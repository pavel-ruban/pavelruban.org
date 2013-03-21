<?php
/**
 * @file
 * le_content_type_flash_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function le_content_type_flash_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function le_content_type_flash_news_node_info() {
  $items = array(
    'flash_news' => array(
      'name' => t('Flash News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
