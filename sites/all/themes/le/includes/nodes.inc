<?php
/**
 * @file
 * This file provides preprocess functions for nodes.
 */

/**
 * Override or insert variables into the node template.
 */
function le_preprocess_node(&$vars, $hook) {
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
    'le_preprocess_node__' . $node->type,
    'le_preprocess_node__' . $build_mode_for_preprocess,
    'le_preprocess_node__' . $node->type . '_' . $build_mode_for_preprocess,
  );

  foreach (array_reverse($preprocess) as $function) {
    if (function_exists($function)) {
      $function($vars, $hook);
      break;
    }
  }
}

/**
 * Preprocess for article with view_mode full.
 */
function le_preprocess_node__article_full(&$vars) {

  $node = $vars['node'];
  $rubrique = field_get_items('node', $vars['node'], 'field_category');
  // Get rubrique.
  if (!empty($rubrique)) {
    $rubrique = taxonomy_term_load($rubrique[0]['tid']);
    if (!empty($rubrique)) {
      $vars['rubrique'] = check_plain($rubrique->name);
    }
  }

  // Get author info.
  if (!empty($vars['field_signature'][0]['entity'])) {
    $author = $vars['field_signature'][0]['entity'];
  }

  if (!empty($author)) {
    $author_name = $author->title;
    $lastname = field_get_items('node', $author, 'field_lastname');
    if (!empty($lastname)) {
      $author_name .= ' ' . $lastname[0]['value'];
    }
    $author_name = check_plain($author_name);
    $signature_author_name = '<u>' . $author_name . '</u>';

    // Add twitter for author.
    $twitter = field_get_items('node', $author, 'field_twitter');
    if (!empty($twitter)) {
      $tw_title = '(' . $twitter[0]['title'] . ')';
      $twitter = l($tw_title, $twitter[0]['url'], array('attributes' => array('target' => '_blank')));
    }
  }

  // Get date.
  $publication_date = t(
    'le @date à @time',
    array(
      '@date' => format_date($node->created, 'custom', 'd/m/Y'),
      '@time' => format_date($node->created, 'custom', LE_THEME_TIME_FORMAT),
    )
  );
  if ($node->created != $node->changed) {
    $publication_date .= ', ' . t(
      '(mis à jour le @date à @time)',
      array(
        '@date' => format_date($node->changed, 'custom', 'd/m/Y'),
        '@time' => format_date($node->changed, 'custom', LE_THEME_TIME_FORMAT),
      )
    );
  }

  // Set signature for article.
  $vars['signature'] = t(
    'Par !author !twitter @date',
    array('!author' => $signature_author_name, '!twitter' => $twitter, '@date' => $publication_date)
  );

  // Share links.
  $vars['share_top'] = theme('le_share_links', array('mode' => 'top'));
  $vars['share_bottom'] = theme(
    'le_share_links',
    array(
      'mode' => 'bottom',
      'data' => array('author' => t('Par @author', array('@author' => $author_name))),
    )
  );

  // Prepare image.
  if (!empty($vars['content']['field_article_media'])) {
    $vars['media_content'] = render($vars['content']['field_article_media']);
  }
}

/**
 * Preprocess for article with view_mode related articles.
 */
function le_preprocess_node__article_related_articles(&$vars) {

  $node = $vars['node'];
  // Prepare image.
  if (!empty($vars['content']['field_article_media'])) {
    $media = render($vars['content']['field_article_media']);
    if (!empty($media)) {
      $vars['media_content'] = l($media, 'node/' . $node->nid, array('html' => TRUE));
    }
  }

  $vars['title_link'] = l($vars['title'], 'node/' . $node->nid);
}

/**
 * Preprocess for article with view_mode related articles.
 */
function le_preprocess_node__folder_related_articles(&$vars) {

  $node = $vars['node'];
  // Prepare image.
  if (!empty($vars['content']['field_folder_illustration'])) {
    $media = render($vars['content']['field_folder_illustration']);
    if (!empty($media)) {
      $vars['media_content'] = l($media, 'node/' . $node->nid, array('html' => TRUE));
    }
  }

  $vars['title_link'] = l($vars['title'], 'node/' . $node->nid);
}

/**
 * Preprocess variables for article in video_article build mode.
 */
function le_preprocess_node__article_video_article(&$vars) {
  $node = $vars['node'];
  $rubrique = field_get_items('node', $vars['node'], 'field_category');
  // Get rubrique.
  if (!empty($rubrique)) {
    $rubrique = taxonomy_term_load($rubrique[0]['tid']);
    if (!empty($rubrique)) {
      $vars['rubrique'] = check_plain($rubrique->name);
    }
  }

  // Get author info.
  if (!empty($vars['field_signature'][LANGUAGE_NONE][0]['target_id'])) {
    $author = user_load($vars['field_signature'][LANGUAGE_NONE][0]['target_id']);
  }

  if (!empty($author)) {
    $author_name = $author->name;
    $lastname = field_get_items('user', $author, 'field_user_lastname');
    if (!empty($lastname)) {
      $author_name .= ' ' . $lastname[0]['value'];
    }
    $author_name = check_plain($author_name);
    $signature_author_name = '<u>' . $author_name . '</u>';

    // Add twitter for author.
    $twitter = field_get_items('user', $author, 'field_twitter');
    if (!empty($twitter)) {
      $tw_title = '(' . $twitter[0]['title'] . ')';
      $twitter = l($tw_title, $twitter[0]['url'], array('attributes' => array('target' => '_blank')));
    }
  }

  // Get date.
  $publication_date = t(
    'le @date à @time',
    array(
      '@date' => format_date($node->created, 'custom', 'd/m/Y'),
      '@time' => format_date($node->created, 'custom', LE_THEME_TIME_FORMAT),
    )
  );
  if ($node->created != $node->changed) {
    $publication_date .= ', ' . t(
      '(mis à jour le @date à @time)',
      array(
        '@date' => format_date($node->changed, 'custom', 'd/m/Y'),
        '@time' => format_date($node->changed, 'custom', LE_THEME_TIME_FORMAT),
      )
    );
  }

  // Set signature for article.
  $vars['signature'] = t(
    'Par !author !twitter @date',
    array('!author' => $signature_author_name, '!twitter' => $twitter, '@date' => $publication_date)
  );

  // Share links.
  $vars['share_top'] = theme('le_share_links', array('mode' => 'top'));

  // Prepare image.
  if (!empty($vars['content']['field_article_media'])) {
    $vars['media_content'] = render($vars['content']['field_article_media']);
  }
}

