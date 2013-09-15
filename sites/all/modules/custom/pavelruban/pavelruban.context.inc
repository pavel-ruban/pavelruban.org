<?php
/**
 * @file
 * Provides different data context.
 */

/**
 * Taxonomy tag field context.
 */
function pavelruban_tags_context($nid = NULL) {
  $context = &drupal_static(__FUNCTION__);

  if (empty($context[$nid])) {
    $context[$nid] = array();
    $node = node_load($nid);
    $wrapper = entity_metadata_wrapper('node', $node);

    $tags = $wrapper->field_tags->value();

    foreach ($tags as $tag) {
      $context[$nid][] = array(
        'name' => $tag->name,
        'tid' => $tag->tid,
      );
    }
  }

  return $context[$nid];
}
