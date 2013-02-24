<?php
/**
 * @file
 * geopolis_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function geopolis_search_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'combined_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_server_search_server_multi';
  $view->human_name = 'Combined search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site search';
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Nodes index : Identifiant (ID) du nœud */
  $handler->display->display_options['fields']['nodes_index:nid']['id'] = 'nodes_index:nid';
  $handler->display->display_options['fields']['nodes_index:nid']['table'] = 'search_api_server_search_server_multi';
  $handler->display->display_options['fields']['nodes_index:nid']['field'] = 'nodes_index:nid';
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nodes_index:nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nodes_index:nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nodes_index:nid']['hide_alter_empty'] = 1;
  /* Champ: Terms index : Identifiant (ID) du terme */
  $handler->display->display_options['fields']['terms_index:tid']['id'] = 'terms_index:tid';
  $handler->display->display_options['fields']['terms_index:tid']['table'] = 'search_api_server_search_server_multi';
  $handler->display->display_options['fields']['terms_index:tid']['field'] = 'terms_index:tid';
  $handler->display->display_options['fields']['terms_index:tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['terms_index:tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['terms_index:tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['terms_index:tid']['hide_alter_empty'] = 1;
  /* Critère de tri: Rechercher : Pertinence */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_server_search_server_multi';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filtre contextuel: Rechercher : Fulltext search */
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['table'] = 'search_api_server_search_server_multi';
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['search_api_multi_fulltext']['summary']['format'] = 'default_summary';

  /* Display: Site search */
  $handler = $view->new_display('panel_pane', 'Site search', 'panel_pane_search');
  $translatables['combined_search'] = array(
    t('Master'),
    t('Site search'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Identifiant (ID) du nœud'),
    t('.'),
    t(','),
    t('Identifiant (ID) du terme'),
    t('Tout'),
    t('View panes'),
  );
  $export['combined_search'] = $view;

  return $export;
}
