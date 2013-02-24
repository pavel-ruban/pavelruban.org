<?php

/**
 * @file
 * Provides functions for implements drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function geopolis_site_drush_command() {
  $commands = array();
  $commands['geopolis-site-import-locale'] = array(
    'description' => 'Update translations for geopolis.',
  );
  $commands['geopolis-site-create-blogs'] = array(
    'description' => 'Create blogs.',
  );
  return $commands;
}

/**
 * Callback for command geopolis-site-import-locale.
 */
function drush_geopolis_site_import_locale() {
  $filepath = DRUPAL_ROOT . '/profiles/geopolis_dev/translations/fr.tr';

  if (file_exists($filepath)) {
    // Import translations.
    $file = (object) array('filename' => drupal_basename($filepath), 'uri' => $filepath);
    _locale_import_read_po('db-store', $file, LOCALE_IMPORT_OVERWRITE, 'fr');
    drush_log(dt('All translations up to date'), 'status');
    // Set language.
    $current_languages = locale_language_list();
    if (!isset($current_languages['fr'])) {
      locale_add_language('fr', NULL, NULL, LANGUAGE_LTR, '', '', TRUE, TRUE);
      drush_log(dt('French language has been added and is set by default in the system.'), 'status');
    }
    else {
      $languages = language_list();
      variable_set('language_default', $languages['fr']);
      drush_log(dt('French language already was enabled and now has been set by default in the system.'), 'status');
    }
  }
  else {
    drush_log(dt('File @name does not exists.', array('@name' => $filepath)), 'status');
  }
}

/**
 * Create default blogs importers.
 */
function drush_geopolis_site_create_blogs() {
  $blogs = array(
    0 => array(
      'name' => 'Le blog du Bureau de New Delhi',
      'url' => 'http://blog.france2.fr/bureau-inde-france2/feed/',
      'terms' => array('Asie-Pacifique', 'Inde'),
    ),
    1 => array(
      'name' => 'Le blog du Bureau de Bruxelles',
      'url' => 'http://blog.france2.fr/bureau-bruxelles-france2/feed/',
      'terms' => array('Europe', 'Belgique'),
    ),
    2 => array(
      'name' => 'Charles Enderlin',
      'url' => 'http://blog.france2.fr/charles-enderlin/feed/',
      'terms' => array('Moyen-Orient'),
      'terms-childrens-od' => array('Moyen-Orient'),
    ),
    3 => array(
      'name' => 'Le blog du Bureau de Pékin',
      'url' => 'http://blog.france2.fr/bureau-pekin/feed/',
      'terms' => array('Asie-Pacifique', 'Chine'),
    ),
    4 => array(
      'name' => 'Le blog du Bureau de Moscou',
      'url' => 'http://blog.france2.fr/bureau-moscou-russie/feed/',
      'terms' => array('Europe', 'Russie'),
    ),
    5 => array(
      'name' => 'Le blog du Bureau de Washington',
      'url' => 'http://blog.france2.fr/Washington/feed/',
      'terms' => array('Amérique', 'Etats-Unis'),
    ),
    6 => array(
      'name' => 'Le blog du Bureau de Berlin',
      'url' => 'http://blog.france2.fr/bureau-berlin/feed/',
      'terms' => array('Europe', 'Allemagne'),
    ),
    7 => array(
      'name' => 'Le blog du Bureau de Londres',
      'url' => 'http://blog.france2.fr/bureau-londres/feed/',
      'terms' => array('Europe', 'Royaume-Uni'),
    ),
  );

  $voc = taxonomy_vocabulary_machine_name_load('place');

  foreach ($blogs as $blog) {
    $node = new stdClass();
    $node->type = 'feed';

    $node->title = $blog['name'];
    $node->feeds['FeedsHTTPFetcher']['source'] = $blog['url'];
    $node->language = LANGUAGE_NONE;

    // Process terms.
    if (!empty($blog['terms'])) {
      foreach ($blog['terms'] as $term) {
        $t = reset(entity_load('taxonomy_term', array(), array('name' => $term)));
        if (!empty($t)) {
          $node->field_term[LANGUAGE_NONE][] = array('tid' => $t->tid);
        }
      }
    }

    // Process terms childrens.
    if (!empty($blog['terms-childrens-od'])) {
      foreach ($blog['terms-childrens-od'] as $term) {
        $term = reset(entity_load('taxonomy_term', array(), array('name' => $term)));
        $childrens = taxonomy_get_children($term->tid, $voc->vid);
        foreach ($childrens as $child) {
          $node->field_term[LANGUAGE_NONE][] = array('tid' => $child->tid);
        }
      }
    }

    module_load_include('inc', 'node', 'node.pages');
    node_object_prepare($node);

    $node = node_submit($node);

    node_save($node);
  }
}

/**
 * Create taxonomy terms.
 */
function le_site_create_taxonomy_terms() {
  // Build array with terms.
  $terms_stack = array(
    array(
      'vocabulary_machine_name' => 'category',
      'terms' => array('Politique', 'Economie', 'Société', 'Culture', 'Médias', 'Sports', 'People'),
    ),
    array(
      'vocabulary_machine_name' => 'type',
      'terms' => array('Article', 'Brève', 'Billet de blog', 'Interview', 'Revue de presse', 'Caricature'),
    ),
  );

  // Create terms.
  foreach ($terms_stack as $terms) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($terms['vocabulary_machine_name']);

    if ($vocabulary) {
      foreach ($terms['terms'] as $term) {
        taxonomy_term_save((object) array('name' => $term, 'vid' => $vocabulary->vid));
      }
    }
    else {
      $t = get_t();
      drupal_set_message($t(
          'Vocabulary with name @name cannot be loaded. Terms are not created.',
          array('@name' => $terms['slugs'])
        ),
        'error'
      );
    }
  }
}
