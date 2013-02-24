<?php

/**
 * @file theme.inc
 *
 * An array of preprocessors to fill variables for templates and helper
 * functions to make theming easier.
 */

/**
 * Preprocess template.
 */
function template_preprocess_ftv_janrain_capture_connection(&$variables) {
  // Provide default Drupal user links if anonymous.
  if (empty($variables['user_links_anonymous'])) {
    $user_links_anonymous[] = l(t('Log in'), 'user/login');
    // Add link to register form if user can is allowed to create account.
    if (user_register_access()) {
      $user_links_anonymous[] = l(t('Create new account'), 'user/register');
    }
    $variables['user_links_anonymous'] = theme('item_list', array('items' => $user_links_anonymous));
  }

  // Provide default Drupal user links if authenticated.
  if (empty($variables['user_links_authenticated'])) {
    $user_links_authenticated = array(
      l(t('User account'), 'user'),
      l(t('Log out'), 'user/logout'),
    );
    $variables['user_links_authenticated'] = theme('item_list', array('items' => $user_links_authenticated));
  }
}

/**
 * Returns HTML to display the Janrain Capture signin link.
 *
 * @ingroup themeable
 */
function theme_ftv_janrain_capture_signin() {
  $janrain_capture_link = '<span class="ftv-janrain-catpure ftv-janrain-catpure-anonymous">';
  $janrain_capture_link .= drupal_render(ftv_janrain_capture_signin_link());
  $janrain_capture_link .= '</span>';

  return $janrain_capture_link;
}

/**
 * Returns HTML to display the Janrain Capture register link.
 *
 * @ingroup themeable
 */
function theme_ftv_janrain_capture_register() {
  $janrain_capture_link = '<span class="ftv-janrain-catpure ftv-janrain-catpure-anonymous">';
  $janrain_capture_link .= drupal_render(ftv_janrain_capture_register_link());
  $janrain_capture_link .= '</span>';

  return $janrain_capture_link;
}

/**
 * Returns HTML to display the Janrain Capture logout link.
 *
 * @ingroup themeable
 */
function theme_ftv_janrain_capture_logout() {
  $janrain_capture_link = '<span class="ftv-janrain-catpure ftv-janrain-catpure-authenticated">';
  $janrain_capture_link .= ftv_janrain_capture_render_logout_link();
  $janrain_capture_link .= '</span>';

  return $janrain_capture_link;
}

/**
 * Returns HTML to display the Janrain Capture profile link.
 *
 * @ingroup themeable
 */
function theme_ftv_janrain_capture_profile() {
  $janrain_capture_link = '<span class="ftv-janrain-catpure ftv-janrain-catpure-authenticated">';
  $janrain_capture_link .= drupal_render(ftv_janrain_capture_profile_link());
  $janrain_capture_link .= '</span>';

  return $janrain_capture_link;
}


