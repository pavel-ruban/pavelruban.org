<?php
/**
 * @file
 * Ctools CT plugin for render buttons on taxonomy dashboard.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Buttons for taxonomy dashboard.'),
  'description' => t('Buttons for add terms into taxonomy vocabularies.'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_taxonomy_dashboard_buttons_theme',
);

/**
 * Render the custom content type.
 */
function le_site_taxonomy_dashboard_buttons_content_type_render($subtype, $conf, $panel_args, $context) {
  if ($vocabularies = taxonomy_get_vocabularies()) {
    $links = '';

    foreach ($vocabularies as $voc) {
      if ($voc->machine_name == 'language') {
        continue;
      }

      $title = t(
        'Créer @art @name',
        array('@name' => drupal_strtolower($voc->name), '@art' => ($voc->machine_name == 'event') ? t('un') : ('une'))
      );
      $links .= le_site_l(
        $title,
        "admin/structure/taxonomy/$voc->machine_name/add",
        array(
          'attributes' => array(
            'title' => $title,
            'class' => 'le-add-node',
          ),
        )
      );
    }
  }

  $block = new stdClass();
  $block->content = theme('le_site_taxonomy_dashboard_buttons', array('links' => $links));
  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_taxonomy_dashboard_buttons_theme(&$theme, $plugin) {
  $theme['le_site_taxonomy_dashboard_buttons'] = array(
    'variables' => array(
      'links' => NULL,
    ),
    'path'      => $plugin['path'],
    'template'  => 'taxonomy-dashboard-buttons',
  );
}
