<?php
/**
 * @file
 * Geopolis site form logic.
 */

/**
 * Implements hook_form_alter().
 */
function le_site_form_alter(&$form, &$form_state, $form_id) {

  // Switch by form id.
  switch ($form_id) {

    case 'poll_node_form':
      $form['actions']['preview']['#access'] = FALSE;
      $form['options']['status']['#access'] = FALSE;
      $form['settings']['#access'] = FALSE;
      break;

    case 'asset_edit_poll_form':
      // Redirect from asset poll to node poll.
      $field_lang = $form['field_poll']['#language'];
      $asset = $form['field_poll'][$field_lang][0]['target_id']['#entity'];
      $poll_nid = field_get_items('asset', $asset, 'field_poll');

      // Edit asset.
      if (!empty($poll_nid[0]['target_id'])) {
        // Don't miss get params.
        if (!empty($_GET['render']) && $_GET['render'] === 'references-dialog') {
          drupal_goto(
            'node/' . $poll_nid[0]['target_id'] . '/edit',
            array('query' => array('render' => $_GET['render']))
          );
        }
        else {
          unset($_GET['destination']);
          drupal_goto('node/' . $poll_nid[0]['target_id'] . '/edit');
        }
      }
      // Create asset
      else {
        // Don't miss get params.
        if (!empty($_GET['render']) && $_GET['render'] === 'references-dialog') {
          drupal_goto(
            'node/add/poll',
            array('query' => array('render' => $_GET['render']))
          );
        }
        else {
          unset($_GET['destination']);
          drupal_goto('node/add/poll');
        }
      }
      break;

    case 'taxonomy_form_term':
      $form['name']['#title'] = t('Title');
      $form['name']['#maxlength'] = 120;
      $form['name']['#maxlength_js'] = TRUE;

      $form['description']['#access'] = FALSE;

      if (isset($form['field_category_articles'])) {
        array_unshift($form['#validate'], 'le_site_taxonomy_term_category_four_required_articles_validate');
      }
      break;

    case 'views_exposed_form':
      $destination = drupal_get_destination();
      if (isset($_GET['render']) && $_GET['render'] == 'popup') {
        $destination = drupal_parse_url($destination['destination']);
        $form_state['redirect'] = array(
          'path' => $destination['path'],
          'options' => array(
            'query' => array('render' => 'popup'),
            'fragment' => $destination['fragment'],
          ),
        );
        $form['render'] = array(
          '#type' => 'hidden',
          '#value' => 'popup',
        );
      }
      else {
        // Fix reset filters button.
        $form['#action'] = base_path() . $destination['destination'];
      }

      // Fix problem with validation for reset button.
      $key = array_search('views_exposed_form_validate', $form['#validate']);
      if ($key !== FALSE) {
        $form['#validate'][$key] = 'le_site_views_exposed_form_validate';
      }
      break;

    case 'bean_form':
      $form['title']['#prefix'] = '<div class="hide">';
      $form['title']['#suffix'] = '</div>';

      $form['#validate'][] = 'le_site_bean_validate';
      $form['view_mode']['#required'] = FALSE;

      $form['view_mode']['#prefix'] = '<div class="hide">';
      $form['view_mode']['#suffix'] = '</div>';

      // Hide system fields.
      if (!empty($form['revision'])) {
        $form['revision']['#prefix'] = '<div class="hide">';
        $form['revision']['#suffix'] = '</div>';
      }

      $form['actions']['submit']['#submit'][] = 'le_site_add_redirect_submit';
      break;

    case 'search_block_form':
      $form['search_block_form']['#default_value'] = t('Taper votre recherche ...');
      $form['search_block_form']['#title_display'] = 'none';
      $form['actions']['submit']['#attributes']['class'] = array('btn-submit');
      $form['actions']['submit']['#value'] = t('Search');
      $form['actions']['submit']['#suffix'] = '<a href="#" class="close-search-panel">' . t('close') . '</a>';

      unset($form['#submit']);
      $form['#submit'][] = 'le_site_search_box_form_submit';
      break;
  }
}

/**
 * Check that for taxonomy term "category" have four articles in field field_category_articles.
 */
