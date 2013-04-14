<?php
/**
 * @file
 * le_content_type_author.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function le_content_type_author_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function le_content_type_author_node_info() {
  $items = array(
    'author' => array(
      'name' => t('Author'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Prénom'),
      'help' => '',
    ),
  );
  return $items;
}
