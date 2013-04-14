<?php
/**
 * @file
 * common_content_type_product.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function common_content_type_product_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function common_content_type_product_node_info() {
  $items = array(
    'product' => array(
      'name' => t('product'),
      'base' => 'node_content',
      'description' => t('Use <em>products</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
