<?php
/**
 * @file
 * Ctools CT plugin for render context_links.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site context_links'),
  'description' => t('context_links'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_context_links_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_context_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme(
    'pavelruban_context_links',
    array(
      'temp' => NULL,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_context_links_theme(&$theme, $plugin) {
  $theme['pavelruban_context_links'] = array(
    'path'      => $plugin['path'],
    'template'  => 'context-links',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_context_links(&$vars) {
  if (preg_match('/^node\/([0-9]+)/', $_GET['q'], $match) && user_access('administer nodes')) {
    $node = node_load($match[1]);
    $vars['edit_link'] = theme('social', array('mode' => 'full', 'part' => 'top', 'nid' => $node->nid, 'changed' => $node->changed));
  }
}
