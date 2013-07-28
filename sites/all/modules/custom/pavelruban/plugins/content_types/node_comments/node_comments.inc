<?php

if (module_exists('comment')) {
  /**
   * Plugins are described by creating a $plugin array which will be used
   * by the system that includes this file.
   */
  $plugin = array(
    'single' => TRUE,
    'title' => t('Node comments'),
    'icon' => 'icon_node.png',
    'description' => t('The comments of the referenced node.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'category' => t('Pavel Ruban'),
    'hook theme' => 'pavelruban_node_comments_theme',
    'defaults' => array(
      'mode' => variable_get('comment_default_mode', COMMENT_MODE_THREADED),
      'comments_per_page' => variable_get('comment_default_per_page', '50'),
    ),
  );
}

function pavelruban_node_comments_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'comments';
  $block->delta  = $node->nid;

  $block->title = t('Comments');
  if (empty($node)) {
    $block->content = t('Node comments go here.');
  }
  else if ($node->comment) {
    $comment_list = pavelruban_comment_render($node, $conf);
    $block->content = theme('pavelruban_node_comments', array('comment_list' => $comment_list, 'node' => $node));
    // Update the history table, stating that this user viewed this node.
    node_tag_new($node);
  }

  return $block;
}

function pavelruban_node_comments_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#default_value' => $conf['mode'],
    '#options' => _comment_get_modes(),
    '#weight' => 1,
  );
  foreach (_comment_per_page() as $i) {
    $options[$i] = t('!a comments per page', array('!a' => $i));
  }
  $form['comments_per_page'] = array('#type' => 'select',
    '#title' => t('Pager'),
    '#default_value' => $conf['comments_per_page'],
    '#options' => $options,
    '#weight' => 3,
  );
  return $form;
}

function pavelruban_node_comments_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function pavelruban_node_comments_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" comments', array('@s' => $context->identifier));
}

/**
 * This function is a somewhat stripped down version of comment_render
 * that removes a bunch of cruft that we both don't need, and makes it
 * difficult to modify this.
 */
function pavelruban_comment_render($node, $conf) {
  $output = '';
  if (!user_access('access comments') || !$node->comment) {
    return;
  }

  $mode = $conf['mode'];
  $comments_per_page = $conf['comments_per_page'];

  $cids = comment_get_thread($node, $mode, $comments_per_page);
  $comments = comment_load_multiple($cids);

  if ($comments) {
    drupal_add_css(drupal_get_path('module', 'comment') . '/comment.css');
    comment_prepare_thread($comments);
    $build = comment_view_multiple($comments, $node);
    $build['pager']['#theme'] = 'pager';
    return drupal_render($build);
  }
  return;
}

/**
 * Implements of hook_theme().
 */
function pavelruban_node_comments_theme(&$theme, $plugin) {
  $theme['pavelruban_node_comments'] = array(
    'path'      => $plugin['path'],
    'template'  => 'pavelruban-node-comments',
    'variables' => array('comment_list' => NULL),
  );
}

/**
 * Preprocess.
 */
function pavelruban_preprocess_pavelruban_node_comments(&$vars) {
  global $user;
  if ($user->uid == 0) {
    $vars['anonym'] = TRUE;
  }
  $vars['add_comment_link'] = l(
    t('add comment'),
    '#',
    array(
      'attributes' => array(
        'class' => array('add-comment'),
      ),
    )
  );

  $result = db_select('node_statistic')
   ->fields('node_statistic', array('access_count'))
   ->condition('nid', $vars['node']->nid)
   ->execute()
   ->fetchCol();
  $acess_count = !empty($result[0]) ? $result[0] : 0;
  $vars['social'] = theme('social',
    array(
      'nid' => $vars['node']->nid,
      'comment_count' => $vars['node']->comment_count,
      'changed' => $vars['node']->changed,
      'share_title' => check_plain($vars['node']->title),
      'share_description' => '',
      'access_count' => $acess_count,
      'mode' => 'full',
      'part' => 'bottom',
    )
  );

  $login_link = l(t('login'), 'user/login');
  $register_link = l(t('register'), 'user/register');

  $vars['login_comment_link'] = sprintf('%s | %s', $login_link, $register_link);
}