function le_site_taxonomy_term_category_four_required_articles_validate($form, &$form_state) {
  $field_lang = $form['field_category_articles']['#language'];
  foreach ($form_state['values']['field_category_articles'][$field_lang] as $item) {
    if (empty($item['target_id'])) {
      form_set_error('field_category_articles', t('You should fill all four fields Mise en avant'));
    }
  }
}

/**
 * Custom validation for views exposed form.
 */
function le_site_views_exposed_form_validate($form, &$form_state) {
  if ($form_state['clicked_button']['#id'] != 'edit-reset') {
    views_exposed_form_validate($form, $form_state);
  }
  else {
    drupal_goto($_GET['q']);
  }
}

/**
 * Bean blocs validate.
 */
function le_site_bean_validate($form_id, $form_values) {
  $form_values['values']['view_mode'] = 'default';
}

/**
 * Add redirect when node is saved.
 */
function le_site_add_redirect_submit($form, &$form_state) {
  unset($_GET['destination']);

  if ($form['form_id']['#value'] == 'bean_form') {
    $form_state['redirect'] = 'admin/dashboard/blocks';
  }

  // Manage redirects.
  /*switch ($form['type']['#value']) {
    case 'article':
      $form_state['redirect'] = 'node/' . $form_state['node']->nid;
      break;

    case 'review':
      $form_state['redirect'] = 'admin/dashboard/reviews';
      break;

    case 'page':
      $form_state['redirect'] = 'node/' . $form_state['node']->nid;
      break;
  }*/
}

/**
 * Process a block search form submission.
 */
function le_site_search_box_form_submit($form, &$form_state) {

  if (isset($_GET['destination'])) {
    unset($_GET['destination']);
  }

  if ($form_state['values']['search_block_form'] == '') {
    form_set_error('keys', t('Please enter some keywords.'));
  }

  $form_id = $form['form_id']['#value'];
  $form_state['redirect'] = 'search/content/' . trim($form_state['values'][$form_id]);
}

































/**
 * Implements hook_form_alter().
 */
