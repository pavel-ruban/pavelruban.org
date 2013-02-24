<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Footer menu'),
  'description' => t('Footer menu'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_footer_menu_theme',
);

/**
 * Render the custom content type.
 */
function le_site_footer_menu_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();

  $menu = menu_load_links('menu-footer-menu');
  $links = array();
  foreach ($menu as $link) {
    $links[] = l($link['link_title'], $link['link_path']);
  }

  $block->content = theme('le_header', array('links' => $links));
  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_footer_menu_theme(&$theme, $plugin) {
  $theme['le_footer_menu'] = array(
    'path'      => $plugin['path'],
    'template'  => 'footer-menu',
    'variables' => array('links' => NULL),
  );
}
