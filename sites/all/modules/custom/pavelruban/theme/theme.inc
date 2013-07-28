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
}
