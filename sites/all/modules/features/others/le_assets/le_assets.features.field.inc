<?php
/**
 * @file
 * le_assets.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function le_assets_field_default_fields() {
  $fields = array();

  // Exported field: 'asset-free_html-field_asset_description'.
  $fields['asset-free_html-field_asset_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_description',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'free_html',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'bloc_de_liste' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'bloc_mise_en_avant' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'block' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'carrousel' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'choose_video' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'diaporama_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'map_height' => '420',
            'map_width' => '510',
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'premium_diaporama' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'taxonomy_evenement' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'taxonomy_institution' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'taxonomy_personality' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_description',
      'label' => 'HTML libre',
      'required' => 1,
      'settings' => array(
        'preferred_formats' => array(
          'full_html_noeditor' => 'full_html_noeditor',
        ),
        'preferred_formats_by_role' => array(
          'filtered_html' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
          'filtered_html_a_' => array(
            1 => 0,
            2 => 0,
            3 => 0,
            4 => 0,
            5 => 0,
            6 => 0,
          ),
          'full_html' => array(
            3 => 0,
            4 => 0,
            5 => 0,
            6 => 0,
          ),
          'full_html_noeditor' => array(
            3 => 0,
          ),
          'php_code' => array(
            3 => 0,
          ),
          'plain_text' => array(
            1 => 0,
            2 => 0,
            3 => 0,
            4 => 0,
            5 => 0,
            6 => 0,
            7 => 0,
          ),
        ),
        'preferred_formats_type' => 'global',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'asset-free_html-field_asset_html'.
  $fields['asset-free_html-field_asset_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_html',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'free_html',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_html',
      'label' => 'HTML',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '6',
        ),
        'type' => 'text_textarea',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'asset-gallery-field_asset_description'.
  $fields['asset-gallery-field_asset_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_description',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'gallery',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_description',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'preferred_formats' => array(
          'filtered_html' => 'filtered_html',
        ),
        'preferred_formats_by_role' => array(
          'filtered_html' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
          'full_html' => array(
            3 => 0,
          ),
          'plain_text' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
        ),
        'preferred_formats_type' => 'global',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'asset-gallery-field_asset_diaporama'.
  $fields['asset-gallery-field_asset_diaporama'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_diaporama',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'image' => 'image',
          ),
        ),
        'target_type' => 'asset',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'gallery',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_diaporama',
      'label' => 'Médias',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'path' => '',
          'references_dialog_add' => 1,
          'references_dialog_delete' => 0,
          'references_dialog_edit' => 1,
          'references_dialog_search' => 1,
          'references_dialog_search_view' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'asset-gallery-field_asset_premium'.
  $fields['asset-gallery-field_asset_premium'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_premium',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => 'Premium',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'gallery',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_premium',
      'label' => 'Premium',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_onoff',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'asset-image-field_asset_description'.
  $fields['asset-image-field_asset_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_description',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'gallery' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_description',
      'label' => 'Légende',
      'required' => 0,
      'settings' => array(
        'preferred_formats' => array(
          'filtered_html' => 'filtered_html',
        ),
        'preferred_formats_by_role' => array(
          'filtered_html' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
          'full_html' => array(
            3 => 0,
          ),
          'plain_text' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
        ),
        'preferred_formats_type' => 'global',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '60',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'asset-image-field_asset_free_crop'.
  $fields['asset-image-field_asset_free_crop'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_free_crop',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Free crop' => 'Free crop',
          '16x9' => '16x9',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => array(
        0 => array(
          'value' => 'Free crop',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'gallery' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_free_crop',
      'label' => 'Cropping',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'asset-image-field_asset_image'.
  $fields['asset-image-field_asset_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'imagefield_crop',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'imagefield_crop',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'asset_list_preview',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'asset_image_full',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'gallery' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'related_articles',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'asset_image_tooltip',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_image',
      'label' => 'L’image',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'assets/images/[current-date:custom:Y]/[current-date:custom:m]',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2MB',
        'max_resolution' => '2000x2000',
        'min_resolution' => '250x250',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'imagefield_crop',
        'settings' => array(
          'collapsible' => '2',
          'croparea' => '320x240',
          'custom_ratio' => '',
          'enforce_minimum' => 1,
          'enforce_ratio' => 1,
          'gif_processing' => 'convert',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
          'resolution' => '100x100',
          'select_maximum_area' => 1,
          'validate_resolution' => 0,
        ),
        'type' => 'imagefield_crop_widget',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'asset-image-field_asset_image_copyright'.
  $fields['asset-image-field_asset_image_copyright'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_image_copyright',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'gallery' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'small' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_image_copyright',
      'label' => 'Copyright',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'asset-poll-field_poll'.
  $fields['asset-poll-field_poll'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_poll',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'poll' => 'poll',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'poll',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 0,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '0',
        ),
        'video_article' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_poll',
      'label' => 'Poll',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'path' => '',
          'references_dialog_add' => 0,
          'references_dialog_delete' => 0,
          'references_dialog_edit' => 0,
          'references_dialog_search' => 0,
          'references_dialog_search_view' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'asset-video-field_asset_video'.
  $fields['asset-video-field_asset_video'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_asset_video',
      'foreign keys' => array(),
      'indexes' => array(
        'provider' => array(
          0 => 'provider',
        ),
        'source' => array(
          0 => 'source',
        ),
        'url' => array(
          0 => 'url',
        ),
      ),
      'locked' => '0',
      'module' => 'emvideo',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'emvideo',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'dashboard_article_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'emvideo',
          'settings' => array(
            'height' => 360,
            'width' => 640,
          ),
          'type' => 'emvideo_video',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'in_body' => array(
          'label' => 'hidden',
          'module' => 'emvideo',
          'settings' => array(
            'height' => '322',
            'width' => '585',
          ),
          'type' => 'emvideo_video',
          'weight' => '0',
        ),
        'related_articles' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'tooltip' => array(
          'label' => 'hidden',
          'module' => 'emvideo',
          'settings' => array(
            'height' => '322',
            'width' => '585',
          ),
          'type' => 'emvideo_video',
          'weight' => '0',
        ),
        'video_article' => array(
          'label' => 'hidden',
          'module' => 'emvideo',
          'settings' => array(
            'height' => '322',
            'width' => '585',
          ),
          'type' => 'emvideo_video',
          'weight' => '0',
        ),
        'widget_search' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'asset',
      'field_name' => 'field_asset_video',
      'label' => 'La vidéo',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'emvideo',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'emvideo_text',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Copyright');
  t('Cropping');
  t('Description');
  t('HTML');
  t('HTML libre');
  t('La vidéo');
  t('Légende');
  t('L’image');
  t('Médias');
  t('Poll');
  t('Premium');

  return $fields;
}
