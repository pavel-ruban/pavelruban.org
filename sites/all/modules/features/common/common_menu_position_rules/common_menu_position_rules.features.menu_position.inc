<?php
/**
 * @file
 * common_menu_position_rules.features.menu_position.inc
 */

/**
 * Implements hook_menu_position_default_rules().
 */
function common_menu_position_rules_menu_position_default_rules() {
$menu_positions = array();
  $menu_positions['menu_position_rule:1'] = array(
  'rid' => '1',
  'admin_title' => 'Article add',
  'enabled' => '1',
  'conditions' => array(
    'pages' => array(
      'pages' => 'node/add/article',
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/articles',
);
  $menu_positions['menu_position_rule:2'] = array(
  'rid' => '2',
  'admin_title' => 'Article edit',
  'enabled' => '1',
  'conditions' => array(
    'content_type' => array(
      'content_type' => array(
        'article' => 'article',
      ),
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/articles',
);
  $menu_positions['menu_position_rule:3'] = array(
  'rid' => '3',
  'admin_title' => 'Assets',
  'enabled' => '1',
  'conditions' => array(
    'pages' => array(
      'pages' => 'admin/content/assets/add
admin/content/assets/add/*
admin/content/assets/manage/*',
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/multimedia',
);
  $menu_positions['menu_position_rule:4'] = array(
  'rid' => '4',
  'admin_title' => 'Tags tab',
  'enabled' => '1',
  'conditions' => array(
    'pages' => array(
      'pages' => 'admin/structure/taxonomy/*/add
taxonomy/term/*/edit
admin/taxonomy/term/*/delete',
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/tags',
);
  $menu_positions['menu_position_rule:5'] = array(
  'rid' => '5',
  'admin_title' => 'Page add',
  'enabled' => '1',
  'conditions' => array(
    'pages' => array(
      'pages' => 'node/add/page',
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/pages',
);
  $menu_positions['menu_position_rule:6'] = array(
  'rid' => '6',
  'admin_title' => 'Page edit',
  'enabled' => '1',
  'conditions' => array(
    'content_type' => array(
      'content_type' => array(
        'page' => 'page',
      ),
    ),
  ),
  'menu_name' => 'menu-le-admin-menu',
  'weight' => '0',
  'plink_path' => 'admin/dashboard/pages',
);
return $menu_positions;
}
