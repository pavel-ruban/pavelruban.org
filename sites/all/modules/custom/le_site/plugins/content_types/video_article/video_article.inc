<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video Article'),
  'description' => t('Provides Video Article Template'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_video_article_theme',
);

/**
 * Render the custom content type.
 */
function le_site_video_article_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  // Get node.
  if (!empty($panel_args[0]) && ($nid = (int) $panel_args[0]) > 0) {
    $node = node_load($nid);
  }
  // Prevent errors if node is empty.
  if (empty($node) || !is_object($node)) {
    return;
  }
  $block->content = theme(
    'le_video_article',
    array(
      'node' => $node,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_video_article_theme(&$theme, $plugin) {
  $theme['le_video_article'] = array(
    'path' => $plugin['path'],
    'template' => 'video-article',
    'variables' => array('node' => NULL),
  );
}

/**
 * Implements of hook_theme().
 */
function le_site_preprocess_le_video_article(&$vars) {
  $vars['video_article'] = node_view($vars['node'], 'video_article'); 
}
