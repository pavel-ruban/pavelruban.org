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
  'title' => t("Article: video"),
  'description' => t('Control access by principal media field.'),
  'callback' => 'ctools_video_article_ctools_access_check',
  'summary' => 'ctools_video_article_ctools_access_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Check for access.
 */
function ctools_video_article_ctools_access_check($conf, $context) {
  if (!empty($context->data->field_article_main_media[LANGUAGE_NONE][0]['target_id'])) {
    $asset = asset_load($context->data->field_article_main_media[LANGUAGE_NONE][0]['target_id']);
    if ($asset->type == 'video'
      && !empty($asset->field_asset_video[LANGUAGE_NONE][0])) {

      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Provide a summary description based upon the checked term_vocabularys.
 */
function ctools_video_article_ctools_access_summary($conf, $context) {
  return t('Grant access to video article page if principal media feild containts
    video asset');
}
