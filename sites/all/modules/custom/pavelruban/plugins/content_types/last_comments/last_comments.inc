<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Last Comments'),
  'description' => t('View recently comments list'),
  'category' => t('Pavel Ruban'),
  'hook theme' => 'pavelruban_last_comments_theme',
);

/**
 * Render the custom content type.
 */
function pavelruban_last_comments_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('pavelruban_last_comments');

  return $block;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_last_comments_theme(&$theme, $plugin) {
  $theme['pavelruban_last_comments'] = array(
    'path'      => $plugin['path'],
    'template'  => 'last-comments',
    'variables' => array('temp' => NULL),
  );
}

/**
 * Preprocess variables.
 */
function template_preprocess_pavelruban_last_comments(&$vars) {
  global $user;
  $comments = pavelruban_get_last_comments();
  if (count($comments)) {
    $vars['last_comments'] = $comments;
    $comments_storage = variable_get('pavelruban_last_comments', array());
    foreach ($comments as $comment) {
      $comments_storage[$comment['cid']]['accessed_uids'][] = $user->uid;
    }
    variable_set('pavelruban_last_comments', $comments_storage);
  }
}
