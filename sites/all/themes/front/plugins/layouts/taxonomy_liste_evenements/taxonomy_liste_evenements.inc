<?php
/**
 * @file
 * Taxonomy listing layout declaration.
 */

$plugin = array(
  'title' => t('Taxonomy liste evenements'),
  'category' => t('Geopolis'),
  'theme' => 'taxonomy_liste_evenements',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'column_left' => t('Left column'),
    'column_right' => t('Right column'),
  ),
);
