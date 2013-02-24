<?php

/**
 * @file
 * User page callbacks for the ftv_janrain_capture module.
 */

/**
 * Packages and sends the result of a page callback to the browser as HTML.
 *
 * @param string $page_callback_result
 *   The result of a page callback. Can be one of:
 *   - NULL: to indicate no content.
 *   - An integer menu status constant: to indicate an error condition.
 *   - A string of HTML content.
 *   - A renderable array of content.
 *
 * @see drupal_deliver_page()
 */
// function ftv_janrain_capture_popin($page_callback_result) {
//   // Emit the correct charset HTTP header, but not if the page callback
//   // result is NULL, since that likely indicates that it printed something
//   // in which case, no further headers may be sent, and not if code running
//   // for this page request has already set the content type header.
//   if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
//     drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
//   }

//   // Send appropriate HTTP-Header for browsers and search engines.
//   global $language;
//   drupal_add_http_header('Content-Language', $language->language);

//   // Print directly the content.
//   print $page_callback_result;

//   // Perform end-of-request tasks.
//   drupal_page_footer();
// }

/**
 * Logout the user
 */
function ftv_janrain_capture_logout() {
  // Logout the user for authenticated users.
  if (user_is_logged_in()) {
    module_load_include('pages.inc', 'user', 'user');
    user_logout();
  }
  // Redirect users to homepage if anonymous.
  else {
    drupal_goto();
  }
}
