<?php

/**
 * @file
 * This file provides tricks for work with nodequeue.
 */

/**
 * Fork function nodequeue_autocomplete().
 */
function le_site_nodequeue_autocomplete() {
  $args = func_get_args();
  $sqid = array_shift($args);
  $string = implode('/', $args);
  $matches = le_site_process_nodequeue_autocomplete($sqid, $string);
  drupal_json_output(drupal_map_assoc($matches));
}

/**
 * Fork function _nodequeue_autocomplete().
 */
function le_site_process_nodequeue_autocomplete($sqid, $string) {
  $output = array();

  if (!is_numeric($sqid) || !$string) {
    return $output;
  }

  $subqueue = nodequeue_load_subqueue($sqid);
  if (!$subqueue) {
    return $output;
  }

  $queue = nodequeue_load($subqueue->qid);
  if (!$queue) {
    return $output;
  }

  $nodes = le_site_nodequeue_api_autocomplete($queue, $subqueue, $string);
  return $nodes;
}

/**
 * Fork function nodequeue_api_autocomplete().
 */
function le_site_nodequeue_api_autocomplete($queue, $subqueue, $string) {
  $matches = array();
  if (empty($string)) {
    return $matches;
  }

  $query = db_select('node', 'n');

  $query->addJoin('left', 'nodequeue_nodes', 'nn', 'nn.nid = n.nid');

  // Allow add into nodequeue "La Une Vidéo" only nodes with video.
  if ($queue->name === 'choosen_video') {
    $query->addJoin('inner', 'field_data_field_article_main_media', 'fmm', "fmm.entity_id = n.nid AND fmm.entity_type = 'node'");
    $query->addJoin('inner', 'asset', 'asset', "asset.aid = fmm.field_article_main_media_target_id AND asset.type = 'video'");
  }

  $query
    ->addTag('node_access')
    ->fields('n', array('nid', 'tnid', 'title'))
    ->range(0, variable_get('nodequeue_autocomplete_limit', 10));

  if (!empty($queue->types)) {
    $query->condition('n.type', $queue->types, 'IN');
  }

  $query->isNull('nn.qid');

  $where_args = array();
  global $user;
  if (!user_access('administer nodes', $user)) {
    $query->condition(db_or()->condition('n.status', 1)->condition('n.uid', $user->uid));
  }

  // Run a match to see if they're specifying by nid.
  $preg_matches = array();
  $match = preg_match('/\[nid: (\d+)\]/', $string, $preg_matches);
  if (!$match) {
    $match = preg_match('/^nid: (\d+)/', $string, $preg_matches);
  }

  if ($match) {
    // If it found a nid via specification, reduce our resultset to just that nid.
    $query->condition('n.nid', $preg_matches[1]);
  }
  else {
    // Build the constant parts of the query.
    $query->where('LOWER(n.title) LIKE LOWER(:string)', array(':string' => '%' . db_like($string) . '%'));
  }

  // Call to the API.
  $function = $queue->owner . "_nodequeue_autocomplete";
  if (function_exists($function)) {
    return $function($queue, $subqueue, $string, $where, $where_args);
  }
  else {
    $query->addTag('i18n_select');
    $result = $query->execute();

    foreach ($result as $node) {
      $id = nodequeue_get_content_id($queue, $node);
      $matches[$node->nid] = check_plain($node->title) . " [nid: $id]";
    }
  }

  return $matches;
}
