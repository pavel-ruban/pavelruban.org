<?php
/**
 * @file
 * Layout declaration.
 */

$plugin = array(
  'title' => t('Home page'),
  'category' => t('Pavel Ruban'),
  'theme' => 'home_page',
  'admin css' => 'layout.css',
  'icon' => 'onecol.png',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer'),
  ),
);
