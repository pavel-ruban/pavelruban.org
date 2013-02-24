<?php
/**
 * @file
 * le_taxonomy_vocabularies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function le_taxonomy_vocabularies_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blocks|taxonomy_term|category|form';
  $field_group->group_name = 'group_blocks';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'category';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Blocs',
    'weight' => '6',
    'children' => array(
      0 => 'field_blocks_zone1',
      1 => 'field_blocks_zone2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blocks|taxonomy_term|category|form'] = $field_group;

  return $export;
}
