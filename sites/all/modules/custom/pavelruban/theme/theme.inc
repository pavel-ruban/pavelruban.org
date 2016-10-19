<?php
/**
 * @file
 * Theme preprocess logic.
 */

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_like_popup(&$vars) {
  if (empty($vars['mode']) || $vars['mode'] == 'teaser') {
    if (!empty($vars['meta'])) {
      $meta = array();
      foreach ($vars['meta'] as $item) {
        if ($item['uid'] > 0) {
          $meta[] = $item;
        }
      }

      $likedCount = count($meta);
      $meta = array_slice($meta, 0, 4);
      $liked_users = '';
      foreach ($meta as $vote) {
        $account = user_load($vote['uid']);
        $user_view = user_view($account, 'like_mini');
        $liked_users .= render($user_view);
      }

      $vars['likedCount'] = $likedCount;
      $vars['likedUsers'] = $liked_users;
    }
    else {
      $vars['likedCount'] = 0;
      $vars['likedUsers'] = '';
    }
  }
  else {
    if (!empty($vars['meta'])) {
      $meta = array();
      foreach ($vars['meta'] as $item) {
        if ($item['uid'] > 0) {
          $meta[] = $item;
        }
      }

      $likedCount = count($meta);
      $liked_users = '';
      foreach ($meta as $vote) {
        $account = user_load($vote['uid']);
        $user_view = user_view($account, 'like_full');
        $liked_users .= render($user_view);
      }

      $vars['likedCount'] = $likedCount;
      $vars['likedUsers'] = $liked_users;
    }
    else {
      $vars['likedCount'] = 0;
      $vars['likedUsers'] = '';
    }

  }
  // Save count data within static variable to allow above theming to use this data.
  pavelruban_current_like_count($vars['likedCount'], 'write');
}

/**
 * Static storage for link data within two themings.
 */
function pavelruban_current_like_count($value = 0, $mode = 'get') {
  static $likesCount = 0;

  switch ($mode) {
    case 'get':
      return $likesCount;

    case 'write':
      $likesCount = $value;
  }
}

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_tags(&$vars) {
  if (!empty($vars['nid'])) {
    $vars['tags_info'] = pavelruban_tags_context($vars['nid']);
  }
}

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_social_popup(&$vars) {
  if (!empty($vars['nid']) && is_numeric($vars['nid'])) {
    $node = node_load($vars['nid']);
    $nid = $vars['nid'];
  }

  if (empty($node) || $node->type !== 'article') return;

  $social_meta = array();
  $url = url("node/{$node->nid}", array('absolute' => TRUE, 'alias' => FALSE));

  $image = field_get_items('node', $node, 'field_article_media');

  if (!empty($image[0]['entity']->field_asset_image)) {
    $asset = field_get_items('asset', $image[0]['entity'], 'field_asset_image');
    if (!empty($asset[0]['uri'])) {
      $image_url = file_create_url($asset[0]['uri']);
    }
  }

  // Build Tweetter hashtags.
  $tag_info = pavelruban_tags_context($nid);
  $hashtags = array();

  foreach ($tag_info as $tag) {
    if (!empty($tag['name'])) {
      $hashtags[] = $tag['name'];
    }
  }

  $hash_count = count($hashtags);
  $social_meta['hashtags'] = implode($hashtags, ',');
  $hash_strlen = strlen($social_meta['hashtags']) + $hash_count + 1; // hash per tag.
  $url_strlen = strlen($url);

  $title = $node->title;

  $description = field_get_items('node', $node, 'field_article_catchline');
  $description = !empty($description[0]['value']) ? $description[0]['value'] : '';
  $description = preg_replace('/\r|\n/', '', $description);

  if ($url_strlen > 140) {
    $url = url('', array('absolute' => TRUE));
    $url_strlen = strlen($url);
  }

  if ($url_strlen + $hash_strlen > 140) {
    $social_meta['hashtags'] = '';
    $tweeter_text = '';
  }
  else {
    $tweet_title = truncate_utf8($title, 140 - $url_strlen - $hash_strlen - 1, TRUE, TRUE);

    $tweeter_text = $tweet_title;
  }

  $social_meta['title'] = $title;
  $social_meta['description'] = $description;
  $social_meta['tweeter_text'] = $tweeter_text;
  $social_meta['url'] = $url;
  $social_meta['raw_url'] = $url;
  $social_meta['image'] = !empty($image_url) ? $image_url : '';

  $vars['social_meta'] = $social_meta;
}

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_social(&$vars) {
  global $user;

  if (!empty($vars['changed'])) {
    $vars['last_changed'] = date('d M Y H:i:s', $vars['changed']);
  }

  $nid = $vars['nid'];

  if (user_access('edit any article content')) {
    $vars['edit_info_link'] = l(
      '',
      "node/$nid/edit",
      array(
        'attributes' => array(
          'class' => array('updated-info'),
          'title' => 'Обновлено',
        ),
      )
    );
  }

  $node = node_load($vars['nid']);

  if ($node->type !== 'article' && $node->type !== 'page')
     return;

  $vars['comment_link'] = l(
    '',
    "node/$nid",
    array(
      'html' => TRUE,
      'fragment' => 'comment-end',
      'attributes' => array('class' => array("comments-img"))
    )
  );

  $criteria = array(
    'uid' => $user->uid,
    'entity_id' => $nid,
    'value_type' => 'points',
  );

  if (!$user->uid) {
    $criteria += array(
      'vote_source' => ip_address(),
    );
  }

  $user_votes = votingapi_select_votes($criteria);
  $node_votes = votingapi_select_votes(
    array(
      'entity_id' => $vars['nid'],
      'entity_type' => 'node',
    )
  );

  $href = "ajax/vote/node/$nid" . (empty($user_votes) ? '' : '/delete');
  $link_title = empty($user_votes) ? 'мне нравится' : 'оценено';
  $link_class = 'like-ajax-img' . (empty($user_votes) ? '' : ' voted');

  $vars['like_link'] = l(
    '',
    $href,
    array(
      'attributes' => array(
        'title' => $link_title,
        'class' => array($link_class),
      ),
    )
  );

  $vars['votes_count'] = count($node_votes);
  $vars['like_popup'] = theme('like_popup', array('meta' => $node_votes, 'nid' => $vars['nid'], 'vars' => $vars));

  $likes_count = pavelruban_current_like_count();
  $vars['empty_likes_count'] = empty($likes_count) ? TRUE : FALSE;
}
