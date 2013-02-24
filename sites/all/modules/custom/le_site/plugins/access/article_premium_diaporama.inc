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
  'title' => t("Article: premium diaporama"),
  'description' => t('Control access by principal media field.'),
  'callback' => 'ctools_article_premium_diaporama_ctools_access_check',
  'summary' => 'ctools_article_premium_diaporama_ctools_access_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Check for access.
 */
function ctools_article_premium_diaporama_ctools_access_check($conf, $context) {
  if (!empty($context->data->field_article_main_media[LANGUAGE_NONE][0]['target_id'])) {
    $asset = asset_load($context->data->field_article_main_media[LANGUAGE_NONE][0]['target_id']);
    if ($asset->type == 'diaporama'
      && $asset->field_asset_premium[LANGUAGE_NONE][0]['value'] == 1) {

      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Provide a summary description based upon the checked term_vocabularys.
 */
function ctools_article_premium_diaporama_ctools_access_summary($conf, $context) {
  return t('Grant access to premium diaporama article page if principal media feild containts
    premium diaporama');
}
