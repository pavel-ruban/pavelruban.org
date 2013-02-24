<?php
/**
 * @file
 * Ctools CT plugin for render header.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Related articles'),
  'description' => t('LES CONTENUS LIÉS'),
  'category' => t('Le360 site'),
  'hook theme' => 'le_site_related_articles_theme',
);

/**
 * Render the custom content type.
 */
function le_site_related_articles_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $nid = reset($panel_args);
  if ($nid) {
    $node = node_load($nid);
    if ($node) {
      $field_read_more = field_get_items('node', $node, 'field_read_more');
      if (!empty($field_read_more)) {
        $ids = array();
        foreach ($field_read_more as $article) {
          $ids[] = $article['target_id'];
        }
        // Render view.
        $view = views_embed_view('article', 'panel_pane_2', implode(',', $ids));
        $block->content = theme('le_site_related_articles', array('view' => $view));
      }
    }
  }

  return $block;
}

/**
 * Implements of hook_theme().
 */
function le_site_related_articles_theme(&$theme, $plugin) {
  $theme['le_site_related_articles'] = array(
    'path'      => $plugin['path'],
    'template'  => 'related-articles',
    'variables' => array('view' => NULL),
  );
}
