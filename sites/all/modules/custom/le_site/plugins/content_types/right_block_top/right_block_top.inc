<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Top360'),
  'description' => t('Top360'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_right_block_top_theme',
);

/**
 * Render the custom content type.
 */
function le_site_right_block_top_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();

  $views['articles'] = views_embed_view('right_column_blocks', 'panel_pane_1');
  $views['videos'] = views_embed_view('right_column_blocks', 'panel_pane_2');
  $views['diaporamas'] = views_embed_view('right_column_blocks', 'panel_pane_3');

  $block->content = theme('le_right_block_top', array('views' => $views));
  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_right_block_top_theme(&$theme, $plugin) {
  $theme['le_right_block_top'] = array(
    'path'      => $plugin['path'],
    'template'  => 'right-block-top',
    'variables' => array('views' => NULL),
  );
}
