<?php
/**
 * @file
 * Definition of the 'pane_with_title' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Pane with title'),
  'description' => t('Render pane with title and wrapper.'),
  'render pane' => 'geopolis_pane_with_title_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_geopolis_pane_with_title_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  return theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
