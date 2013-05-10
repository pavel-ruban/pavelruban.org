<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site home'),
  'description' => t('Home content'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_home_content_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_home_content_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $content = views_embed_view('articles', 'home');
  $block->content = theme(
    'pavelruban_home_content',
    array(
      'views' => $content,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_home_content_theme(&$theme, $plugin) {
  $theme['pavelruban_home_content'] = array(
    'path'      => $plugin['path'],
    'template'  => 'home-content',
    'variables' => array('views' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_home_content(&$vars) {
  $vars['image'] = theme('image', array('path' => 'sites/all/themes/front/images/logo.png'));
}