function geopolis_site_form_alter(&$form, &$form_state, $form_id) {

  global $user;

  // Add title validation.
  array_unshift($form['#validate'], 'le_site_entity_title_validate');

  $form['#after_build'][] = 'le_site_metatag_form_after_build';
  if ($form_id == 'user_login') {
    $form['#submit'][] = 'le_site_redirect_after_login';
  }
  // Specific case for all content types forms.
  if (preg_match('/.*_node_form$/', $form_id)) {
    $form['#after_build'][] = 'le_site_permissions_form_after_build';
    if (!empty($form['comment_settings']) && !user_access('administer comments')) {
      $form['comment_settings']['#type'] = 'hidden';
    }

    $form['#after_build'][] = 'le_site_form_after_build';
    $form['#validate'][] = 'le_site_url_validate';

    if ($form_id == 'article_node_form') {
      $form['field_article_media'][LANGUAGE_NONE][0]['target_id']['#show_preview'] = 1;
      $form['field_article_main_media'][LANGUAGE_NONE][0]['target_id']['#show_preview'] = 1;
      if (empty($form['field_signature'][LANGUAGE_NONE][0]['target_id']['#default_value'])) {
        $form['field_signature'][LANGUAGE_NONE][0]['target_id']['#default_value'] = $user->name;
      }
    }

    $form['actions']['cancel']['#access'] = FALSE;
    $form['actions']['submit']['#weight'] = 1;

//    $form['actions']['preview'] = array(
//      '#type' => 'submit',
//      '#value' => t('Preview'),
//      '#weight' => 11,
//      '#submit' => array('node_form_submit', 'le_site_add_redirect_submit'),
//    );


    if ($form_id == 'feed_item_node_form' || $form_id == 'feed_node_form') {
      if (!empty($form['actions']['save_and_publish'])) {
        unset($form['actions']['save_and_publish']);
      }
      if (!empty($form['actions']['unpublish'])) {
        unset($form['actions']['unpublish']);
      }
      if (!empty($form['actions']['preview'])) {
        unset($form['actions']['preview']);
      }
    }
  }

  else {
    switch ($form_id) {

      case 'asset_edit_diaporama_form':
        $form['#validate'][] = 'le_site_diaporama_form_validate';
        if (!empty($_GET['type']) && $_GET['type'] == 'premium') {
          $form['field_asset_premium'][LANGUAGE_NONE]['#default_value'] = 1;
        }
        if (!empty($form['field_asset_diaporama'][LANGUAGE_NONE])) {
          foreach ($form['field_asset_diaporama'][LANGUAGE_NONE] as &$element) {
            if (!empty($element) && is_array($element)) {
              if (!empty($element['target_id'])) {
                $element['target_id']['#show_preview'] = 1;
              }
            }
          }
        }
        break;

      case 'user_profile_form':
        $form['field_user_name']['#type'] = 'hidden';
        $form['#validate'][] = 'le_site_user_registration_form_validate';
        if (!empty($form['field_user_name'][LANGUAGE_NONE][0])) {
          $form['field_user_name'][LANGUAGE_NONE][0]['value']['#required'] = FALSE;
        }
        break;

      case 'user_register_form':
        $form['account']['notify']['#default_value'] = 1;
        $form['field_user_name']['#type'] = 'hidden';

        if (!empty($form['field_user_name'][LANGUAGE_NONE][0])) {
          $form['field_user_name'][LANGUAGE_NONE][0]['value']['#required'] = FALSE;
        }
        $form['#validate'][] = 'le_site_user_registration_form_validate';
        break;

      case 'asset_edit_image_form':
        $form['title']['#title'] = t("Titre de l'image");
        $form['title']['#maxlength'] = 80;
        $form['title']['#maxlength_js'] = TRUE;

        $form['#after_build'][] = 'le_site_asset_edit_image_form_after_build';
        break;

      case 'term_queue_add_term_form':
        $form['#validate'][] = 'le_site_term_queue_add_term_form_validate';
        break;

      case 'shortcut_link_delete':
        if (!empty($_GET['destination'])) {
          menu_set_active_item($_GET['destination']);
        }
        break;

      case 'term_queue_delete_term_form':
        $path = preg_replace('/\/[0-9]*\/delete/', '', $_GET['q']);
        menu_set_active_item($path);
        break;

      case 'nodequeue_edit_queue_form':
        $qid_map = nodequeue_get_qid_map();
        $qid = (int) $form['qid']['#value'];
        $qid_name = array_search($form['qid']['#value'], $qid_map);
        if ($qid_name == 'article_home') {
          $form['#validate'][] = 'le_site_edit_article_home_nodequeue_validate';
        }
        break;
    }

    if (stristr($form_id, 'nodequeue_arrange_subqueue_form')) {
      if (!empty($form['actions']['reverse'])) {
        unset($form['actions']['reverse']);
      }
      if (!empty($form['actions']['clear'])) {
        unset($form['actions']['clear']);
      }
      if (!empty($form['actions']['shuffle'])) {
        unset($form['actions']['shuffle']);
      }
      if (!empty($form['nodes']['#queue'])) {
        if ($form['nodes']['#queue']['name'] == 'article_home') {
          $form['#validate'][] = 'le_site_edit_article_home_nodequeue_validate';
        }
      }
    }


    if (!empty($form['#entity_type']) && $form['#entity_type'] == 'asset') {
      $form['actions']['delete']['#submit'][0] = 'le_site_asset_base_form_submit_delete';
    }
  }
}

/**
 * Implements hook_element_info_alter().
 *
 * Add #after_builds to widgets that needs them.
 */
function le_site_element_info_alter(&$info) {
  foreach (references_dialog_widgets() as $widget) {
    // If this element type is specified as a type that a widget should be
    // attached to, go ahead and make it so.
    if (!empty($info[$widget['element_type']]) && (!isset($info[$widget['element_type']]['#after_build'])
      || in_array('references_dialog_process_widget', $info[$widget['element_type']]['#after_build']))) {

      if (isset($info[$widget['element_type']]['#after_build'])) {
        foreach ($info[$widget['element_type']]['#after_build'] as $key => $value) {
          if (in_array('references_dialog_process_widget',
            $info[$widget['element_type']]['#after_build'])) {
            unset($info[$widget['element_type']]['#after_build'][$key]);
          }
        }
      }
      $info[$widget['element_type']]['#after_build'][] = 'le_site_references_dialog_process_widget';
    }
  }
  if (isset($info['text_format'])) {
    $info['text_format']['#process'][] = 'le_site_process_format';
  }
}

