<?php

/**
 * @file
 * Theme setting callbacks for the le360 theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function le_admin_form_system_theme_settings_alter(&$form, &$form_state) {
  $options = array('none' => t('none'));
  if (function_exists('menu_block_block_info')) {
    foreach (menu_block_block_info() as $delta => $data) {
      $options[$delta] = $data['info'];
    }
    $form['le_admin_menu_level_1'] = array(
      '#type' => 'select',
      '#title' => t('Le360 Admin Menu Level 1'),
      '#options' => $options,
      '#default_value' => theme_get_setting('le_admin_menu_level_1'),
    );
    $form['le_admin_menu_level_2'] = array(
      '#type' => 'select',
      '#title' => t('Le360 Admin Menu Level 2'),
      '#options' => $options,
      '#default_value' => theme_get_setting('le_admin_menu_level_2'),
    );
  }
}
