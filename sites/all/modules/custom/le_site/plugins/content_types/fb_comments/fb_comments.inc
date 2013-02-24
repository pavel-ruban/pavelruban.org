<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Facebook comments'),
  'description' => t('Facebook comments'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_fb_comments_theme',
);

/**
 * Render the custom content type.
 */
function le_site_fb_comments_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $url = url($_GET['q'], array('absolute' => TRUE));
  $block->content = theme('le_fb_comments', array('url' => $url));

  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_fb_comments_theme(&$theme, $plugin) {
  $theme['le_fb_comments'] = array(
    'path'      => $plugin['path'],
    'template'  => 'fb-comments',
    'variables' => array('url' => NULL),
  );
}
