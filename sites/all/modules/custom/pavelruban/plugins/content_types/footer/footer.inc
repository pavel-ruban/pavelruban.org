<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Site footer'),
  'description' => t('Footer'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_footer_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_footer_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->content = theme(
    'pavelruban_footer',
    array(
      'temp' => NULL,
    )
  );

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_footer_theme(&$theme, $plugin) {
  $theme['pavelruban_footer'] = array(
    'path'      => $plugin['path'],
    'template'  => 'footer',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_footer(&$vars) {
  $vars['image'] = theme('image', array('path' => 'sites/all/themes/front/images/logo.png'));
}