/**
 * Diaporama form validate.
 */
function le_site_diaporama_form_validate($form_id, $form_values) {
  $count = 0;
  foreach ($form_values['values']['field_asset_diaporama'][LANGUAGE_NONE] as $value) {
    if (is_array($value) && !empty($value['target_id'])) {
      $count++;
    }
  }

  if ($count < 1) {
    form_set_error('field_asset_diaporama', 'Le champ est requis.');
  }
}

/**
 * User registration form validate.
 */
function le_site_user_registration_form_validate($form_id, &$form_values) {
  if (!empty($form_values['values']['field_user_firstname'][LANGUAGE_NONE][0]['value'])
    && !empty($form_values['values']['field_user_lastname'][LANGUAGE_NONE][0]['value'])) {
    $form_values['values']['field_user_name'][LANGUAGE_NONE][0]['value']
      = $form_values['values']['field_user_firstname'][LANGUAGE_NONE][0]['value'] . '.'
      . $form_values['values']['field_user_lastname'][LANGUAGE_NONE][0]['value'];
  }
}

/**
 * Sheduler fields validate.
 */
function le_site_sheduler_fields_validate($form_id, $form_values) {
  // Sheduler additional validation.
  if (!empty($form_values['values']['publish_on']['date'])
    || !empty($form_values['values']['publish_on']['time'])) {

    $label = t('sheduler form fieldset');

    if (empty($form_values['values']['publish_on']['date'])) {
      form_set_error('publish_on', t('The date value input for field %field is empty:', array('%field' => $label)));
    }
    elseif (empty($form_values['values']['publish_on']['time'])) {
      form_set_error('publish_on', t('The time value input for field %field is empty:', array('%field' => $label)));
    }
  }
}

/**
 * Validate url.
 */
function le_site_url_validate($form_id, $form_values) {
  if (!empty($form_values['values']['field_read_more_external'][LANGUAGE_NONE])) {
    $delta = 0;
    foreach ($form_values['values']['field_read_more_external'][LANGUAGE_NONE] as $row) {
      if (!empty($row['url'])) {
        $valid_url = valid_url($row['url'], TRUE);
        if (!$valid_url) {
          form_set_error(
            'field_read_more_external][' . LANGUAGE_NONE . '][' . $delta . '][url',
            t('Url has wrong format. External url must be absolute. Example: http://francetv.fr')
          );
        }
      }
      $delta++;
    }
  }
}

/**
 * Form API submit callback for the delete button.
 */
function le_site_asset_base_form_submit_delete(&$form, &$form_state) {

  $form_state['redirect'] = array(
    'admin/content/assets/manage/' . $form_state['asset']->aid . '/delete',
    array('query' => array('destination' => $_GET['destination'])));
  unset($_GET['destination']);
}

/**
 * Fork ckeditor pre_render.
 */
function le_site_ckeditor_pre_render_text_format($element) {
  static $init = FALSE;
  if (!isset($element['#format'])) {
    return $element;
  }

  module_load_include('inc', 'ckeditor', 'includes/ckeditor.lib');
  if ($init === FALSE) {
    $input_formats = ckeditor_profiles_compile();
    drupal_add_js(array('ckeditor' => array('input_formats' => $input_formats, 'plugins' => array())), 'setting');
    $init = TRUE;
  }

  if (isset($element['value'])) {
    if (isset($element['summary'])) {
      $element['value'] = ckeditor_load_by_field($element['value'], $element['format']['format'], TRUE, $element['summary']['#id']);
      $element['summary'] = ckeditor_load_by_field($element['summary'], $element['format']['format'], FALSE);
    }
    else {
      $element['value'] = ckeditor_load_by_field($element['value'], $element['format']['format']);
    }
  }
  else {
    $element = ckeditor_load_by_field($element, $element['#format']);
  }

  if (!empty($element['value']['#suffix'])) {
    $element['value']['#suffix']
      = preg_replace('/<a.*class="ckeditor_links".*>.*<\/a>/', '', $element['value']['#suffix']);
  }
  return $element;
}

