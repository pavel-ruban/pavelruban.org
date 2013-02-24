<?php

/**
 * @file
 * Plugin to provide access control based upon term vocabulary name.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Taxonomy: vocabulary name"),
  'description' => t('Control access by vocabulary.'),
  'callback' => 'ctools_term_vocabulary_name_ctools_access_check',
  'default' => array('names' => array()),
  'settings form' => 'ctools_term_vocabulary_name_ctools_access_settings',
  'settings form submit' => 'ctools_term_vocabulary_name_ctools_access_settings_submit',
  'summary' => 'ctools_term_vocabulary_name_ctools_access_summary',
  'required context' => new ctools_context_required(
    t('Vocabulary'), array('taxonomy_term', 'terms', 'taxonomy_vocabulary')
  ),
);

/**
 * Settings form for the 'by term_vocabulary' access plugin
 */
function ctools_term_vocabulary_name_ctools_access_settings($form, &$form_state, $conf) {
  $options = array();
  $vocabularies = taxonomy_get_vocabularies();

  foreach ($vocabularies as $voc) {
    $options[$voc->machine_name] = check_plain($voc->name);
  }

  $form['settings']['names'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Vocabularies'),
    '#options' => $options,
    '#description' => t('Only the checked vocabularies will be valid.'),
    '#default_value' => $conf['names'],
  );
  return $form;
}

/**
 * Compress the term_vocabularys allowed to the minimum.
 */
function ctools_term_vocabulary_name_ctools_access_settings_submit($form, &$form_state) {
  $form_state['values']['settings']['names'] = array_filter($form_state['values']['settings']['names']);
}

/**
 * Check for access.
 */
function ctools_term_vocabulary_name_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data) || empty($context->data->vocabulary_machine_name)) {
    return FALSE;
  }

  if (array_filter($conf['names']) && empty($conf['names'][$context->data->vocabulary_machine_name])) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description based upon the checked term_vocabularys.
 */
function ctools_term_vocabulary_name_ctools_access_summary($conf, $context) {
  if (!isset($conf['type'])) {
    $conf['type'] = array();
  }
  $vocabularies = taxonomy_get_vocabularies();

  $names = array();
  foreach ($vocabularies as $voc) {
    if (in_array($voc->machine_name, $conf['names'])) {
      $names[] = check_plain($voc->name);
    }
  }

  if (empty($names)) {
    return t('@identifier is any vocabulary', array('@identifier' => $context->identifier));
  }

  return format_plural(
    count($names),
    '@identifier vocabulary is "@vids"',
    '@identifier vocabulary is one of "@vids"',
    array('@vids' => implode(', ', $names), '@identifier' => $context->identifier)
  );
}
