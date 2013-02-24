<?php
/**
 * @file
 * le_nodequeue.features.inc
 */

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function le_nodequeue_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: choosen_video
  $nodequeues['choosen_video'] = array(
    'qid' => '3',
    'name' => 'choosen_video',
    'title' => 'La Une Vidéo',
    'subqueue_title' => '',
    'size' => '5',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: chosen
  $nodequeues['chosen'] = array(
    'qid' => '1',
    'name' => 'chosen',
    'title' => 'La Une',
    'subqueue_title' => '',
    'size' => '3',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
      1 => 'folder',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: exceptional
  $nodequeues['exceptional'] = array(
    'qid' => '5',
    'name' => 'exceptional',
    'title' => 'Exceptionnel',
    'subqueue_title' => '',
    'size' => '1',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: news_flow
  $nodequeues['news_flow'] = array(
    'qid' => '4',
    'name' => 'news_flow',
    'title' => 'Fleuve d’actualité',
    'subqueue_title' => '',
    'size' => '7',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
      1 => 'folder',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: press_review
  $nodequeues['press_review'] = array(
    'qid' => '2',
    'name' => 'press_review',
    'title' => 'Revue de presse',
    'subqueue_title' => '',
    'size' => '1',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'article',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