/**
 * le_site_form_after_build.
 */
function le_site_permissions_form_after_build($form, &$form_state) {
  if (!empty($form['field_body'][LANGUAGE_NONE][0]['format'])
    && !user_access('access edit article corps text format')) {
    $form['field_body'][LANGUAGE_NONE][0]['format']['#access'] = FALSE;
  }
  if (!user_access('access toggle ckeditor text format')
    && ($key = array_search(
      'ckeditor_pre_render_text_format',
      $form['field_body'][LANGUAGE_NONE][0]['#pre_render'])
    ) !== FALSE) {
    $form['field_body'][LANGUAGE_NONE][0]['#pre_render'][$key]
      = 'le_site_ckeditor_pre_render_text_format';
  }
  return $form;
}

/**
 * le_site_form_after_build.
 */
function le_site_metatag_form_after_build($form, &$form_state) {
  if (isset($form['metatags']['title'])) {
    $form['metatags']['title']['#type'] = 'hidden';
  }

  return $form;
}

/**
 * le_site_form_after_build.
 */
function le_site_form_after_build($form, &$form_state) {
  array_unshift(
    $form['scheduler_settings']['publish_on']['#element_validate'],
    'le_site_sheduler_fields_validate'
  );
  return $form;
}

/**
 * Element process function.
 */
function le_site_process_format($element) {
  if (isset($element['#entity_type']) && isset($element['#field_name']) && isset($element['#bundle'])) {
    if ($element['#field_name'] == 'field_body' && $element['#bundle'] == 'article') {
      if (isset($element['format']['format']['#options']['full_html'])) {
        $element['format']['format']['#default_value'] = 'full_html';
      }
    }
  }
  return $element;
}

/**
 * After build function for asset image edit form.
 */
