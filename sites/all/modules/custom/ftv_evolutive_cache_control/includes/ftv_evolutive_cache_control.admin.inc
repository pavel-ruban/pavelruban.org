<?php

/**
 * @file 
 * ftv_evolutive_cache_control admin include file
 */
function _ftv_evolutive_cache_control_admin() {
  $form = array();

  $form['urls'] = array(
    '#type' => 'fieldset',
    '#title' => 'URLs for specific TTL Levels',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['urls']['ttls_urls'] = array(
    '#type' => 'textarea',
    '#title' => 'TTL by url',
    '#default_value' => variable_get('ttls_urls', ''),
  );

  $form['default'] = array(
    '#type' => 'fieldset',
    '#title' => 'Default TTL Levels for all content types',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['default']['ttls_default'] = array(
    '#type' => 'textarea',
    '#title' => 'TTL Levels',
    '#default_value' => variable_get('ttls_default', ''),
  );

  $form['content_type'] = array(
    '#type' => 'fieldset',
    '#title' => 'Content Types',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $node_types = node_type_get_types();
  foreach ($node_types as $node_type) {
    $form['content_type'][$node_type->type] = array(
      '#type' => 'fieldset',
      '#title' => $node_type->name,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['content_type'][$node_type->type]['ttls_' . $node_type->type] = array(
      '#type' => 'textarea',
      '#title' => 'Param',
      '#default_value' => variable_get('ttls_' . $node_type->type, ''),
    );
  }

  if (module_exists('page_manager')) {
    $form['tasks'] = array(
      '#type' => 'fieldset',
      '#title' => t('Page manager tasks'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE
    );

    ctools_include('page_manager.admin', 'page_manager', '');
    $tasks = page_manager_get_tasks_by_type('page');
    foreach ($tasks as $task_name => $task) {
      if (($task['task type']) !== 'page') continue;
      if ($task_name === 'page') {
        $subtasks = page_manager_get_task_subtasks($task);
        foreach ($subtasks as $subtask_name => $subtask) {
          $form['tasks'][$subtask_name] = array(
            '#type' => 'fieldset',
            '#title' => $subtask['admin title'],
            '#collapsible' => TRUE,
            '#collapsed' => TRUE
          );

          $form['tasks'][$subtask_name]['ttls_' . $subtask_name] = array(
            '#type' => 'textfield',
            '#title' => 'Param',
            '#default_value' => variable_get('ttls_' . $subtask_name, ''),
          );
        }
      }
      else {
        $form['tasks'][$task_name] = array(
          '#type' => 'fieldset',
          '#title' => $task['title'],
          '#collapsible' => TRUE,
          '#collapsed' => TRUE
        );

        $form['tasks'][$task_name]['ttls_' . $task_name] = array(
          '#type' => 'textfield',
          '#title' => 'Param',
          '#default_value' => variable_get('ttls_' . $task_name, ''),
        );
      }
    }
  }

  return system_settings_form($form);
}
