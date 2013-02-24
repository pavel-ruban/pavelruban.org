<?php
/**
 * @file
 * le_dashboard_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function le_dashboard_home_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dashboard_home_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dashboard home: Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Les derniers articles';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Tous les articles';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_user_name' => 'field_user_name',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Titre de l’article';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = ' Date et heure de publication';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Modifier';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="/node/[nid]/edit?destination=admin/dashboard">Modifier</a>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Dashboard home: Articles */
  $handler = $view->new_display('panel_pane', 'Dashboard home: Articles', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = 'admin/dashboard/articles';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access dashboard articles';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_article_media_target_id']['id'] = 'field_article_media_target_id';
  $handler->display->display_options['relationships']['field_article_media_target_id']['table'] = 'field_data_field_article_media';
  $handler->display->display_options['relationships']['field_article_media_target_id']['field'] = 'field_article_media_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Media Asset: L’image */
  $handler->display->display_options['fields']['field_asset_image']['id'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['table'] = 'field_data_field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['field'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['relationship'] = 'field_article_media_target_id';
  $handler->display->display_options['fields']['field_asset_image']['label'] = 'Vignette';
  $handler->display->display_options['fields']['field_asset_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asset_image']['settings'] = array(
    'image_style' => 'asset_list_preview',
    'image_link' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Titre de l’article';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Signature */
  $handler->display->display_options['fields']['field_signature']['id'] = 'field_signature';
  $handler->display->display_options['fields']['field_signature']['table'] = 'field_data_field_signature';
  $handler->display->display_options['fields']['field_signature']['field'] = 'field_signature';
  $handler->display->display_options['fields']['field_signature']['label'] = 'Auteur';
  $handler->display->display_options['fields']['field_signature']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = ' Date et heure de publication';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Modifier';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<a href="/node/[nid]/edit?destination=admin/dashboard">Modifier</a>';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Modifier';
  $handler->display->display_options['pane_category']['name'] = 'Tableau de bord';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['dashboard_home_articles'] = array(
    t('Master'),
    t('Les derniers articles'),
    t('Tous les articles'),
    t('Apply'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('author'),
    t('Nid'),
    t('Titre de l’article'),
    t(' Date et heure de publication'),
    t('Modifier'),
    t('<a href="/node/[nid]/edit?destination=admin/dashboard">Modifier</a>'),
    t('Dashboard home: Articles'),
    t('more'),
    t('Media Asset entity referenced from field_article_media'),
    t('Vignette'),
    t('Auteur'),
    t('Tableau de bord'),
  );
  $export['dashboard_home_articles'] = $view;

  return $export;
}