function le_site_asset_edit_image_form_after_build($form) {
  unset($form['field_asset_image'][LANGUAGE_NONE][0]['#description']);
  if (empty($form['field_asset_image'][LANGUAGE_NONE][0]['#value']['fid'])) {
    $form['field_asset_image'][LANGUAGE_NONE][0]['#description'] = t('Les fichiers doivent peser moins de 2 Mo.
    Extensions autorisées : png gif jpg jpeg. Les images doivent faire entre 250x250 et 2000x2000 pixels');
  }
  $form['title']['#description'] = '';
  return $form;
}

/**
 * Custom validation for access article_home nodequeue moderation.
 */
function le_site_edit_article_home_nodequeue_validate($form, &$form_state) {
  if (!user_access('access edit article_home nodequeue')) {
    form_set_error('', t("Sorry, you haven't access to edit this nodequeue."));
  }
}

/**
 * Custom validation for term queue add term form.
 */
function le_site_term_queue_add_term_form_validate($form, &$form_state) {
  if (empty($form_state['values']['tid'])) {
    form_error($form['tid'], t('Field term is empty.'));
  }

  if (is_autocomplete()) {
    preg_match("/tid:\d+/", $form_state['values']['tid'], $matches);
    $tid_array = explode(":", $matches[0]);
    $tid = $tid_array[1];
  }
  else {
    $tid = $form_state['values']['tid'];
  }
  if (empty($tid)) {
    form_error($form['tid'], t('This term does not exist.'));
  }
  $qid = $form_state['values']['qid'];
  $terms = term_queue_get_terms($form_state['values']['qid']);
  if (!empty($terms)) {
    foreach ($terms as $term) {
      if ($term->tid == $tid) {
        $queue = term_queue_load(term_queue_machine_name($qid));
        form_error($form['tid'], t('This term already in :queue.', array(':queue' => $queue->title)));
      }
    }
  }
}

/**
 * Add redirect when user is logged in.
 */
function le_site_redirect_after_login($form, &$form_state) {

  if (user_access('access dashboard homepage')) {
    $form_state['redirect'] = 'admin/dashboard';
  }
}

/**
 * Remove redirect when node is saved.
 */
/*function le_site_remove_redirect_submit($form, &$form_state) {
  unset($_GET['destination']);
  $form_state['redirect'] = 'node/' . $form_state['node']->nid . '/edit';
}*/


/**
 * Add our references dialog fields to the existing element.
 */
function le_site_references_dialog_process_widget(&$element) {
  if (!isset($element['#entity_type'])) {
    return $element;
  }
  $field = field_info_field($element['#field_name']);
  $instance = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);

  $widget_settings = $instance['widget']['settings'];
  $widget_type = $instance['widget']['type'];
  $widgets = references_dialog_widgets();
  // Bail if we don't have anything to do here.
  if (!in_array($widget_type, array_keys($widgets))) {
    return $element;
  }
  $dialog_widget = references_dialog_widget_load($widget_type);
  // Attach javascript and CSS needed.
  $attached = references_dialog_attached();
  $element['#attached']['js'][] = $attached['js'][0];
  $element['#attached']['js'][] = references_dialog_js_settings($element['#id'], array('format' => $dialog_widget['format']));
  $element['#attached']['css'][] = $attached['css'][0];
  $element['#attached']['library'][] = $attached['library'][0];

  $dialog_links = array();
  foreach ($dialog_widget['operations'] as $operation => $settings) {
    if ($operation == 'add') {
      unset($settings['function']);
      $settings['function'] = 'le_site_references_dialog_entityreference_add_link';
    }

    if (isset($widget_settings['references_dialog_' . $operation]) && $widget_settings['references_dialog_' . $operation]) {
      if ($operation == 'edit') {
        $links = le_site_entityreference_edit_link($element, $widget_settings, $field, $instance);
      }
      else {
        $links = $settings['function']($element, $widget_settings, $field, $instance);
      }
      foreach ($links as $link) {
        $link['attributes']['class'][] = $operation . '-dialog';
        $dialog_links[] = references_dialog_link($link);
      }
    }
  }
  if (count($dialog_links)) {
    // We add a div directly into the markup here since we really need it in order
    // to make sure the javascript works.
    $element['#suffix'] = '';
    if (!empty($element['#show_preview'])) {
      // If url is ajax/illustration-preview.
      if (!le_site_is_ajax() || preg_match('/ajax\/illustration-preview', $_SERVER['REQUEST_URI'])) {
        $element['#suffix'] .= le_site_show_entity_preview($element);
      }
    }
    $element['#suffix'] .= '<div class="dialog-links ' . $element['#id'] . '">' . theme('references_dialog_links', $dialog_links) . '</div>';
  }
  return $element;
}

/**
 * Edit link callback for entity references.
 */
function le_site_entityreference_edit_link($element, $widget_settings, $field, $instance) {
  if (isset($element['#default_value'])) {
    $entity_type = $field['settings']['target_type'];
    // Take "label (entity id)', match the id from parenthesis.
    if (preg_match("/.+\((\d+)\)/", $element['#default_value'], $matches)) {
      $value = $matches[1];
    }
    if (isset($value)) {
      $entity = current(entity_load($entity_type, array($value)));
      if (entity_access('update', $entity_type, $entity)) {
        return array(
          array(
            'title' => t('Edit'),
            'href' => references_dialog_get_admin_path($entity_type, 'edit', NULL, $entity),
          ),
        );
      }
    }
  }
  // If default value is empty, render hidden link, to later render with JS.
  return array(
    array(
      'title' => t('Edit'),
      'href' => '',
      'attributes' => array('style' => 'display:none'),
    ),
  );
}

/**
 * Add link callback for entity references.
 */
