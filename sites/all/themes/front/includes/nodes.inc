<?php

/**
 * @file
 *
 * Node preprocesses.
 */

/**
* Preprocess variables.
*/
function front_preprocess_node__article_full(&$vars) {
  if (!empty($vars['content']['field_article_media'])) {
    $vars['media'] = render($vars['content']['field_article_media']);
  }
  if (!empty($vars['content']['field_article_catchline'])) {
    $description = render($vars['content']['field_article_catchline']);
    $vars['description'] = $description;
  }
  if (!empty($vars['content']['field_body'])) {
    $vars['body'] = render($vars['content']['field_body']);
  }

  $tags = field_get_items('node', $vars['node'], 'field_tags');
  if (!empty($tags)) {
    $vars['tags'] = theme('tags', array('tags' => $tags));
  }
}

/**
* Preprocess variables.
*/
function front_preprocess_node__page_full(&$vars) {
  if (!empty($vars['content']['field_page_main_media'])) {
    $vars['media'] = render($vars['content']['field_page_main_media']);
  }

  if (!empty($vars['content']['field_page_catchline'])) {
    $description = render($vars['content']['field_page_catchline']);
    $vars['description'] = $description;
  }

  if (!empty($vars['content']['field_page_body'])) {
    $vars['body'] = render($vars['content']['field_page_body']);
  }

  $tags = field_get_items('node', $vars['node'], 'field_tags');
  if (!empty($tags)) {
    $vars['tags'] = theme('tags', array('tags' => $tags));
  }

  $status = drupal_get_http_header("status");
  if($status == '404 Not Found' || variable_get('site_404') == $_GET['q']){
    $vars['is_404'] = TRUE;
  }
  elseif ($status == '403 Forbidden' || variable_get('site_403') == $_GET['q']) {
    $vars['is_403'] = TRUE;
  }
}


/**
 * Override or insert variables into the node template.
 */
function front_preprocess_node(&$vars, $hook) {
  if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
    $vars['classes_array'][] = 'node-full';
  }

  $node = $vars['node'];
  $build_mode_for_preprocess = str_replace('-', '_', $vars['view_mode']);

  $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . $vars['view_mode'];

  // Defines the priority of calling preprocess fuctions for specific nodetype & build
  // modes.
  // Note: priority is calculated in reverse mode.
  $preprocess = array(
    'front_preprocess_node__' . $node->type,
    'front_preprocess_node__' . $build_mode_for_preprocess,
    'front_preprocess_node__' . $node->type . '_' . $build_mode_for_preprocess,
  );

  foreach (array_reverse($preprocess) as $function) {
    if (function_exists($function)) {
      $function($vars, $hook);
      break;
    }
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_node__article_teaser(&$vars) {
  if (!empty($vars['content']['field_article_media'])) {
    $vars['content']['field_article_media']['#disable_shadowbox'] = TRUE;
    $vars['media'] = render($vars['content']['field_article_media']);
  }
  if (!empty($vars['content']['field_article_catchline'])) {
    $description = render($vars['content']['field_article_catchline']);
    $vars['description'] = $description;
  }

  $result = db_select('node_statistic')
    ->fields('node_statistic', array('access_count'))
    ->condition('nid', $vars['nid'])
    ->execute()
    ->fetchCol();
  $acess_count = !empty($result[0]) ? $result[0] : 0;

  $vars['tags'] = theme('tags', array('nid' => $vars['nid']));

  $vars['social'] = theme('social',
    array(
      'nid' => $vars['nid'],
      'comment_count' => $vars['comment_count'],
      'changed' => $vars['changed'],
      'share_title' => $vars['title'],
      'share_description' => $description,
      'access_count' => $acess_count,
    )
  );
}