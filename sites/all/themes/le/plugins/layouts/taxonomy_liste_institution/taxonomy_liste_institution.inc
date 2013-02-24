<?php
/**
 * @file
 * Taxonomy listing layout declaration.
 */

$plugin = array(
  'title' => t('Taxonomy liste institution'),
  'category' => t('Geopolis'),
  'theme' => 'taxonomy_liste_institution',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'column_left' => t('Left column'),
    'column_right' => t('Right column'),
  ),
);
