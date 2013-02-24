<?php
/**
 * @file
 * le_rubrique_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function le_rubrique_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-menu-rubrique:taxonomy/term/2
  $menu_links['menu-menu-rubrique:taxonomy/term/2'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/2',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Politique',
    'options' => array(
      'attributes' => array(
        'title' => 'Politique',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/3
  $menu_links['menu-menu-rubrique:taxonomy/term/3'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Economie',
    'options' => array(
      'attributes' => array(
        'title' => 'Economie',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-49',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/4
  $menu_links['menu-menu-rubrique:taxonomy/term/4'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/4',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Société',
    'options' => array(
      'attributes' => array(
        'title' => 'Société',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/5
  $menu_links['menu-menu-rubrique:taxonomy/term/5'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/5',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Culture',
    'options' => array(
      'attributes' => array(
        'title' => 'Culture',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-47',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/6
  $menu_links['menu-menu-rubrique:taxonomy/term/6'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/6',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Médias',
    'options' => array(
      'attributes' => array(
        'title' => 'Médias',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-46',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/7
  $menu_links['menu-menu-rubrique:taxonomy/term/7'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/7',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Sports',
    'options' => array(
      'attributes' => array(
        'title' => 'Sports',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-45',
  );
  // Exported menu link: menu-menu-rubrique:taxonomy/term/8
  $menu_links['menu-menu-rubrique:taxonomy/term/8'] = array(
    'menu_name' => 'menu-menu-rubrique',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'People',
      ),
    ),
    'module' => 'taxonomy_menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-44',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Culture');
  t('Economie');
  t('Médias');
  t('People');
  t('Politique');
  t('Société');
  t('Sports');


  return $menu_links;
}
