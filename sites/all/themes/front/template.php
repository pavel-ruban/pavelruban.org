<?php
/**
 * @file
 * Render logic and theme hooks for front theme.
 */

/**
 * Process variables.
 */
function front_preprocess_user_profile(&$vars) {
  global $user;
  $vars['edit_link'] = l(
    t('edit'),
    "user/$user->uid/edit",
    array(
      'attributes' => array('class' => array('user-edit-link')),
    )
  );
  if (!empty($user->access)) {
    if (date('Y', time()) != ($year = date('Y', $user->access)))  {
      $vars['access'] = "в $year году";
    }
    else {
      setlocale(LC_ALL, 'ru_RU.UTF8');
      $vars['access'] = strftime('%d %b в %H:%M', $user->access);
    }
  }
}

/**
 * Theming redefine.
 */
function front_imagefield_crop_widget($variables) {
  $element = $variables['element'];
  $output = '';
  $output .= '<div class="imagefield-crop-widget form-managed-file clearfix">';

  if (isset($element['preview'])) {
    $output .= '<div class="imagefield-crop-preview">';
    $output .= drupal_render($element['preview']);
    $output .= '</div>';
  }
  $output .= drupal_render_children($element);
  if (isset($element['cropbox'])) {
    $output .= '<div class="imagefield-crop-cropbox">';
    $output .= drupal_render($element['cropbox']);
    $output .= '</div>';
  }
  $output .= '</div>';
  return $output;
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
  if (!empty($vars['content']['field_article_media'])) {
    $vars['media'] = render($vars['content']['field_article_media']);
  }
  if (!empty($vars['content']['field_article_catchline'])) {
    $vars['description'] = render($vars['content']['field_article_catchline']);
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_html(&$vars) {
  $vars['tea_mug'] = l('', '',
    array(
      'attributes' => array('class' => array('tea-mug')),
    )
  );
  if (arg(0) == 'user' && in_array(arg(1), array('login'))) {
    $vars['classes_array'][] = 'mini-wrapper';
  }
  if (arg(0) == 'user' && in_array(arg(1), array('password'))) {
    $vars['classes_array'][] = 'medium-wrapper';
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_node__article_full(&$vars) {
  if (!empty($vars['content']['field_article_media'])) {
    $vars['media'] = render($vars['content']['field_article_media']);
  }
  if (!empty($vars['content']['field_article_catchline'])) {
    $vars['description'] = render($vars['content']['field_article_catchline']);
  }
  if (!empty($vars['content']['field_body'])) {
    $vars['body'] = render($vars['content']['field_body']);
  }
}

/**
 * Override or insert variables into the node template.
 */
function front_preprocess_comment(&$vars) {
  global $user;
  $comment_owner = user_load($vars['comment']->uid);
  $comment_owner_view = user_view($comment_owner, 'comments');
  $picture = render($comment_owner_view['field_asset_image']);

  if ($comment_owner->uid == 0) {
    $vars['author'] = "<span class=\"anonym\">аноним</span>";
    $vars['picture'] = '<div class="anonym reply_image"></div>';
  }
  else {
    $vars['author'] = l(
      "<span>{$comment_owner->name}</span>",
      "user/{$comment_owner->uid}",
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('username'),
        ),
      )
    );
    $vars['picture'] = l(
      $picture,
      "user/{$comment_owner->uid}",
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('reply_image'),
        ),
      )
    );
  }


  if (date('Y', time()) != ($year = date('Y', $vars['comment']->changed)))  {
    $vars['date'] = $year;
  }
  else {
    setlocale(LC_ALL, 'ru_RU.UTF8');
    $vars['date'] = strftime('%d %b в %H:%M', $vars['comment']->changed);
  }

  $delete = $user->uid == 1 || ($user->uid == $comment_owner->uid
    && ((time() - $vars['comment']->changed) < 300));
  if ($delete) {
    $vars['delete_link'] = l(
      "<div class\"=comment-delete-img\"></div>",
      "ajax/comment/{$vars['comment']->cid}/delete",
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('comment-delete-link'),
        ),
      )
    );
    $vars['delete'] = $delete;
  }
}