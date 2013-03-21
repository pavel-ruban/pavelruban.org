<?php
/**
 * @file
 * le_panels_system_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function le_panels_system_template_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
