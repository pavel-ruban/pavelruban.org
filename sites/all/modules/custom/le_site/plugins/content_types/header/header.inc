<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site header'),
  'description' => t('Header'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_header_theme',
);

/**
 * Render the custom content type.
 */
function le_site_header_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();

  // Rubrique links.
  $menu = menu_load_links('menu-menu-rubrique');
  $rubrique_links = array();
  foreach ($menu as $link) {
    $rubrique_links[] = l(
      $link['link_title'],
      $link['link_path'],
      array(
        'attributes' => array(
          'class' => array(le_site_get_classes_by_rubrique($link['link_title'])),
        ),
      )
    );
  }

  // Additional links.
//  $menu = menu_load_links('menu-additional-header-menu');
//  $additional_links = array();
//  foreach ($menu as $link) {
//    $data = le_site_get_data_for_additional_header_links($link['link_title']);
//    $additional_links[] = l(
//      $data['title'],
//      $link['link_path'],
//      array(
//        'attributes' => array(
//          'class' => array($data['class']),
//        ),
//      )
//    );
//  }

  $block->content = theme(
    'le_header',
    array(
      'rubrique_links' => $rubrique_links,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_header_theme(&$theme, $plugin) {
  $theme['le_header'] = array(
    'path'      => $plugin['path'],
    'template'  => 'header',
    'variables' => array('rubrique_links' => NULL),
  );
}
