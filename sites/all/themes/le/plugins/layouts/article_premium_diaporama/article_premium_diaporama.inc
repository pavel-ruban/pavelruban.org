<?php
/**
 * @file
 * Content page layout declaration.
 */

$plugin = array(
  'title' => t('Article Premium Diaporama'),
  'category' => t('Geopolis'),
  'theme' => 'article_premium_diaporama',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'column_content' => t('Content column'),
    'column_meta' => t('Meta column'),
    'column_side' => t('Side column'),
  ),
);
