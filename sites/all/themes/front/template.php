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
  if ($vars['elements']['#view_mode'] == 'full') {
    $target_user = user_load(arg(1));
    $vars['target_user'] = $target_user;
    if ($user->uid == 1 || $user->uid == $target_user->uid) {
      $vars['edit_link'] = l(
        t('edit'),
        "user/$target_user->uid/edit",
        array(
          'attributes' => array('class' => array('user-edit-link')),
        )
      );
    }
    if (!empty($target_user->access)) {
      if (date('Y', time()) != ($year = date('Y', $target_user->access))) {
        $vars['access'] = "в $year году";
      }
      else {
        setlocale(LC_ALL, 'ru_RU.UTF8');
        $vars['access'] = strftime('%d %b в %H:%M', $target_user->access);
      }
    }
  }

  $build_mode_for_preprocess = str_replace('-', '_', $vars['elements']['#view_mode']);

  $vars['theme_hook_suggestions'][] = 'user_profile__' . $vars['elements']['#view_mode'];

  // Defines the priority of calling preprocess fuctions for specific usertype & build
  // modes.
  // Note: priority is calculated in reverse mode.
  $preprocess = array(
    'front_preprocess_user__' . $build_mode_for_preprocess,
  );

  foreach (array_reverse($preprocess) as $function) {
    if (function_exists($function)) {
      $function($vars, $hook);
      break;
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
 * Preprocess variables.
 */
function front_preprocess_asset__gallery(&$vars) {
  static $wow_slider_init = FALSE;
  if (!$wow_slider_init) {
    drupal_add_library('pavelruban', 'wow_slider');
    $wow_slider_init = TRUE;
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_asset__image(&$vars) {
  static $shadowbox_init = FALSE;
  if (!$shadowbox_init) {
    drupal_add_library('pavelruban', 'shadowbox');
    $shadowbox_init = TRUE;
  }

  if (!empty($vars['elements']['#disable_shadowbox'])) {
    $vars['image'] = render($vars['content']['field_asset_image']);
  }
  elseif (empty($vars['asset']->gallery_item) && !empty($vars['content']['field_asset_image']) && $vars['view_mode'] != 'teaser') {
    if (!empty($vars['field_asset_image'][0]['uri'])) {
      $url = file_create_url($vars['field_asset_image'][0]['uri']);
    }
    $url = empty($url) ? $_GET['q'] . '#' : $url;

    $vars['image'] = l(
      render($vars['content']['field_asset_image']),
      $url,
      array(
        'html' => TRUE,
        'attributes' => array('rel' => 'shadowbox[All media]'),
      )
    );
  }
  else {
    if (!empty($vars['asset']->gallery_item)) {
      if ($vars['view_mode'] == 'slider_viewport') {
        static $wowid = 1;
        static $units = 0;

        if (!empty($vars['content']['field_asset_image'][0]['#item'])) {
          $image = & $vars['content']['field_asset_image'][0]['#item'];
          $image['attributes']['id'] = array("wows${wowid}_${units}");
          $image['attributes']['title'] = array($vars['title']);
          $image['alt'] = array($vars['title']);
          $units++;
        }

        if (!empty($vars['field_asset_image'][0]['uri'])) {
          $url = file_create_url($vars['field_asset_image'][0]['uri']);
        }
        $url = empty($url) ? $_GET['q'] . '#' : $url;
        $gallery_name = !empty($vars['asset']->gallery_name) ? $vars['asset']->gallery_name : NULL;
        $desc = !empty($vars['content']['field_asset_description'])
          ? render($vars['content']['field_asset_description']) : '';
        $vars['image'] = l(
          render($vars['content']['field_asset_image']) . $desc,
          $url,
          array(
            'html' => TRUE,
            'attributes' => array('rel' => "shadowbox[$gallery_name]"),
          )
        );
      }
      elseif ($vars['view_mode'] == 'slider_thumbnail') {
        if (!empty($vars['content']['field_asset_image'][0]['#item'])) {
          $image = & $vars['content']['field_asset_image'][0]['#item'];
          $image['attributes']['title'] = array($vars['title']);
          $image['alt'] = array('');
        }
        $vars['image'] = l(
          render($vars['content']['field_asset_image']) . 'vertical image scroller',
          '',
          array(
            'html' => TRUE,
          )
        );
      }
    }
    else {
      $vars['image'] = render($vars['content']['field_asset_image']);
    }
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_entity(&$vars) {
  switch ($vars['entity_type']) {
    case 'asset':
      $asset = $vars['asset'];
      $build_mode_for_preprocess = str_replace('-', '_', $vars['view_mode']);

      $vars['theme_hook_suggestions'][] = 'asset__' . $vars['view_mode'];
      $vars['theme_hook_suggestions'][] = 'asset__' . $asset->type . '_' . $vars['view_mode'];

      // Defines the priority of calling preprocess fuctions for specific assettype & build
      // modes.
      // Note: priority is calculated in reverse mode.
      $preprocess = array(
        'front_preprocess_asset__' . $asset->type,
        'front_preprocess_asset__' . $build_mode_for_preprocess,
        'front_preprocess_asset__' . $asset->type . '_' . $build_mode_for_preprocess,
      );

      foreach (array_reverse($preprocess) as $function) {
        if (function_exists($function)) {
          $function($vars);
          break;
        }
      }
      break;

  }
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
    $vars['content']['field_article_media']['#disable_shadowbox'] = TRUE;
    $vars['media'] = render($vars['content']['field_article_media']);
  }
  if (!empty($vars['content']['field_article_catchline'])) {
    $description = render($vars['content']['field_article_catchline']);
    $vars['description'] = $description;
  }

  $result = db_select('node_statistic')
    ->fields('node_statistic', array('access_count'))
    ->condition('nid', $vars['nid'])
    ->execute()
    ->fetchCol();
  $acess_count = !empty($result[0]) ? $result[0] : 0;
  $vars['social'] = theme('social',
    array(
      'nid' => $vars['nid'],
      'comment_count' => $vars['comment_count'],
      'changed' => $vars['changed'],
      'share_title' => $vars['title'],
      'share_description' => $description,
      'access_count' => $acess_count,
    )
  );
  $tags = field_get_items('node', $vars['node'], 'field_tags');
  if (!empty($tags)) {
    $vars['tags'] = theme('tags', array('tags' => $tags));
  }
}

/**
 * Preprocess variables.
 */
function front_preprocess_html(&$vars) {
  global $user;
  $vars['tea_mug'] = '<div class="tea-mug-cloud"></div>' . l('', '',
      array(
        'attributes' => array('class' => array('tea-mug')),
      )
    );
  $arg1 = arg(1);
  if (arg(0) == 'user' && (in_array(arg(1), array('login'))
      || (empty($user->uid) && empty($arg1)))
  ) {
    $vars['classes_array'][] = 'mini-wrapper';
  }
  if (arg(0) == 'user' && in_array(arg(1), array('password'))) {
    $vars['classes_array'][] = 'medium-wrapper';
  }
  // $delay = 10 * 60;
  // $date = variable_get('pavelruban_change_environment', time() - ($delay + 1));

//  if ((time() - $date) > $delay) {
  $id = rand(1, 10);
  $vars['classes_array'][] = "img$id";
  variable_set('pavelruban_change_environment', time());
//  }

  // Social js.
  drupal_add_js('http://vkontakte.ru/js/api/openapi.js?98', 'external');
  drupal_add_js('https://platform.twitter.com/widgets.js', 'external');
  $vk_js_init = <<<init_vk_js
    VK.init({
      apiId: 3790252,
      onlyWidgets: true
    });
init_vk_js;
  drupal_add_js($vk_js_init, 'inline');

  // Statistic.
  if (preg_match('/^node\/([0-9]+)$/', $_GET['q'], $matches)) {
    $nid = $matches[1];

    $result = db_select('node_statistic')
      ->fields('node_statistic', array('access_count'))
      ->condition('nid', $nid)
      ->execute()
      ->fetchCol();

    if (empty($result)) {
      db_insert('node_statistic')
        ->fields(array('nid' => $nid, 'access_count' => 1))
        ->execute();
    }
    else {
      db_update('node_statistic')
        ->fields(array('nid' => $nid, 'access_count' => ++$result[0]))
        ->condition('nid', $nid)
        ->execute();
    }
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
    $description = render($vars['content']['field_article_catchline']);
    $vars['description'] = $description;
  }
  if (!empty($vars['content']['field_body'])) {
    $vars['body'] = render($vars['content']['field_body']);
  }

  $tags = field_get_items('node', $vars['node'], 'field_tags');
  if (!empty($tags)) {
    $vars['tags'] = theme('tags', array('tags' => $tags));
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


  if (date('Y', time()) != ($year = date('Y', $vars['comment']->changed))) {
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

/**
 * Redefine captcha theming.
 */
function front_image_captcha_refresh_link($variables) {
  $output = '<div class="reload-captcha-wrapper">';
  $output .= l(t('refresh'), $variables['url'], array('attributes' => array('class' => array('reload-captcha'))));
  $output .= '</div>';
  return $output;
}
