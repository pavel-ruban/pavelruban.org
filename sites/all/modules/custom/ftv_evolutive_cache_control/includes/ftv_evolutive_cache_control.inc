<?php

/**
 * @file 
 * ftv_evolutive_cache_control include file
 */

/**
 * Create cache control object
 * @param type $vars preprocess_page variables
 * @return stdClass cache 
 */
function _ftv_evolutive_cache_control_get_cache($vars) {
  $cache = new stdClass;

  $cache->nid = '0';
  $cache->second = FTV_TIMESTAMP_MINUTE;
  $cache->time = time();
  $cache->node_type = '';
  $cache->url = $_GET['q'];
  $cache->task = '';

  if (isset($vars['node'])) {
    $cache->nid = $vars['node']->nid;
    $cache->second = $cache->time - $vars['node']->changed;
    $cache->node_type = $vars['node']->type;
  }
  elseif (isset($vars['task'])) {
    $cache->task = $vars['task'];
  }

  _ftv_evolutive_cache_control_get_ttl_level($cache);
  _ftv_evolutive_cache_control_get_expires($cache);

  return $cache;
}

/**
 * Get TTL Level
 * 
 * @param type $second_since_last_change Timestamp since last change
 * @return int TTL Level (Timestamp)
 */
function _ftv_evolutive_cache_control_get_ttl_level(&$cache) {
  $settings = _ftv_evolutive_cache_control_parse_levels_settings(variable_get('ttls_urls'), TRUE);
  $path = path_load($cache->url);
  if (!empty($settings[$path['alias']])) {
    $cache->ttl_level = $settings[$path['alias']]['ttl'];
    return;
  }
  if (!empty($cache->node_type)) {
    $settings = variable_get('ttls_' . $cache->node_type);
  }
  if (!$settings && !empty($cache->task)) {
    $setting = variable_get('ttls_' . $cache->task);
    if (!empty($setting)) {
      $cache->ttl_level = (int)$setting;
      return;
    }
  }

  if (!$settings)
    $settings = variable_get('ttls_default');

  if (!$settings)
    $cache->ttl_level = FTV_TTL_LEVEL_2;

  $settings = array_reverse(_ftv_evolutive_cache_control_parse_levels_settings($settings));

  foreach ($settings as $setting) {
    if ($cache->second >= $setting['change']) {
      $cache->ttl_level = $setting['ttl'];
      return;
    }
  }

  $cache->ttl_level = FTV_TTL_LEVEL_2;
}

/**
 * Get expires date
 * 
 * @param type $ttl_level
 * @return type 
 */
function _ftv_evolutive_cache_control_get_expires(&$cache) {
  $cache->timestamp = $cache->time + $cache->ttl_level;
  $cache->gmdate = gmdate('D, d M Y H:i:s \G\M\T', $cache->timestamp);
}

/**
 * Get a human render TTL Level
 * @param type $second_since_last_change Timestamp since last change
 * @return int TTL Level (Timestamp)
 */
function _ftv_evolutive_cache_control_get_human_ttl_level($cache) {
  if ($cache->expires < time()) {
    return 'Cache expiré';
  }
  else {
    return 'Expiration du cache de ce contenu : ' . date('D, d M Y H:i:s', $cache->expires);
  }
}

/**
 * Helper function to get a ttl level from DB
 * 
 * @param type $nid
 * @return type 
 */
function _ftv_evolutive_cache_control_get_ttl_db($nid) {
  return db_select('ftv_evolutive_cache_control', 'f')
          ->fields('f', array('ttl_level', 'expires'))
          ->condition('nid', $nid, '=')
          ->execute()
          ->fetch();
}

/**
 * Helper function to set a ttl level in DB
 * 
 * @param type $cache 
 */
function _ftv_evolutive_cache_control_set_ttl_db($cache) {
  $result = _ftv_evolutive_cache_control_get_ttl_db($cache->nid);

  if ($result) {
    db_update('ftv_evolutive_cache_control')
        ->fields(array('ttl_level' => $cache->ttl_level))
        ->fields(array('expires' => $cache->timestamp))
        ->condition('nid', $cache->nid, '=')
        ->execute();
  }
  else {
    db_insert('ftv_evolutive_cache_control')
        ->fields(array('nid' => $cache->nid, 'ttl_level' => $cache->ttl_level, 'expires' => $cache->timestamp))
        ->execute();
  }
}

/**
 * Helper function to parse settings
 * @param type $mapping_raw
 * @return type 
 */
function _ftv_evolutive_cache_control_parse_levels_settings($mapping_raw, $inline = FALSE) {
  $mapping = array();

  if (!empty($mapping_raw)) {
    $lines = preg_split("/[\n\r]+/", $mapping_raw, -1, PREG_SPLIT_NO_EMPTY);
    foreach ($lines as $line) {
      // Parse this line.
      if (strpos($line, '|') !== FALSE) {
        $parts = explode('|', $line);
        if ($inline) {
          $mapping[trim($parts[0])] = array('ttl' => trim($parts[1]));
        }
        else {
          $mapping[] = array('change' => trim($parts[0]), 'ttl' => trim($parts[1]));
        }
      }
    }
  }

  return $mapping;
}
