<?php
/**
 * @file
 * Content page layout declaration.
 */

$plugin = array(
  'title' => t('Content page'),
  'category' => t('Le360'),
  'theme' => 'content_page',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'column_left' => t('Content'),
    'column_right' => t('Sidebar'),
  ),
);
