<?php
/**
 * Provides functions for work with assets.
 */

/**
 * Creates asset with type poll from node poll.
 */
function le_site_create_asset_poll($node) {

  entity_create('asset', array(
    'uid' => $node->uid,
    'type' => 'poll', //bundle
    'title' => $node->title,
    'field_poll' => array(
        LANGUAGE_NONE => array(
        0 => array(
          'target_id' => $node->nid,
        ),
      ),
    ),
  ))->save();
}

/**
 * Updates asset with type poll from node poll.
 */
function le_site_edit_asset_poll($node) {
  $aid = db_select('field_data_field_poll', 'fp')
    ->fields('fp', array('entity_id'))
    ->condition('field_poll_target_id', $node->nid)
    ->condition('entity_type', 'asset')
    ->range(0, 1)
    ->execute()
    ->fetchCol();
  if (!empty($aid)) {
    if ($asset = entity_load('asset', array($aid[0]))) {
      $asset = reset($asset);
      $asset->title = $node->title;
      entity_save('asset', $asset);
    }
  }
}

/**
 * Remove asset when node poll will be deleted.
 */
function le_site_delete_asset_poll($node) {
  if (!empty($node)) {
    $aid = db_select('field_data_field_poll', 'fp')
      ->fields('fp', array('entity_id'))
      ->condition('field_poll_target_id', $node->nid)
      ->condition('entity_type', 'asset')
      ->range(0, 1)
      ->execute()->fetchCol();
    if (!empty($aid)) {
      entity_delete('asset', $aid[0]);
    }
  }
}