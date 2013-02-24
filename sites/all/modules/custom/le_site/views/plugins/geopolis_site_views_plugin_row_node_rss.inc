<?php


class geopolis_site_views_plugin_row_node_rss extends views_plugin_row {

  // Basic properties that let the row style follow relationships.
  var $base_table = 'node';
  var $base_field = 'nid';

  // Stores the nodes loaded with pre_render.
  var $nodes = array();

  function option_definition() {
    $options = parent::option_definition();
    $options['view_mode'] = array('default' => 'rss');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $options = array(
      'rss'    => t('RSS'),
    );
    
    // Load custom build modes as groups.
    $entity_info = entity_get_info('node');
    $view_modes = $entity_info['view modes'];
    foreach ($view_modes as $view_mode_id => $view_mode) {
      if (!in_array($view_mode_id, array_keys($options))) {
        $options[$view_mode_id] = $view_mode['label'];
      }
    }
    
    $form['view_mode'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#title' => t('View mode'),
      '#default_value' => $this->options['view_mode'],
    );
  }

  function pre_render($values) {
    $nids = array();
    foreach ($values as $row) {
      $nids[] = $row->{$this->field_alias};
    }
    if (!empty($nids)) {
      $this->nodes = node_load_multiple($nids);
    }
  }

  function render($row) {
    $nid = $row->{$this->field_alias};
    if (!is_numeric($nid)) {
      return;
    }

    // Load the specified node:
    $node = $this->nodes[$nid];
    if (empty($node)) {
      return;
    }

    $node->rss_namespaces = array('xmlns:dc' => 'http://purl.org/dc/elements/1.1/');
    $this->view->style_plugin->namespaces = array_merge($this->view->style_plugin->namespaces, $node->rss_namespaces);
    $build = node_view($node, $this->options['view_mode']);
    return drupal_render($build);
  }

}
