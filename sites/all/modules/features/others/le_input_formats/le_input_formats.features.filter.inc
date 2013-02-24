<?php
/**
 * @file
 * le_input_formats.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function le_input_formats_filter_default_formats() {
  $formats = array();

  // Exported format: Simple HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Simple HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-44',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-42',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML (Assets).
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML (Assets)',
    'cache' => '0',
    'status' => '1',
    'weight' => '1',
    'filters' => array(
      'assets_filter' => array(
        'weight' => '-45',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML with pagebreaks.
  $formats['full_html_with_pagebreaks'] = array(
    'format' => 'full_html_with_pagebreaks',
    'name' => 'Full HTML with pagebreaks',
    'cache' => '0',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'assets_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: PHP code.
  $formats['php_code'] = array(
    'format' => 'php_code',
    'name' => 'PHP code',
    'cache' => '0',
    'status' => '1',
    'weight' => '11',
    'filters' => array(
      'php_code' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '10',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
