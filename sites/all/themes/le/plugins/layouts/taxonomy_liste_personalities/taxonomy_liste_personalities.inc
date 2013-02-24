<?php
/**
 * @file
 * Taxonomy listing layout declaration.
 */

$plugin = array(
  'title' => t('Taxonomy liste personalities'),
  'category' => t('Geopolis'),
  'theme' => 'taxonomy_liste_personalities',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'column_left' => t('Left column'),
    'column_right' => t('Right column'),
  ),
);
