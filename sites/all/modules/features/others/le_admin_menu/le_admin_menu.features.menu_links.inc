<?php
/**
 * @file
 * le_admin_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function le_admin_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-le-admin-menu:admin/dashboard
  $menu_links['menu-le-admin-menu:admin/dashboard'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Tableau de bord',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/articles
  $menu_links['menu-le-admin-menu:admin/dashboard/articles'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/articles',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Articles',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/blocks
  $menu_links['menu-le-admin-menu:admin/dashboard/blocks'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/blocks',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Blocs',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/dossier
  $menu_links['menu-le-admin-menu:admin/dashboard/dossier'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/dossier',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Dossier',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/flashnews
  $menu_links['menu-le-admin-menu:admin/dashboard/flashnews'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/flashnews',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Flash news',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/multimedia
  $menu_links['menu-le-admin-menu:admin/dashboard/multimedia'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/multimedia',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Médiathèque',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/pages
  $menu_links['menu-le-admin-menu:admin/dashboard/pages'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/pages',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Page statique',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/tags
  $menu_links['menu-le-admin-menu:admin/dashboard/tags'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/tags',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Tags',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-le-admin-menu:admin/dashboard/users
  $menu_links['menu-le-admin-menu:admin/dashboard/users'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/dashboard/users',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Gérer les utilisateurs',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-41',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue',
    'router_path' => 'admin/structure',
    'link_title' => 'La Une',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue/1/view/1
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue/1/view/1'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue/1/view/1',
    'router_path' => 'admin/structure',
    'link_title' => 'La Une',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'admin/structure/nodequeue',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue/2/view/2
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue/2/view/2'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue/2/view/2',
    'router_path' => 'admin/structure',
    'link_title' => 'Revue de presse',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => 'admin/structure/nodequeue',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue/3/view/3
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue/3/view/3'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue/3/view/3',
    'router_path' => 'admin/structure',
    'link_title' => 'La Une Vidéo',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'admin/structure/nodequeue',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue/4/view/4
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue/4/view/4'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue/4/view/4',
    'router_path' => 'admin/structure',
    'link_title' => 'Fleuve d’actualité',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'admin/structure/nodequeue',
  );
  // Exported menu link: menu-le-admin-menu:admin/structure/nodequeue/5/view/5
  $menu_links['menu-le-admin-menu:admin/structure/nodequeue/5/view/5'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'admin/structure/nodequeue/5/view/5',
    'router_path' => 'admin/structure',
    'link_title' => 'Exceptionnel',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'admin/structure/nodequeue',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/1
  $menu_links['menu-le-admin-menu:menu-position/1'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/1',
    'router_path' => 'menu-position/%',
    'link_title' => 'Article add (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/articles',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/10
  $menu_links['menu-le-admin-menu:menu-position/10'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/10',
    'router_path' => 'menu-position/%',
    'link_title' => 'Edit Flash news (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/flashnews',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/13
  $menu_links['menu-le-admin-menu:menu-position/13'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/13',
    'router_path' => 'menu-position/%',
    'link_title' => 'Block actions (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/blocks',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/2
  $menu_links['menu-le-admin-menu:menu-position/2'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/2',
    'router_path' => 'menu-position/%',
    'link_title' => 'Article edit (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/articles',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/3
  $menu_links['menu-le-admin-menu:menu-position/3'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/3',
    'router_path' => 'menu-position/%',
    'link_title' => 'Assets (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/multimedia',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/4
  $menu_links['menu-le-admin-menu:menu-position/4'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/4',
    'router_path' => 'menu-position/%',
    'link_title' => 'Tags tab (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/tags',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/5
  $menu_links['menu-le-admin-menu:menu-position/5'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/5',
    'router_path' => 'menu-position/%',
    'link_title' => 'Page add (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/pages',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/6
  $menu_links['menu-le-admin-menu:menu-position/6'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/6',
    'router_path' => 'menu-position/%',
    'link_title' => 'Page edit (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/pages',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/7
  $menu_links['menu-le-admin-menu:menu-position/7'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/7',
    'router_path' => 'menu-position/%',
    'link_title' => 'Dossier add (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/dossier',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/8
  $menu_links['menu-le-admin-menu:menu-position/8'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/8',
    'router_path' => 'menu-position/%',
    'link_title' => 'Dossier edit (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/dossier',
  );
  // Exported menu link: menu-le-admin-menu:menu-position/9
  $menu_links['menu-le-admin-menu:menu-position/9'] = array(
    'menu_name' => 'menu-le-admin-menu',
    'link_path' => 'menu-position/9',
    'router_path' => 'menu-position/%',
    'link_title' => 'Add Flash news (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/dashboard/flashnews',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Flash news (menu position rule)');
  t('Article add (menu position rule)');
  t('Article edit (menu position rule)');
  t('Articles');
  t('Assets (menu position rule)');
  t('Block actions (menu position rule)');
  t('Blocs');
  t('Dossier');
  t('Dossier add (menu position rule)');
  t('Dossier edit (menu position rule)');
  t('Edit Flash news (menu position rule)');
  t('Exceptionnel');
  t('Flash news');
  t('Fleuve d’actualité');
  t('Gérer les utilisateurs');
  t('La Une');
  t('La Une Vidéo');
  t('Médiathèque');
  t('Page add (menu position rule)');
  t('Page edit (menu position rule)');
  t('Page statique');
  t('Revue de presse');
  t('Tableau de bord');
  t('Tags');
  t('Tags tab (menu position rule)');


  return $menu_links;
}
