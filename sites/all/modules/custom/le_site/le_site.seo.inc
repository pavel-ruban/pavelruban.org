<?php

/**
 * @file
 * Provides functions for SEO.
 */

/**
 * Mask external url for SEO optimization.
 */
function le_site_mask_url($url) {
  // First reverse the string.
  $url = strrev($url);
  return '#' . strtr($url, __GEOPOLIS_SITE_MASK_URL_INPUT, __GEOPOLIS_SITE_MASK_URL_OUTPUT);
}

/**
 * Check url for external property.
 */
function le_site_url_is_external($path) {
  global $base_url;
  $url_host = parse_url($path);

  if (empty($url_host['host']) && empty($url_host['scheme'])) {
    return FALSE;
  }
  else {
    if ($url_host['scheme'] . '://' . $url_host['host'] == substr($base_url, 0, strlen($url_host['scheme'] . '://' . $url_host['host']))) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Fork drupal l().
 */
function le_site_l($text, $path, $options = array()) {
  global $language;

  // Merge in defaults.
  $options += array(
    'attributes' => array(),
    'html' => FALSE,
  );

  // Append active class.
  if (($path == $_GET['q'] || ($path == '<front>' && drupal_is_front_page())) &&
    (empty($options['language']) || $options['language']->language == $language->language)) {
    if (empty($options['attributes']['class'])) {
      $options['attributes']['class'] = 'active';
    }
    elseif (is_array($options['attributes']['class'])) {
      $options['attributes']['class'][] = ' active';
    }
    else {
      $options['attributes']['class'] .= ' active';
    }
  }

  // Remove all HTML and PHP tags from a tooltip. For best performance, we act only
  // if a quick strpos() pre-check gave a suspicion (because strip_tags() is expensive).
  if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
    $options['attributes']['title'] = strip_tags($options['attributes']['title']);
  }

  $manual_hide = FALSE;
  $origin_link = FALSE;
  if (!empty($options['attributes']['class'])) {
    if (is_string($options['attributes']['class'])) {
      if (strpos($options['attributes']['class'], 'imitation-links') !== FALSE) {
        $manual_hide = TRUE;
      }
      elseif (strpos($options['attributes']['class'], 'origin-link') !== FALSE) {
        $origin_link = TRUE;
      }
    }
    elseif (is_array($options['attributes']['class'])) {
      foreach ($options['attributes']['class'] as $pattern) {
        if (is_string($pattern)) {
          if (strpos($pattern, 'imitation-links') !== FALSE) {
            $manual_hide = TRUE;
            break;
          }
          elseif (strpos($pattern, 'origin-link') !== FALSE) {
            $origin_link = TRUE;
            break;
          }
        }
      }
    }
  }

  // If hidden link.
  if (variable_get('geopolis_seo_link', TRUE)
    && (le_site_url_is_external($path) || $manual_hide) && !$origin_link) {

    $options['attributes']['unteflutche'] = TRUE;

    if (!$manual_hide) {
      if (empty($options['attributes']['class'])) {
        $options['attributes']['class'] = 'imitation-links';
      }
      elseif (is_array($options['attributes']['class'])) {
        $options['attributes']['class'][] = 'imitation-links';
      }
      else {
        $options['attributes']['class'] .= ' imitation-links';
      }
    }

    // Open all external links in new tab.
    if (!empty($options['attributes']) && empty($options['attributes']['target'])
      && geopolis_site_url_is_external($path)) {
      $options['attributes']['target'] = '_blank';
    }
    elseif (empty($options['attributes']) && geopolis_site_url_is_external($path)) {
      $options['attributes'] = array();
      $options['attributes']['target'] = '_blank';
    }

    $url = url($path, $options);
    $onclick = TRUE;

    if (isset($options['attributes']['unteflutche'])) {
      if (is_array($options['attributes']['class'])) {
        foreach ($options['attributes']['class'] as $class) {
          if (is_string($class)) {
            if (strpos($class, 'showPopup') !== FALSE) {
              $options['attributes']['data-popup-href'] = $url;
              $onclick = FALSE;
              break;
            }
            elseif (strpos($class, 'janrain-seo') !== FALSE) {
              $options['attributes']['data-janrain-href'] = $url;
              $onclick = FALSE;
              break;
            }
            elseif (strpos($class, 'geopolis-eval-seo') !== FALSE) {
              $options['attributes']['data-eval-code'] = geopolis_site_mask_url($path);
              $onclick = FALSE;
              break;
            }
          }
        }
      }
      elseif (is_string($options['attributes']['class'])) {
        if (strpos($options['attributes']['class'], 'showPopup') !== FALSE) {
          $options['attributes']['data-popup-href'] = $url;
          $onclick = FALSE;
        }
        elseif (strpos($options['attributes']['class'], 'janrain-seo') !== FALSE) {
          $options['attributes']['data-janrain-href'] = $url;
          $onclick = FALSE;
        }
        elseif (strpos($options['attributes']['class'], 'geopolis-eval-seo') !== FALSE) {
          $options['attributes']['data-eval-code'] = geopolis_site_mask_url($path);
          $onclick = FALSE;
        }
      }
      unset($options['attributes']['unteflutche']);
    }

    if (!empty($options['attributes']['target'])
      && $options['attributes']['target'] == '_blank') {
      $onclick = $onclick ? " onclick='GeopolisSite.unteflutchenew(\"" . check_url($url) . "/\"); return false;' " : '';
      return "<span " . drupal_attributes($options['attributes']) . $onclick . " >" . ($options['html'] ? $text : check_plain($text)) . '</span>';
    }
    else {
      $onclick = $onclick ? " onclick='GeopolisSite.unteflutche(\"" . check_url($url) . "/\"); return false;' " : '';
      return "<span " . drupal_attributes($options['attributes']) . $onclick . " >" . ($options['html'] ? $text : check_plain($text)) . '</span>';
    }
  }
  return '<a href="' . check_url(url($path, $options)) . '"' . drupal_attributes($options['attributes']) . '>' . ($options['html'] ? $text : check_plain($text)) . '</a>';
}

/**
 * Replace external <a> to encoded <span> by preg_replace_callback().
 */
function le_site_replace_external_links($matches) {
  preg_match_all('/(\b.+?)\="(.+?)"/', $matches[1], $unformatted_attributes);
  $attributes = array();

  foreach ($unformatted_attributes[1] as $key => $item) {
    $attributes[$item] = $unformatted_attributes[2][$key];
  }

  if (!empty($attributes['href']) && Geopolis_site_url_is_external($attributes['href'])) {
    $url = Geopolis_site_mask_url(check_url($attributes['href']));
    if (empty($attributes['class'])) {
      $attributes['class'] = 'imitation-links';
    }
    else {
      $attributes['class'] .= ' imitation-links';
    }

    // Open all external links in new tab.
    if (empty($attributes['target'])) {
      $attributes['target'] = '_blank';
    }
    unset($attributes['href']);
    if (!empty($attributes['target']) && $attributes['target'] == '_blank') {
      unset($attributes['target']);
      $temp = $attributes;
      $attributes = array();
      foreach ($temp as $name => $attr) {
        $attributes[] = $name . '="' . $attr . '"';
      }
      return "<span " . implode(' ', $attributes) . " onclick='GeopolisSite.unteflutchenew(\"" . $url . "/\"); return false;' >" . $matches[2] . '</span>';
    }
    else {
      $temp = $attributes;
      $attributes = array();
      foreach ($temp as $name => $attr) {
        $attributes[] = $name . '="' . $attr . '"';
      }
      return "<span " . implode(' ', $attributes) . " onclick='GeopolisSite.unteflutche(\"" . $url . "/\"); return false;' >" . $matches[2] . '</span>';
    }
  }
  return $matches[0];
}

/**
 * Proccess callback for input format filter replace_external_link.
 */
function le_site_replace_external_link_filter($text) {
  $text = preg_replace_callback('/<a(.+?)>(.*?)<\/a>/s', 'geopolis_site_replace_external_links', $text);

  return $text;
}

/**
 * Render google news xml file.
 */
function le_site_render_google_news() {
  $files_directory = variable_get('file_public_path', conf_path() . '/files');
  $timestamp = variable_get('le_google_news_generate_timestamp', 0);

  $filepath = DRUPAL_ROOT . '/' . $files_directory . '/gn.xml';

  // Generate google news xml.
  if (!file_exists($filepath) || (REQUEST_TIME - $timestamp) >= GEOPOLIS_NEWS_GENERATE_INTEVAL) {
    geopolis_site_get_google_news();
    variable_set('le_google_news_generate_timestamp', REQUEST_TIME);
  }
  // Render google news xml.
  if (file_exists($filepath)) {
    drupal_add_http_header('Content-Type', 'text/xml; charset=utf-8');
    print file_get_contents($filepath);
    exit();
  }
}

/**
 * Generate the news feed.
 */
function le_site_get_google_news() {
  global $language_content;

  $content_prefix = '<?xml version="1.0" encoding="UTF-8"?>';
  $content_prefix .= '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9"';
  $content_prefix .= '  xmlns:news="http://www.google.com/schemas/sitemap-news/0.9"';
  $content_prefix .= '  xmlns:video="http://www.google.com/schemas/sitemap-video/1.1">';

  $query = db_query('SELECT n.nid AS nid, n.created AS created, n.title AS title, fam.field_article_main_media_target_id AS media_id, a.title AS a_title, a.created AS a_created, fav.field_asset_video_url AS video_url, fad.field_asset_description_value AS description_value, m.data AS data
    FROM {node} n
    LEFT JOIN {field_data_field_article_main_media} fam ON n.vid = fam.revision_id
    LEFT JOIN {asset} a ON a.aid = fam.field_article_main_media_target_id
    LEFT JOIN {field_data_field_asset_video} fav ON a.aid = fav.entity_id
    LEFT JOIN {field_data_field_asset_description} fad ON a.aid = fad.entity_id
    LEFT JOIN {metatag} m ON n.nid = m.entity_id AND m.entity_type = :etype
    WHERE n.type = :ntype AND n.status = 1 AND n.created >= :time
    ORDER BY n.created DESC LIMIT 1000 OFFSET 0',
    array(':etype' => 'node', ':ntype' => 'article', ':time' => REQUEST_TIME - 172800)
  );

  $content = '';
  while ($node = $query->fetchAssoc()) {
    $content .= '<url>';
    $content .= '<loc>' . url('node/' . $node['nid'], array('absolute' => TRUE)) . '</loc>';
    $content .= '<news:news>';
    $content .= '<news:publication>';
    $content .= '<news:name>' . variable_get('site_name', 'Drupal') . '</news:name>';
    $content .= '<news:language>' . check_plain($language_content->language) . '</news:language>';
    $content .= '</news:publication>';
    $content .= '<news:genres>PressRelease, Blog</news:genres>';
    $content .= '<news:publication_date>' . gmdate(DATE_W3C, $node['created']) . '</news:publication_date>';
    $content .= '<news:title>' . check_plain($node['title']) . '</news:title>';
    // Add keywords.
    if (!empty($node['data'])) {
      $meta = unserialize($node['data']);
      if (!empty($meta['keywords']['value'])) {
        if (strpos($meta['keywords']['value'], ',')) {
          $keywords = $meta['keywords']['value'];
        }
        else {
          $keywords = str_replace(' ', ', ', $meta['keywords']['value']);
        }
        $content .= '<news:keywords>' . $keywords . '</news:keywords>';
      }
    }
    // Add video.
    if ($node['video_url']) {
      $video_url = geopolis_site_get_url_by_emcode($node['video_url']);
      if ($video_url) {
        $preview = geopolis_site_emvideo_parse($node['video_url']);
        $content .= '<video:video>';
        $content .= '<video:thumbnail_loc>' . check_url($preview['snapshot']) . '</video:thumbnail_loc>';
        $content .= '<video:title>' . check_plain($node['a_title']) . '</video:title>';
        $description = (!empty($node['description_value'])) ? $node['description_value'] : $node['a_title'];
        $content .= '<video:description>' . truncate_utf8(strip_tags(check_plain($description)), 2000, TRUE, TRUE) . '</video:description>';
        $content .= '<video:player_loc>' . check_url($video_url) . '</video:player_loc>';
        $content .= '</video:video>';
      }
    }
    $content .= '</news:news>';
    $content .= '</url>';
  }

  if (!empty($content)) {
    $content = $content_prefix . $content;
    $content .= '</urlset>';
  }

  $files_directory = variable_get('file_public_path', conf_path() . '/files');
  file_put_contents(DRUPAL_ROOT . '/' . $files_directory . '/gn.xml', $content);
}

/**
 * Fork function pathauto_cleanstring().
 */
function geopolis_site_pathauto_cleanstring($string) {

  $string = str_replace(explode(',', GEOPOLIS_SITE_STOP_WORDS), ' ', $string);

  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['cache'] = &drupal_static(__FUNCTION__);
  }
  $cache = &$drupal_static_fast['cache'];

  // Generate and cache variables used in this function so that on the second
  // call to pathauto_cleanstring() we focus on processing.
  module_load_include('inc', 'pathauto', 'pathauto');
  if (!isset($cache)) {
    $cache = array(
      'separator' => ' ',
      'strings' => array(),
      'transliterate' => variable_get('pathauto_transliterate', FALSE) && module_exists('transliteration'),
      'punctuation' => array(),
      'reduce_ascii' => (bool) variable_get('pathauto_reduce_ascii', FALSE),
      'ignore_words_regex' => FALSE,
      'lowercase' => (bool) variable_get('pathauto_case', PATHAUTO_CASE_LOWER),
    );

    // Generate and cache the punctuation replacements for strtr().
    $punctuation = pathauto_punctuation_chars();
    unset($punctuation['hyphen']);
    foreach ($punctuation as $name => $details) {
      $action = variable_get('pathauto_punctuation_' . $name, PATHAUTO_PUNCTUATION_REMOVE);
      switch ($action) {
        case PATHAUTO_PUNCTUATION_REMOVE:
          $cache['punctuation'][$details['value']] = '';
          break;

        case PATHAUTO_PUNCTUATION_REPLACE:
          $cache['punctuation'][$details['value']] = $cache['separator'];
          break;

        case PATHAUTO_PUNCTUATION_DO_NOTHING:
          // Literally do nothing.
          break;

      }
    }

    // Generate and cache the ignored words regular expression.
    $ignore_words = variable_get('pathauto_ignore_words', PATHAUTO_IGNORE_WORDS);
    $ignore_words_regex = preg_replace(array('/^[,\s]+|[,\s]+$/', '/[,\s]+/'), array('', '\b|\b'), $ignore_words);
    if ($ignore_words_regex) {
      $cache['ignore_words_regex'] = '\b' . $ignore_words_regex . '\b';
      if (function_exists('mb_eregi_replace')) {
        $cache['ignore_words_callback'] = 'mb_eregi_replace';
      }
      else {
        $cache['ignore_words_callback'] = 'preg_replace';
        $cache['ignore_words_regex'] = '/' . $cache['ignore_words_regex'] . '/i';
      }
    }
  }

  // Empty strings do not need any proccessing.
  if ($string === '' || $string === NULL) {
    return '';
  }

  // Remove all HTML tags from the string.
  $output = strip_tags(decode_entities($string));

  // Optionally transliterate (by running through the Transliteration module)
  if ($cache['transliterate']) {
    $output = transliteration_get($output);
  }

  // Replace or drop punctuation based on user settings
  $output = strtr($string, $cache['punctuation']);

  // Reduce strings to letters and numbers
  if ($cache['reduce_ascii']) {
    $output = preg_replace('/[^a-zA-Z0-9_-]+/', $cache['separator'], $output);
  }

  // Get rid of words that are on the ignore list
  if ($cache['ignore_words_regex']) {
    $words_removed = $cache['ignore_words_callback']($cache['ignore_words_regex'], '', $output);
    if (drupal_strlen(trim($words_removed)) > 0) {
      $output = $words_removed;
    }
  }

  // Always replace whitespace with the separator.
  $output = preg_replace('/\s+/', $cache['separator'], $output);

  // Trim duplicates and remove trailing and leading separators.
  $output = _pathauto_clean_separators($output, $cache['separator']);

  $words = explode(' ', $output);
  $output = implode(' ', array_splice($words, 0, 16));

  return "$output";
}

