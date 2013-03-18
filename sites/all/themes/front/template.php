<?php
/**
 * @file
 * Render logic and theme hooks for front theme.
 */

/**
 * Override or insert variables into the node template.
 */
function front_preprocess_comment(&$vars) {
  $user = user_load($vars['comment']->uid);
  $user_view = user_view($user, 'comments');
  $picture = render($user_view['field_user_image']);
  $vars['picture'] = l(
    $picture,
    "user/{$user->uid}",
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('reply_image'),
      ),
    )
  );
  $vars['author'] = l(
    "<span>{$user->name}</span>",
    "user/{$user->uid}",
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('username'),
      ),
    )
  );
  $a = 1;
}

/**
 * Override or insert variables into the node template.
 */
function front_preprocess_node(&$vars, $hook) {
  if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
    $vars['classes_array'][] = 'node-full';
  }

  $node = $vars['node'];
  $build_mode_for_preprocess = str_replace('-', '_', $vars['view_mode']);

  $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . $vars['view_mode'];

  // Defines the priority of calling preprocess fuctions for specific nodetype & build
  // modes.
  // Note: priority is calculated in reverse mode.
  $preprocess = array(
    'front_preprocess_node__' . $node->type,
    'front_preprocess_node__' . $build_mode_for_preprocess,
    'front_preprocess_node__' . $node->type . '_' . $build_mode_for_preprocess,
  );

  foreach (array_reverse($preprocess) as $function) {
    if (function_exists($function)) {
      $function($vars, $hook);
      break;
    }
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_node__article_teaser(&$vars) {
  if (!empty($vars['content']['field_media'])) {
    $vars['media'] = render($vars['content']['field_media']);
  }
  if (!empty($vars['content']['field_description'])) {
    $vars['description'] = render($vars['content']['field_description']);
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_html(&$vars) {
  $vars['tea_mug'] = theme('image',
    array(
      'path' => '/sites/all/themes/front/images/cup.png',
      'attributes' => array('class' => array('tea-mug')),
    )
  );
  $vars['pencil'] = theme('image',
    array(
      'path' => '/sites/all/themes/front/images/pencils.png',
      'attributes' => array('class' => array('pencil')),
    )
  );
}

/**
 * Preprocess variables.
 */
function front_preprocess_node__article_full(&$vars) {
  if (!empty($vars['content']['field_media'])) {
    $vars['media'] = render($vars['content']['field_media']);
  }
  if (!empty($vars['content']['body'])) {
    $vars['body'] = render($vars['content']['body']);
  }
}
