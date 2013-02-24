<?php
/**
 * @file
 * le_taxonomy_vocabularies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function le_taxonomy_vocabularies_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
