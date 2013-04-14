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
    'path'      => $plugin['path'],
    'template'  => 'header',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_header(&$vars) {
  global $user;
  $vars['image'] = theme('image',
    array('path' => 'sites/all/themes/front/images/logo.png')
  );

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
  if (!empty($user->uid)) {
    $vars['user_logout'] = l(
      "logout",
      "user/logout"
    );
  }
}
