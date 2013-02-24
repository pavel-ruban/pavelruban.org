<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'title' => t('Footer'),
  'description' => t('Footer'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_footer_theme',
);

/**
 * Render the custom content type.
 */
function le_site_footer_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $menu = menu_tree_all_data('menu-footer-menu');
  $footer_menu_links = array();

  if (!empty($menu)) {
    foreach ($menu as $child) {
      $footer_menu_links[] = l(
        $child['link']['link_title'],
        $child['link']['link_path']
      );
    }
  }

  $menu_count = count($footer_menu_links);
  $left = floor($menu_count / 2);

  $left_side = array_slice($footer_menu_links, 0, $left);
  $right_side = array_slice($footer_menu_links, $left);
  $footer_menu_links = array('left' => $left_side, 'right' => $right_side);

  $block->content = theme('le_footer', array('footer_menu' => $footer_menu_links));
  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_footer_theme(&$theme, $plugin) {
  $theme['le_footer'] = array(
    'path'      => $plugin['path'],
    'template'  => 'footer',
    'variables' => array('footer_menu' => NULL),
  );
}
