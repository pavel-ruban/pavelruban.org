<?php
/**
 * @file
 * le_rubrique_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function le_rubrique_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menu-rubrique.
  $menus['menu-menu-rubrique'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'title' => 'menu_rubrique',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('menu_rubrique');


  return $menus;
}
