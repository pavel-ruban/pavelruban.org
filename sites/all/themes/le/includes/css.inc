<?php

/**
 * @file
 * This file provides alter css for pages by url.
 */

/**
 * Implements hook_css_alter().
 */
function le_css_alter(&$css) {
  /*if (drupal_is_front_page()) {
    $css[GEOPOLIS_THEME_PATH . '/css/home.css'] = array(
      'group' => 100,
      'every_page' => FALSE,
      'media' => 'all',
      'type' => 'file',
      'weight' => 0.006,
      'preprocess' => FALSE,
      'data' => GEOPOLIS_THEME_PATH . '/css/home.css',
    );
  }*/
}