function le_site_references_dialog_entityreference_add_link($element, $widget_settings, $field, $instance) {
  $add_links = array();
  $entity_type = $field['settings']['target_type'];
  $entity_info = entity_get_info($entity_type);
  $entity_bundles = array_keys($entity_info['bundles']);
  if (!empty($field['settings']['handler_settings']['target_bundles'])) {
    $bundles = $field['settings']['handler_settings']['target_bundles'];
  }
  elseif (isset($entity_info['bundles'])) {
    // If the entity target bundles is empty, it means all target bundles are allowed. Fill it all up!
    $bundles = $entity_bundles;
  }
  // Create a link for each allowed bundles.
  if (isset($bundles)) {
    foreach ($bundles as $bundle) {
      if (in_array($bundle, $entity_bundles) && $link = le_site_references_dialog_entityreference_link_helper($entity_type, $bundle)) {
        $add_links[] = $link;
      }
    }
  }
  return $add_links;
}

/**
 * Change link build function.
 */
function le_site_references_dialog_entityreference_link_helper($entity_type, $bundle = NULL) {
  $wrapper = entity_metadata_wrapper($entity_type, NULL, array('bundle' => $bundle));
  $info = $wrapper->entityInfo();
  if (isset($bundle)) {
    $label = $info['bundles'][$bundle]['label'];
  }
  else {
    $label = $info['label'];
  }
  // We use entity_access here. We provide the bundle if this is a node type,
  // since node_access expects that to be passed to it as the entity when you
  // run node_access('create')
  if (entity_access('create', $entity_type, $entity_type == 'node' ? $bundle : NULL) &&
    $path = references_dialog_get_admin_path($entity_type, 'add', $bundle)) {
    $link = array(
      'title' => le_site_create_link_title_by_type($label),
      'href' => $path,
    );
    return $link;
  }
  return FALSE;
}

/**
 * Create link title by type.
 */
function le_site_create_link_title_by_type($label) {
  $une_article = array(
    'personnalité',
    'thématique',
    'institution',
    'image',
    'video',
    'vidéo',
    'carte',
  );
  if (in_array(drupal_strtolower($label), $une_article)) {
    return t('Ajouter une @type', array('@type' => $label));
  }

  return t('Ajouter un @type', array('@type' => $label));
}

/**
 * Return HTML for render preview of entity in reference dialog.
 */
function le_site_get_asset_image_preview($title) {
  $content = '';
  if (preg_match("/.+\((\d+)\)/", $title, $matches)) {
    $content = views_embed_view('le_assets_library', 'asset_preview', $matches[1]);
  }

  if (le_site_is_ajax()) {
    print $content;
    drupal_exit();
  }
  else {
    return $content;
  }
}

/**
 * Return HTML for render preview of entity in reference dialog.
 */
function le_site_show_entity_preview($element) {
  $content = !empty($element['#default_value']) ? le_site_get_asset_image_preview($element['#default_value'], FALSE) : '';
  return '<div id="div-' . $element['#id'] . '">' . $content . '</div>';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function le_site_form_system_site_information_settings_alter(&$form, &$form_state, $form_id) {
  if (user_access('manage janrain and disqus disabling')) {
    $form['manage_janrain_disqus'] = array(
      '#type' => 'fieldset',
      '#title' => t('Manage janrain and disqus disabling'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['manage_janrain_disqus']['disable_disqus'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable disqus'),
      '#default_value' => variable_get('le_site_disqus_disabled', FALSE),
    );

    $form['manage_janrain_disqus']['disable_janrain'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable janrain'),
      '#default_value' => variable_get('le_site_janrain_disabled', FALSE),
    );

    $form['le_facebook_app_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Facebook application ID'),
      '#default_value' => variable_get('le_facebook_app_id', '372858999446772'),
    );

    $form['#submit'][] = 'le_site_system_site_information_settings_form_submit';
  }
}

/**
 * Form submit handler.
 */
/*function le_site_system_site_information_settings_form_submit($form, &$form_state) {
  if ($form_state['values']['disable_disqus']) {
    variable_set('le_site_disqus_disabled', TRUE);
  }
  else {
    variable_set('le_site_disqus_disabled', FALSE);
  }

  if ($form_state['values']['disable_janrain']) {
    variable_set('le_site_janrain_disabled', TRUE);
  }
  else {
    variable_set('le_site_janrain_disabled', FALSE);
  }
}*/