/**
 * Fork function pathauto_cleanstring().
 */
function geopolis_site_file_pathauto_cleanstring($string) {

  $string = preg_replace_callback("/(?<=[^\'a-zA-Z])[a-zA-Z.\']+(?=[^\'a-zA-Z])/", 'geopolis_site_process_file_name', $string);

  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['cache'] = &drupal_static(__FUNCTION__);
  }
  $cache = &$drupal_static_fast['cache'];

  // Generate and cache variables used in this function so that on the second
  // call to pathauto_cleanstring() we focus on processing.
  module_load_include('inc', 'pathauto', 'pathauto');
  if (!isset($cache)) {
    $cache = array(
      'separator' => '_',
      'strings' => array(),
      'transliterate' => variable_get('pathauto_transliterate', FALSE) && module_exists('transliteration'),
      'punctuation' => array(),
      'reduce_ascii' => (bool) variable_get('pathauto_reduce_ascii', FALSE),
      'ignore_words_regex' => FALSE,
      'lowercase' => (bool) variable_get('pathauto_case', PATHAUTO_CASE_LOWER),
    );

    // Generate and cache the punctuation replacements for strtr().
    $punctuation = pathauto_punctuation_chars();
    unset($punctuation['underscore']);
    unset($punctuation['period']);
    unset($punctuation['hyphen']);
    foreach ($punctuation as $name => $details) {
      $action = variable_get('pathauto_punctuation_' . $name, PATHAUTO_PUNCTUATION_REMOVE);
      switch ($action) {
        case PATHAUTO_PUNCTUATION_REMOVE:
          $cache['punctuation'][$details['value']] = '';
          break;
        case PATHAUTO_PUNCTUATION_REPLACE:
          $cache['punctuation'][$details['value']] = $cache['separator'];
          break;
        case PATHAUTO_PUNCTUATION_DO_NOTHING:
          // Literally do nothing.
          break;
      }
    }

    // Generate and cache the ignored words regular expression.
    $ignore_words = variable_get('pathauto_ignore_words', PATHAUTO_IGNORE_WORDS);
    $ignore_words_regex = preg_replace(array('/^[,\s]+|[,\s]+$/', '/[,\s]+/'), array('', '\b|\b'), $ignore_words);
    if ($ignore_words_regex) {
      $cache['ignore_words_regex'] = '\b' . $ignore_words_regex . '\b';
      if (function_exists('mb_eregi_replace')) {
        $cache['ignore_words_callback'] = 'mb_eregi_replace';
      }
      else {
        $cache['ignore_words_callback'] = 'preg_replace';
        $cache['ignore_words_regex'] = '/' . $cache['ignore_words_regex'] . '/i';
      }
    }
  }

  // Empty strings do not need any proccessing.
  if ($string === '' || $string === NULL) {
    return '';
  }

  // Remove all HTML tags from the string.
  $output = strip_tags(decode_entities($string));

  // Optionally transliterate (by running through the Transliteration module)
  if ($cache['transliterate']) {
    $output = transliteration_get($output);
  }

  // Replace or drop punctuation based on user settings
  $output = strtr($string, $cache['punctuation']);

  // Reduce strings to letters and numbers
  if ($cache['reduce_ascii']) {
    $output = preg_replace('/[^a-zA-Z0-9_\-.]+/', $cache['separator'], $output);
  }

  // Get rid of words that are on the ignore list
  if ($cache['ignore_words_regex']) {
    $words_removed = $cache['ignore_words_callback']($cache['ignore_words_regex'], '', $output);
    if (drupal_strlen(trim($words_removed)) > 0) {
      $output = $words_removed;
    }
  }

  // Always replace whitespace with the separator.
  $output = preg_replace('/\s+/', $cache['separator'], $output);

  // Trim duplicates and remove trailing and leading separators.
  $output = _pathauto_clean_separators($output, $cache['separator']);

  $words = explode('_', $output);
  $output = implode('_', array_splice($words, 0, 16));

  return "$output";
}

/**
 * Remove strop words from file name.
 */
function geopolis_site_process_file_name($matches) {
  if (in_array(" $matches[0] ", explode(',', GEOPOLIS_SITE_STOP_WORDS))) {
    return '';
  }
  else {
    return $matches[0];
  }
}
