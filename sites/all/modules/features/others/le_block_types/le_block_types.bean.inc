<?php
/**
 * @file
 * le_block_types.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function le_block_types_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'facebook';
  $bean_type->label = 'Facebook';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['facebook'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'html_libre_block';
  $bean_type->label = 'HTML Libre Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['html_libre_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'mise_en_avant_block';
  $bean_type->label = 'Mise en Avant Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['mise_en_avant_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'sondage_block';
  $bean_type->label = 'Sondage Block';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['sondage_block'] = $bean_type;

  return $export;
}
