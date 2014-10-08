<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site header'),
  'description' => t('Header'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_header_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_header_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->content = theme(
    'pavelruban_header',
    array(
      'temp' => NULL,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_header_theme(&$theme, $plugin) {
  $theme['pavelruban_header'] = array(
    'path' => $plugin['path'],
    'template' => 'header',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_header(&$vars) {
  global $user;

  // Left Sidebar.
  $vars['home_img_link'] = l(
    '',
    '<front>',
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('home-logo-img'),
        'title' => t('На главную'),
      ),
    )
  );

  $vars['git_img_link'] = l(
    '',
    'https://github.com/pavelruban-org',
    array(
      'absolute' => TRUE,
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target' => array('blank'),
        'class' => array('git-logo-img'),
        'title' => t('Проекты разрабатываемые мною на github.com'),
      ),
    )
  );

  if (user_access('View the administrative dashboard')) {
    $admin_margin = TRUE;

    $vars['admin_img_link'] = l(
      '',
      'admin/dashboard/articles',
      array(
        'html' => TRUE,
        'attributes' => array(
          'title' => t('Настройки'),
          'class' => array('admin-logo-img'),
        ),
      )
    );
  }

  // Show last comments link if any.
  if ($count = count(pavelruban_get_last_comments())) {
    $class = $count > 9 ? 'dozens' : 'small';
    $vars['last_comments'] = l(
      $count,
      'last-comments',
      array(
        'attributes' => array(
          'title' => t('Recent comments'),
          'class' => empty($admin_margin) ? array($class) : array($class, 'admin-margin'),
        ),
      )
    );
  }

  // Top right login menu.

  switch ($user->uid) {
    case '0':
      $l = l(
        "login",
        "user/login"
      );

      $r = l(
        "register",
        "user/register"
      );

      $vars['user_link'] = sprintf('%s/%s', $l, $r);
      break;

    default:
      $vars['user_link'] = l(
        $user->name,
        "user/$user->uid"
      );
  }

  $vars['aboutme_link'] = l(
    "about me",
    variable_get('about_me_page_uri', 'node/37')
  );

  if (!empty($user->uid)) {
    $vars['user_logout'] = l(
      "logout",
      "user/logout"
    );
  }
}
