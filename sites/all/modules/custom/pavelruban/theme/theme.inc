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
        if ($item->uid > 0) {
          $meta[] = $item;
        }
      }

      $likedCount = count($meta);
      $meta = array_slice($meta, 0, 4);
      $liked_users = '';
      foreach ($meta as $user) {
        $account = user_load($user->uid);
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
        if ($item->uid > 0) {
          $meta[] = $item;
        }
      }

      $likedCount = count($meta);
      $liked_users = '';
      foreach ($meta as $user) {
        $account = user_load($user->uid);
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
}

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_tags(&$vars) {
  if (!empty($vars['tags'])) {
    $tids = array();
    foreach ($vars['tags'] as $tag) {
      $tids[] = $tag['tid'];
    }

    $terms = taxonomy_term_load_multiple($tids);
    foreach ($vars['tags'] as $tag) {
      $vars['tags_info'][] = array(
        'name' => $terms[$tag['tid']]->name,
        'tid' => $tag['tid'],
      );
    }
  }
}

/**
 * Preprocess variables.
 */
function pavelruban_preprocess_social(&$vars) {
  global $user;
  if (!empty($vars['changed'])) {
    $vars['last_changed'] = date('d M Y H:i:s', $vars['changed']);
  }

  // Is user already liked node.
  $vote = array(
    'value' => 1,
    'value_type' => 'points',
    'entity_id' => $vars['nid'],
    'uid' => $user->uid,
  );
  $user_vote = votingapi_select_votes($vote);

  if (!empty($user_vote[0]['vote_id'])) {
    $vars['voted'] = TRUE;
  }
  $result = pavelruban_get_node_votes_count($vars['nid']);
  $vars['votes_count'] = $result['count'];
  $vars['like_popup'] = theme('like_popup', array('meta' => $result['meta'], 'nid' => $vars['nid']));

  $node = node_load($vars['nid']);
  $social_meta = array();
  $url = url("node/{$node->nid}", array('absolute' => TRUE, 'alias' => FALSE));

  $title = $node->title;
  $title = truncate_utf8($title, 140, TRUE, TRUE);
  $description = field_get_items('node', $node, 'field_article_catchline');
  $description = !empty($description[0]['value']) ? $description[0]['value'] : '';
  $description = preg_replace('/\r|\n/', '', $description);
  $tweeter_text = truncate_utf8("$title | $description", 140 - strlen($url) - 1, TRUE, TRUE);
  $description = truncate_utf8($description, 140 - strlen($title), TRUE, TRUE);

  $image = field_get_items('node', $node, 'field_article_media');

  if (!empty($image[0]['entity']->field_asset_image)) {
    $asset = field_get_items('asset', $image[0]['entity'], 'field_asset_image');
    if (!empty($asset[0]['uri'])) {
      $image_url = file_create_url($asset[0]['uri']);
    }
  }

  $social_meta['title'] = $title;
  $social_meta['description'] = $description;
  $social_meta['tweeter_text'] = $tweeter_text;
  $social_meta['url'] = $url;
  $social_meta['image'] = !empty($image_url) ? $image_url : '';

  $vars['social_meta'] = $social_meta;
}
