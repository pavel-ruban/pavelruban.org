<?php

/**
 * @file
 * This file update counter for node view.
 */

$real_cwd = getcwd();
if (!defined('DRUPAL_ROOT')) {
  // Suppose that we in sites/all/modules/contrib/module folder, and calculate drupal root path.
  define('DRUPAL_ROOT', $real_cwd . '/../../../../..');
}
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

if (isset($_REQUEST['nid'])) {
  $nid = (int) $_REQUEST['nid'];
  if ($nid) {
    // Update counter. Daycount reset by hook_cron in statistics module.
    db_merge('node_counter')
      ->key(array('nid' => $nid))
      ->fields(array('timestamp'), array($_SERVER['REQUEST_TIME']))
      ->expression('totalcount', 'totalcount + 1')
      ->expression('daycount', 'daycount + 1')
      ->expression('month_count', 'month_count + 1')
      ->execute();
  }
}

$im = imagecreatefromgif($real_cwd . '/spacer.gif');
header('Content-Type: image/gif');
imagegif($im);
imagedestroy($im);
exit;
