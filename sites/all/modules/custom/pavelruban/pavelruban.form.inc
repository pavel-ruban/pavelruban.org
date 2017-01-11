<?php
/**
 * @file
 * From functional.
 */

/**
 * Implement hook_form_alter().
 */
function pavelruban_form_alter(&$form, &$form_state, $form_id) {
  $form['#after_build'][] = 'pavelruban_captcha_afterbuild';

  if (!empty($form['captcha'])) {
    unset($form['captcha']['#description']);
  }
  switch ($form_id) {
    case 'user_profile_form':
      $form['#submit'][] = 'pavelruban_add_redirect';
      $form['account']['field_about_me'] = $form['field_about_me'];
      $form['account']['field_about_me']['#weight'] = -4;
      unset($form['field_about_me']);
      $form['account']['field_user_contacts'] = $form['field_user_contacts'];
      $form['account']['field_user_contacts']['#weight'] = -5;
      unset($form['field_user_contacts']);
      $form['account']['current_pass']['#weight'] = -2;
      $form['account']['mail']['#weight'] = -6;
      $form['timezone']['#collapsed'] = TRUE;
      break;

    case 'user_login':
      $form['name']['#description'] = t('Enter your username.');
      break;

    case 'comment_node_article_form':
      $form['actions']['preview']['#access'] = FALSE;
      $form['actions']['submit']['#value'] = t('submit');
      $form['subject']['#access'] = FALSE;
      $form['author']['#access'] = FALSE;
      break;

    case 'comment_node_page_form':
      $form['actions']['preview']['#access'] = FALSE;
      $form['actions']['submit']['#value'] = t('submit');
      $form['subject']['#access'] = FALSE;
      $form['author']['#access'] = FALSE;
      break;
  }

  if (preg_match('/comment.*form/', $form_id)) {
    $form['#validate'][] = 'pavelruban_comment_form_validate';
  }
}

/**
 * Don't allow bots past comments with hrefs & urls.
 *
 * @param $form
 * @param $form_state
 */
function pavelruban_comment_form_validate($form, &$form_state) {
  if (!empty($form_state['values']['comment_body'][LANGUAGE_NONE][0]['value'])) {
    $comment = $form_state['values']['comment_body'][LANGUAGE_NONE][0]['value'];

    $regex = '/\[\s*?url\s*?=|(?:http(?:s)|ftp)?:\/\/|<a[^<]*?href=/';

    if (preg_match($regex, $comment)) {
      form_set_error(
        'comment_body',
        t('Sorry but you are not allowed use any references & links inside your comment. Ha ha ha. Go out of my site spammy bot!')
      );
    }
  }
}

/**
 * Submit.
 */
function pavelruban_captcha_afterbuild($form, &$form_state) {
  $form['captcha']['captcha_widgets']['captcha_response']['#title'] = t('Captcha');
  unset($form['captcha']['captcha_widgets']['captcha_response']['#description']);
  return $form;
}

/**
 * Submit.
 */
function pavelruban_add_redirect(&$form, &$form_state) {
  global $user;
  $form_state['redirect'] = "user/$user->uid";
}

