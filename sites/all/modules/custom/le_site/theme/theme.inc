<?php
/**
 * @file
 * Process function for templates of theming.
 */

/**
 * Process variables for search form on page of search results.
 */
function geopolis_site_preprocess_search_form_on_search_page(&$vars) {
  unset($vars['form']['search_block_form']['#theme_wrappers']);
  unset($vars['form']['search_block_form']['#attributes']['class']);
  $vars['form']['search_block_form']['#value'] = arg(2);
}

/**
 * Process variables for ajouter_reference_dialog_buttons.
 */
function le_site_preprocess_ajouter_reference_dialog_buttons(&$vars) {
  $attached = references_dialog_attached();
  $link_settings = array(
    'image' => 'Ajouter une Image',
    'video' => 'Ajouter une Vidéo',
    'diaporama' => 'Ajouter un Diaporama',
    'free-html' => 'Ajouter une Carte',
    'audio' => 'Ajouter un Son',
    'document' => 'Ajouter un Document',
  );
  $count = 0;
  $links = '';
  foreach ($link_settings as $asset_type => $link_text) {
    $links .= '<li class="' . ++$count
      . '"><a class="add-dialog references-dialog-activate" href="'
      . url('admin/content/assets/add/', array('absolute' => TRUE))
      . $asset_type . '">' . $link_text . '</a></li>';
  }
  $vars['links'] = '<div class="dialog-links wysiwyg-ajouter-buttons"><ul class="references-dialog-links">'
    . $links . '</ul></div>';

  drupal_add_js(
    array(
      'ReferencesDialog' => array(
        'fields' => array(
          'wysiwyg-ajouter-buttons' => array(
            'format' => '$label',
          ),
        ),
      ),
    ),
    'setting'
  );
  drupal_add_js($attached['js'][0]);
  drupal_add_css($attached['css'][0]);
  drupal_add_library('system', 'ui.dialog');
}

/**
 * Process variables for search form on page of search results.
 */
function geopolis_site_preprocess_admin_dashboard_link(&$vars) {
  $link = '<span class="admin-dashboard-link">&nbsp;</span>';
  $vars['dashboard_link'] = l(
    $link,
    'admin/dashboard',
    array(
      'html' => TRUE,
    )
  );
}
