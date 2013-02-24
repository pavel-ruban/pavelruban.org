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
  $vars['image'] = theme('image', array('path' => 'sites/all/themes/front/images/logo.png'));
}
