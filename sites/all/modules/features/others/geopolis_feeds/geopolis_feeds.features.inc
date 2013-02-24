<?php
/**
 * @file
 * geopolis_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function geopolis_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function geopolis_feeds_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function geopolis_feeds_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Flux'),
      'base' => 'node_content',
      'description' => t('Subscribe to RSS or Atom feeds. Creates nodes of the content type "Feed item" from feed content.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'feed_item' => array(
      'name' => t('Feed item'),
      'base' => 'node_content',
      'description' => t('This content type is being used for automatically aggregated content from feeds.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
