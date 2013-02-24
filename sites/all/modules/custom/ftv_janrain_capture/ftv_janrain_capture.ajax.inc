<?php

/**
 * @file
 * Page callbacks for FTV Janrain Capture module.
 */


/**
 * Ajax callback: Retrieve user informations.
 *
 */
function ftv_janrain_capture_user() {
  // Force cache-control to 0.
  // drupal_add_http_header('Cache-Control', 'max-age=0');
  drupal_add_http_header('Cache-Control', 'max-age=0, no-cache, must-revalidate, post-check=0, pre-check=0');

  if (user_is_anonymous()) {
    // Display anonymous links : signin and register links
    $commands[] = ajax_command_css('.ftv-janrain-catpure-anonymous', array('display' => 'inline'));
  }
  // User is authenticated to Drupal
  else {
    // Display authenticated links : profile and logout links
    $commands[] = ajax_command_css('.ftv-janrain-catpure-authenticated', array('display' => 'inline'));

    // Display welcome user message if activated
    $username = isset($_SESSION['janrain_capture_displayname']) ? $_SESSION['janrain_capture_displayname'] : NULL;
    if (variable_get('ftv_janrain_capture_display_username', TRUE) && !empty($username)) {
      $selector = '#block-ftv-janrain-capture-ftv-janrain-capture-connection .item-list';
      $welcome_user = '<h3>' . t('Hello <strong>@username</strong>', array('@username' => $username)) . '</h3>';
      $commands[] = ajax_command_prepend($selector, $welcome_user);
    }

    // Override token_expired_url settings url
    // Get Janrain token expire url because this value should be wrong into Drupal.settings because of caching (Varnish)
    $token_expired_url = url('janrain_capture/token_expired/' . drupal_get_token('janrain_capture_token_expired'));
    $setting['janrainCapture']['token_expired_url'] = $token_expired_url;
    // Override logout_url : user/* is deny from all
    if (isset($_GET['destination']) && !empty($_GET['destination'])) {
      $query['destination'] = $_GET['destination'];
      $setting['janrainCapture']['logout_url'] = url('janrain_capture/user-logout', array('absolute' => TRUE, 'query' => $query));
    }
    else {
      $setting['janrainCapture']['logout_url'] = url('janrain_capture/user-logout', array('absolute' => TRUE));
    }
    $commands[] = ajax_command_settings($setting, TRUE);

    // Check missing data.
    // Execute Drupal.ajax.prototype.commands.check_missing_data
    // $user_missing_data = isset($_SESSION['janrain_capture_missing_data']) ? $_SESSION['janrain_capture_missing_data'] : NULL;
    // $commands[] = array(
    //   'command' => 'ftv_janrain_capture_check_missing_data',
    //   'data' => array(
    //     'user_missing_data' => $user_missing_data,
    //   ),
    // );
  }

  // Allow others modules to add commands
  drupal_alter('ftv_janrain_capture_user', $commands);

  return array('#type' => 'ajax', '#commands' => $commands);
}
