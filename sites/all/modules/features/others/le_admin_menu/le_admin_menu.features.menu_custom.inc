<?php
/**
 * @file
 * le_admin_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function le_admin_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-le-admin-menu.
  $menus['menu-le-admin-menu'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'title' => 'Le360 Admin Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Le360 Admin Menu');
  t('Management');
  t('The <em>Management</em> menu contains links for administrative tasks.');


  return $menus;
}
