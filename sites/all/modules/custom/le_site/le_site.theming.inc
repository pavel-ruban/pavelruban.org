<?php

/**
 * Return class for rubrique name. Used in header menu.
 */
function le_site_get_classes_by_rubrique($rubrique) {

  switch ($rubrique) {
    case 'Politique':
      return 'policy';
      break;

    case 'Economie':
      return 'economy';
      break;

    case 'Société':
      return 'company';
      break;

    case 'Culture':
      return 'culture';
      break;

    case 'Médias':
      return 'media';
      break;

    case 'Sports':
      return 'sports';
      break;

    case 'People':
      return 'people';
      break;

  }
}

/**
 * Return titles and classes for additional header links.
 */
function le_site_get_data_for_additional_header_links($title) {

  switch ($title) {

    case 'Blogs 360':
      return array('title' => 'Blogs 360', 'class' => 'blog');
      break;

    case 'mail':
      return array('title' => 'mail', 'class' => 'mail');
      break;

    case 'share':
      return array('title' => 'share', 'class' => 'share');
      break;

    case 'search':
      return array('title' => 'search', 'class' => 'search');
      break;

    case 'arabe':
      return array('title' => 'ةيبرعلا', 'class' => 'arabe');
      break;
  }
}