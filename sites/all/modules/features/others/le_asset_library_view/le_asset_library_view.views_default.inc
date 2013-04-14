<?php
/**
 * @file
 * le_asset_library_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function le_asset_library_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'le_assets_library';
  $view->description = 'Médiathèque';
  $view->tag = 'dashboard';
  $view->base_table = 'asset';
  $view->human_name = 'Le360 Assets library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Médiathèque';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer assets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'asset';
  $handler->display->display_options['row_options']['view_mode'] = 'tooltip';
  $handler->display->display_options['row_options']['asset_library'] = 1;
  /* Relationship: Media Asset: Asset type */
  $handler->display->display_options['relationships']['type']['id'] = 'type';
  $handler->display->display_options['relationships']['type']['table'] = 'asset';
  $handler->display->display_options['relationships']['type']['field'] = 'type';
  $handler->display->display_options['relationships']['type']['required'] = TRUE;
  /* Relationship: Media Asset: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'asset';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Media Asset: Aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'asset';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = '';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Sort criterion: Media Asset: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'asset';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Media Asset: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'asset';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titre';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Media Asset: Asset type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'asset';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;

  /* Display: Library */
  $handler = $view->new_display('page', 'Library', 'library');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/assets/search';

  /* Display: Library Table */
  $handler = $view->new_display('page', 'Library Table', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
    'machine_name' => 'machine_name',
    'field_asset_image' => 'field_asset_image',
    'field_asset_video' => 'field_asset_image',
    'title' => 'title',
    'name' => 'name',
    'field_user_name' => 'field_user_name',
    'insert_asset' => 'insert_asset',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'aid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'machine_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_asset_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_asset_video' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'insert_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<?php
  print theme(\'ajouter_reference_dialog_buttons\');
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Media Asset: Aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'asset';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = '';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = FALSE;
  /* Field: Asset type: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'asset_type';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['relationship'] = 'type';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  /* Field: Media Asset: L’image */
  $handler->display->display_options['fields']['field_asset_image']['id'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['table'] = 'field_data_field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['field'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['label'] = 'Vignette';
  $handler->display->display_options['fields']['field_asset_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_asset_image']['alter']['text'] = '<span rel="assets/tooltip/[aid]/tooltip" class="asset-tooltip">[field_asset_image]</span>';
  $handler->display->display_options['fields']['field_asset_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_asset_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_asset_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asset_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Media Asset: La vidéo */
  $handler->display->display_options['fields']['field_asset_video']['id'] = 'field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['table'] = 'field_data_field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['field'] = 'field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['label'] = '';
  $handler->display->display_options['fields']['field_asset_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_asset_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_asset_video']['type'] = 'emvideo_snapshot';
  $handler->display->display_options['fields']['field_asset_video']['settings'] = array(
    'width' => '100',
    'class' => '',
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_asset'] = FALSE;
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Field: Asset type: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'asset_type';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'type';
  $handler->display->display_options['fields']['name']['label'] = 'Type';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_name']['label'] = 'Auteur';
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  /* Field: Media Asset: Insert button */
  $handler->display->display_options['fields']['insert_asset']['id'] = 'insert_asset';
  $handler->display->display_options['fields']['insert_asset']['table'] = 'asset';
  $handler->display->display_options['fields']['insert_asset']['field'] = 'insert_asset';
  $handler->display->display_options['fields']['insert_asset']['label'] = 'Insert';
  $handler->display->display_options['fields']['insert_asset']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Media Asset: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'asset';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titre';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Media Asset: Asset type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'asset';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'free_html' => 'free_html',
    'diaporama' => 'diaporama',
    'document' => 'document',
    'image' => 'image',
    'audio' => 'audio',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_user_name_value']['id'] = 'field_user_name_value';
  $handler->display->display_options['filters']['field_user_name_value']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['filters']['field_user_name_value']['field'] = 'field_user_name_value';
  $handler->display->display_options['filters']['field_user_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_user_name_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_user_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_name_value']['expose']['operator_id'] = 'field_user_name_value_op';
  $handler->display->display_options['filters']['field_user_name_value']['expose']['label'] = 'Auteur';
  $handler->display->display_options['filters']['field_user_name_value']['expose']['operator'] = 'field_user_name_value_op';
  $handler->display->display_options['filters']['field_user_name_value']['expose']['identifier'] = 'field_user_name_value';
  $handler->display->display_options['path'] = 'admin/assets/search';

  /* Display: Asset preview */
  $handler = $view->new_display('panel_pane', 'Asset preview', 'asset_preview');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'field_asset_image' => 'field_asset_image',
    'field_asset_video' => 'field_asset_video',
    'edit_asset' => 'edit_asset',
    'delete_asset' => 'delete_asset',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_asset_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_asset_video' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Field: Media Asset: Asset type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'asset';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Media Asset: L’image */
  $handler->display->display_options['fields']['field_asset_image']['id'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['table'] = 'field_data_field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['field'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['label'] = '';
  $handler->display->display_options['fields']['field_asset_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_asset_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asset_image']['type'] = 'le_site_image_url';
  $handler->display->display_options['fields']['field_asset_image']['settings'] = array(
    'image_style' => 'asset_list_preview',
  );
  /* Field: Media Asset: La vidéo */
  $handler->display->display_options['fields']['field_asset_video']['id'] = 'field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['table'] = 'field_data_field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['field'] = 'field_asset_video';
  $handler->display->display_options['fields']['field_asset_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_asset_video']['type'] = 'emvideo_snapshot';
  $handler->display->display_options['fields']['field_asset_video']['settings'] = array(
    'width' => '100',
    'class' => '',
  );
  /* Field: Media Asset: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'asset';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'his';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Media Asset: Aid */
  $handler->display->display_options['arguments']['aid']['id'] = 'aid';
  $handler->display->display_options['arguments']['aid']['table'] = 'asset';
  $handler->display->display_options['arguments']['aid']['field'] = 'aid';
  $handler->display->display_options['arguments']['aid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['aid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['aid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['aid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['aid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['le_assets_library'] = array(
    t('Master'),
    t('Médiathèque'),
    t('Apply'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Asset type'),
    t('User'),
    t('Title'),
    t('Titre'),
    t('Type'),
    t('Library'),
    t('more'),
    t('Library Table'),
    t('<?php
  print theme(\'ajouter_reference_dialog_buttons\');
?>'),
    t('Machine name'),
    t('Vignette'),
    t('<span rel="assets/tooltip/[aid]/tooltip" class="asset-tooltip">[field_asset_image]</span>'),
    t('Auteur'),
    t('Insert'),
    t('Asset preview'),
    t('La vidéo'),
    t('Date changed'),
    t('All'),
    t('View panes'),
  );
  $export['le_assets_library'] = $view;

  return $export;
}
