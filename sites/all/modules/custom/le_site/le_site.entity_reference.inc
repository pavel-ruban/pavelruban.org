<?php

/**
 * @file
 * This file provide functions for work with entity reference module.
 */

/**
 * Fork of entityreference_autocomplete_callback().
 */
/*function geopolis_site_entityreference_autocomplete_callback($type, $field_name, $entity_type, $bundle_name, $entity_id = '', $string = '') {
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);
  $matches = array();

  if (!$field || !$instance || $field['type'] != 'entityreference' || !field_access('edit', $field, $entity_type)) {
    return MENU_ACCESS_DENIED;
  }

  $entity = NULL;
  if ($entity_id !== 'NULL') {
    $entity = entity_load_single($entity_type, $entity_id);
    if (!$entity || !entity_access('view', $entity_type, $entity)) {
      return MENU_ACCESS_DENIED;
    }
  }
  $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

  if ($type == 'tags') {
    // The user enters a comma-separated list of tags. We only autocomplete the last tag.
    $tags_typed = drupal_explode_tags($string);
    $tag_last = drupal_strtolower(array_pop($tags_typed));
    if (!empty($tag_last)) {
      $prefix = count($tags_typed) ? implode(', ', $tags_typed) . ', ' : '';
    }
  }
  else {
    // The user enters a single tag.
    $prefix = '';
    $tag_last = $string;
  }

  if (!empty($tag_last)) {
    // Get an array of matching entities.
    $entity_labels = $handler->getReferencableEntities($tag_last, $instance['widget']['settings']['match_operator'], 10);

    // Loop through the products and convert them into autocomplete output.
    foreach ($entity_labels as $entity_id => $label) {
      $key = "$label ($entity_id)";
      if (strpos($key, ',') !== FALSE || strpos($key, '"') !== FALSE) {
        $key = '"' . str_replace('"', '""', $key) . '"';
      }
      // Strip things like starting/trailing white spaces, line breaks and tags.
      $key = preg_replace('/\s\s+/', ' ', str_replace("\n", '', trim(decode_entities(strip_tags($key)))));
      $matches[$prefix . $key] = '<div class="reference-autocomplete">' . $label . '</div>';
    }
  }

  drupal_json_output($matches);
}*/

/**
 * Add validation for title.
 */
/*function geopolis_site_entity_title_validate(&$form, &$form_state) {

  if (strpos($form['#form_id'], 'views') !== FALSE) {
    return;
  }
  $form_state['values']['title'] = drupal_ucfirst($form_state['values']['title']);
  if (!empty($form['#entity_type']) && !empty($form_state['values']['title'])) {
    $entity = entity_load($form['#entity_type'], FALSE, array('title' => $form_state['values']['title']));
  }

  if (!empty($entity)) {
    $entity = array_shift($entity);
    // If we add new content compare just title, elsewhere check that's another entity.
    $form_entity = (!empty($form['#entity'])) ? $form['#entity'] : $form['#node'];
    if (empty($form['#entity']) && empty($form['#node'])
      || entity_id($form['#entity_type'], $entity) != entity_id($form['#entity_type'], $form_entity)) {
      form_set_error(
        'title',
        t(
          '@type with the same name already exists. Use a different name.',
          array('@type' => drupal_ucfirst($form['#entity_type']))
        )
      );
    }
  }
}*/

/**
 * Delete link callback for entity references.
 */
function le_site_references_dialog_entityreference_delete_link(&$element, $widget_settings, $field, $instance) {
  $element['#attached']['js'][LE_SITE_MODULE_PATH . '/js/geopolis_site-delete-reference.js'] = array('weight' => 100);
  $element['#attached']['css'][] = LE_SITE_MODULE_PATH . '/css/geopolis_site.css';
  return array(
    array(
      'title' => t('Remove'),
      'href' => '',
    ),
  );
}

/**
 * Page callback for our redirect page.
 */
function le_site_references_dialog_redirect_page($entity_id, $entity_type) {
  // Get some information about the entity we are dealing with.
  $entity = entity_load($entity_type, array($entity_id));
  $entity = reset($entity);
  $entity_info = entity_get_info($entity_type);
  $entity_id = $entity->{$entity_info['entity keys']['id']};
  $entity_title = entity_label($entity_type, $entity);

  if ($entity->type === 'poll') {
    $aid = db_query(
      "SELECT entity_id FROM {field_data_field_poll}
        WHERE field_poll_target_id = :nid AND entity_type = 'asset'",
      array(':nid' => $entity_id)
    )->fetchField();
    if (!empty($aid)) {
      $asset = asset_load($aid);
      if (!empty($asset)) {
        $entity_type = 'asset';
        $entity_title = entity_label($entity_type, $asset);
        $entity_id = $aid;
      }
    }
  }

  // Add appropriate javascript that will be used by the parent page to
  // fill in the required data.
  if (isset($entity_id) && references_dialog_in_dialog() && isset($_GET['references-dialog-close'])) {
    drupal_add_js(drupal_get_path('module', 'references_dialog') . '/js/references-dialog-child.js');
    drupal_add_js(array(
      'ReferencesDialog' => array(
        'entity_id' => $entity_id,
        'title' => $entity_title,
        'entity_type' => $entity_type,
      ),
    ), 'setting');
  }
  return '';
}
