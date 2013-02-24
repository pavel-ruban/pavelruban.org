<?php
/**
 * @file
 * le_assets.features.inc
 */

/**
 * Implements hook_default_asset_type().
 */
function le_assets_default_asset_type() {
  $items = array();
  $items['poll'] = entity_import('asset_type', '{
    "type" : "poll",
    "name" : "Sondage",
    "icon" : "AddEncadre.png",
    "description" : "",
    "help" : "",
    "weight" : "0",
    "locked" : "0",
    "uuid" : "",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function le_assets_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
