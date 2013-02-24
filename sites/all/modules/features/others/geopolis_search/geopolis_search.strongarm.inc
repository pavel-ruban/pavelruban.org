<?php
/**
 * @file
 * geopolis_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function geopolis_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_tasks';
  $strongarm->value = array();
  $export['search_api_tasks'] = $strongarm;

  return $export;
}
