<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site sidebar'),
  'description' => t('Sidebar'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_sidebar_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_sidebar_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->content = theme(
    'pavelruban_sidebar',
    array(
      'temp' => NULL,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_sidebar_theme(&$theme, $plugin) {
  $theme['pavelruban_sidebar'] = array(
    'path'      => $plugin['path'],
    'template'  => 'sidebar',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_sidebar(&$vars) {
  $result = views_get_view_result('articles', 'home');
  if (!empty($result)) {
    foreach ($result as $node) {
      $nids[] = $node->nid; 
    }
    $nodes = node_load_multiple($nids);
    $rows = array();
    foreach ($result as $row) {
      $rows[] = l(
        $nodes[$row->nid]->title,
        "node/{$row->nid}"
      );
    }
    $vars['rows'] = $rows;
  }
}
