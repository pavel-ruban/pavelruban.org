<?php
/**
 * @file
 * Render logic and theme hooks for Le360 front theme.
 */

define('LE_THEME_PATH', drupal_get_path('theme', 'le'));
define('LE_THEME_TIME_FORMAT', 'H\hi');
require_once LE_THEME_PATH . '/includes/css.inc';
require_once LE_THEME_PATH . '/includes/nodes.inc';
require_once LE_THEME_PATH . '/includes/pager.inc';
require_once LE_THEME_PATH . '/theme/theme.inc';

/**
 * Implements hook_theme().
 */
function le_theme() {
  return array(
    'le_share_links' => array(
      'template' => 'le-share-links',
      'path' => LE_THEME_PATH . '/templates/common',
      'variables' => array('mode' => 'top', 'data' => NULL),
    ),
    'item_pager_list' => array(
      'variables' => array('items' => array(), 'title' => NULL, 'type' => 'ul', 'attributes' => array()),
    ),
  );
}

/**
 * Add body classes if certain regions have content.
 */
function le_preprocess_html(&$variables) {
  $variables['classes_array'] = array();
}

/**
 * Process variables for views-view.tpl.php.
 */
function le_preprocess_views_view(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'le_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-unformatted.tpl.php.
 */
function le_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'le_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Default preprocess for views-view-fields.
 */
function le_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'le_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Override or insert variables into the taxonomy term template.
 */
function le_preprocess_taxonomy_term(&$vars, $hook) {
  $vars['name'] = check_plain($vars['name']);
  $view_mode = $vars['view_mode'];
  $term = $vars['term'];
  $preprocess[] = 'le_preprocess_taxonomy_term__' . $term->vocabulary_machine_name . '_' . str_replace('-', '_', $view_mode);
  $preprocess[] = 'le_preprocess_taxonomy_term__' . str_replace('-', '_', $view_mode);

  foreach ($preprocess as $function) {
    if (function_exists($function)) {
      $function($vars, $hook);
    }
  }

  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . $term->vocabulary_machine_name . '_' . str_replace('-', '_', $view_mode);
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . str_replace('-', '_', $view_mode);
}

/**
 * Preprocess variables for panels-pane.tpl.php.
 */
function le_preprocess_panels_pane(&$variables) {
  /*if (!empty($variables['pane']->style['style']) && $variables['pane']->style['style'] == 'pane_with_title') {
    $variables['pane_with_title'] = TRUE;
    $variables['classes_array'][] = 'bloc';
  }*/
  // Force preprocess execution for suggestions.
  if (!empty($variables['theme_hook_suggestions'])) {
    foreach ($variables['theme_hook_suggestions'] as $suggestion) {
      $function = 'le_preprocess_' . $suggestion;
      if (function_exists($function)) {
        $function($variables);
      }
    }
  }
}

/**
 * Preprocess variables for node--article-full.tpl.php.
 */
function geopolis_preprocess_node__article_full(&$vars) {


  $read_more_items = field_get_items('node', $node, 'field_read_more');
  $title_long = field_get_items('node', $node, 'field_title_long');
  $title_long = $title_long[0]['safe_value'];

  if (empty($title_long) || (strlen($title_long) < 5)) {
    $title_long = $vars['title'];
  }

  $vars['title'] = $title_long;

  $read_more = array();
  if (!empty($read_more_items)) {
    foreach ($read_more_items as $delta => $item) {
      if (isset($item['entity'])) {
        $label = $item['entity']->title;
        $uri = entity_uri('node', $item['entity']);
        if (empty($uri['options']['attributes']['title'])) {
          $uri['options']['attributes']['title'] = $item['entity']->title;
        }
        $read_more[$delta] = le_site_l($label, $uri['path'], $uri['options']);
      }
    }
  }

  foreach (element_children($vars['content']['field_read_more_external']) as $child) {
    $item = $vars['content']['field_read_more_external'][$child];
    if (!empty($item['#markup'])) {
      $read_more[] = $item['#markup'];
    }
  }
  $vars['read_more'] = $read_more;
  $vars['tags'] = implode(',&nbsp;&nbsp', _geopolis_get_node_terms($node, array(
    'field_places',
    'field_institutions',
    'field_thematics',
  )));

  $vars['share'] = theme('geopolis_share_links', array('node' => $node, 'type' => 'all'));
  if (!empty($vars['content']['field_article_main_media'])) {
    $vars['media_content'] = render($vars['content']['field_article_main_media']);
  }
  elseif (!empty($vars['content']['field_article_media'])) {
    $vars['media_content'] = render($vars['content']['field_article_media']);
  }
}

/**
 * Preprocess variables for any entity.
 */
function le_preprocess_entity(&$vars, $hook) {
  if ('bean' == $vars['elements']['#entity_type']) {
    $bean = $vars['bean'];
    $preprocess = 'le_preprocess_bean__' . $bean->type;

    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }

    switch ($vars['elements']['#bundle']) {
      case 'bloc_mise_en_avant':
        break;
    }
  }
  elseif ('field_collection_item' == $vars['elements']['#entity_type']) {
    $fci = $vars['field_collection_item'];

    $preprocess = 'le_preprocess_field_collection_item__' . $fci->field_name;

    if (function_exists($preprocess)) {
      $preprocess($vars);
    }
  }
  elseif ('asset' == $vars['elements']['#entity_type']) {
    switch ($vars['elements']['#bundle']) {
      // We set description from asset field to image alt and title.
      case 'image':
        break;
    }
  }
}

/**
 * Processes variables for asset-tooltip.tpl.php.
 *
 * @see template_preprocess_overlay()
 * @see asset-tooltip.tpl.php
 */
function le_process_asset_tooltip(&$variables) {
  drupal_add_css(path_to_theme() . '/css/le-asset-tooltip-theme.css');
}

/**
 * Process variables fields.
 */
function le_preprocess_field(&$variables) {
  $element = $variables['element'];

  // Last part is concatenated with one underscore because panels set it
  // to "_custom_display".
  if (isset($element['#view_mode'])) {
    $variables['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__'
      . $element['#bundle'] . '__' . preg_replace('/^_/', '', $element['#view_mode']);
    foreach (array_reverse($variables['theme_hook_suggestions']) as $theme) {
      $function = 'le_preprocess_' . $theme;
      if (function_exists($function)) {
        $function($variables);
        break;
      }
    }
  }
}

/**
 * Process variables for views-view-rss.tpl.php.
 */
function le_preprocess_views_view_rss(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'le_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Returns HTML for a form element.
 */
function le_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-'
      . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  if ($element['#name'] === 'search_block_form') {
    $attributes['class'][] = 'text-form';
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}
