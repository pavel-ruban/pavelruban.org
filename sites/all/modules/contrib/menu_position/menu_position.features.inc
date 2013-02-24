<?php
/**
 * Implements hook_features_api().
 */
function menu_position_features_api() {
  return array(
    'menu_position' => array(
      'name' => t('Menu position'),
      'default_hook' => 'menu_position_default_rules',
      'default_file' => FEATURES_DEFAULTS_INCLUDED,
      'features_source' => TRUE,
      'file' => drupal_get_path('module', 'menu_position') .'/menu_position.features.inc'
    )
  );
}

/**
 * Helper function to get the list of all rules
 */
function _menu_position_read_rules() {
  return db_query('SELECT * FROM {menu_position_rules} ORDER BY weight, rid')->fetchAllAssoc('rid');
}


/**
 * Implements hook_features_export().
 * @param array $data
 *   An array of machine names for the component in question to be exported.
 * @param array &$export
 *   By reference. An array of all components to be exported with a given
 *   feature. Component objects that should be exported should be added to
 *   this array.
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called.
 */
function menu_position_features_export($data, &$export, $module_name) {
  foreach ($data as $rule_string) {
    //$rid = substr($rule_string, 19); //'menu_position_rule'
    $export['features']['menu_position'][$rule_string] = $rule_string;
  }
  return array();
}

/**
 * Implements hook_features_export_options().
 * List all objects for a component that may be exported.
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function menu_position_features_export_options() {
  $options = array();
  $rules = _menu_position_read_rules();
  foreach ($rules as $rule) {
    $options['menu_position_rule:' . $rule->rid] = $rule->admin_title;
  }
  return $options;
}

/**
 * Implements hook_features_export_render().
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function menu_position_features_export_render($module_name, $data, $export = NULL) {
  module_load_include('inc', 'menu_position', 'menu_position.admin');
  $code = array();
  $code[] = '$menu_positions = array();';
  foreach ($data as $rid_txt) {
    $rid = substr($rid_txt, 19); //'menu_position_rule'
    $rule = menu_position_read_rule($rid);
    if (!empty($rule['plid']) && !empty($rule['mlid'])) {
      $menu_link = menu_link_load($rule['plid']);
      $rule['plink_path'] = $menu_link['link_path'];
      $rule['menu_name'] = $menu_link['menu_name'];
      unset($rule['mlid']);
      unset($rule['plid']);
      $code[] = "  \$menu_positions['$rid_txt'] = " . features_var_export($rule) .";";
    }
  }
  $code[] = "return \$menu_positions;";
  $code = implode("\n", $code);
  return array('menu_position_default_rules' => $code);
}

/**
 * Implements hook_features_export_revert().
 * Revert all component objects for a given feature module.
 *
 * @param string $module_name
 *   The name of the feature module whose components should be reverted.
 * @return boolean
 *   TRUE or FALSE for whether the components were successfully reverted.
 */
function menu_position_features_revert($module_name) {
  $rules = module_invoke($module_name, 'menu_position_default_rules');
  if (!empty($rules)) {
    module_load_include('inc', 'menu_position', 'menu_position.admin');
    // We will collect rules which not to be deleted.
    $rids = array();
    foreach ($rules as $rule) {
      $rule['plid'] = db_query("SELECT mlid FROM {menu_links} WHERE link_path = :link_path and menu_name = :menu_name",
        array(':link_path' => $rule['plink_path'], ':menu_name' => $rule['menu_name']))->fetchField();

      $db_rule = menu_position_read_rule($rule['rid']);
      if (!empty($db_rule['rid'])) {
        $rids[] = $db_rule['rid'];
        menu_position_edit_rule($rule);
      }
      else {
        $rids[] = _menu_position_features_add_rule($rule);
      }
    }

    _menu_position_features_rules_cleanup($rids, TRUE);
  }
}

/**
 * Delete all rules except rebuiled.
 */
function _menu_position_features_rules_cleanup($rids, $exclude = FALSE) {
  $rids = array_filter($rids);
  if (!empty($rids)) {
    if ($exclude) {
      db_delete('menu_position_rules')->condition('rid', $rids, 'NOT IN')->execute();
    }
    else {
      db_delete('menu_position_rules')->condition('rid', $rids, 'IN')->execute();
    }
  }
}

/**
 * Fork of menu_position_add_rule().
 * Required to return rid of newly created rule record.
 */
function _menu_position_features_add_rule($rule) {
  $fields = array(
    'admin_title' => $rule['admin_title'],
    'conditions'  => serialize($rule['conditions']),
    'menu_name'   => $rule['menu_name'],
    'plid'        => $rule['plid'],
  );
  $rid = db_insert('menu_position_rules')
    ->fields($fields)
    ->execute();

  $mlid = menu_position_add_menu_link($rid, $rule['plid'], $rule['admin_title']);

  // Now add the mlid back to the rule.
  db_update('menu_position_rules')
    ->fields(array('mlid' => $mlid))
    ->condition('rid', $rid)
    ->execute();

  return $rid;
}

/**
 * Fork of menu_position_add_rule().
 * Required to insert record with primary key.
 */
function _menu_position_features_add_rule_full($rule) {
  $fields = array(
    'admin_title' => $rule['admin_title'],
    'conditions'  => serialize($rule['conditions']),
    'menu_name'   => $rule['menu_name'],
    'plid'        => $rule['plid'],
    'rid'         => $rule['rid'],
  );
  db_insert('menu_position_rules')
    ->fields($fields)
    ->execute();

  $mlid = menu_position_add_menu_link($rule['rid'], $rule['plid'], $rule['admin_title']);

  // Now add the mlid back to the rule.
  db_update('menu_position_rules')
    ->fields(array('mlid' => $mlid))
    ->condition('rid', $rule['rid'])
    ->execute();
}

/**
 * Implements hook_features_export_rebuild().
 * Rebuild all component objects for a given feature module. Should only be
 * implemented for 'faux-exportable' components.
 *
 * This hook is called at points where Features determines that it is safe
 * (ie. the feature is in state `FEATURES_REBUILDABLE`) for your module to
 * replace objects in the database with defaults that you collect from your
 * own defaults hook. See API.txt for how Features determines whether a
 * rebuild of components is possible.
 *
 * @param string $module_name
 *   The name of the feature module whose components should be rebuilt.
 */
function menu_position_features_rebuild($module_name) {
  $rules = module_invoke($module_name, 'menu_position_default_rules');
  if (!empty($rules)) {
    module_load_include('inc', 'menu_position', 'menu_position.admin');
    // We will collect rules which not to be deleted.
    $rids = array();
    foreach ($rules as $rule) {
      $rule['plid'] = db_query("SELECT mlid FROM {menu_links} WHERE link_path = :link_path and menu_name = :menu_name",
        array(':link_path' => $rule['plink_path'], ':menu_name' => $rule['menu_name']))->fetchField();
      // If parent link missed - position rule is useless.
      if (empty($rule['plid'])) {
        continue;
      }

      $db_rule_candidate = menu_position_read_db_rule($rule['plink_path'], $rule['menu_name']);
      $db_rule = menu_position_read_rule($rule['rid']);
      if ($db_rule_candidate) {
        $serialized_conditions = serialize($rule['conditions']);
        // If record with same menu, path and conditions exists in DB, we override it.
        if (!empty($db_rule_candidate['raw_conditions']) && $db_rule_candidate['raw_conditions'] == $serialized_conditions) {
          // Note that we save rid from feature, to have 'default' state.
          if ($db_rule_candidate['rid'] == $rule['rid']) {
            menu_position_edit_rule($rule);
          }
          else {
            // Override existing.
            if ($db_rule['rid']) {
              menu_position_edit_rule($rule);
            }
            else {
              menu_position_add_rule($rule);
            }
            // Remove candidate, because it with same menu, plid, conditions.
            $rids[] = $db_rule_candidate['rid'];
          }
          continue;
        }
      }

      // If continue is not the case - this means record doesn't exists, and we insert new record.
      if ($db_rule['rid']) {
        menu_position_edit_rule($rule);
      }
      elseif (!empty($rule['rid'])) {
        _menu_position_features_add_rule_full($rule);
      }
      else {
        menu_position_add_rule($rule);
      }
    }

    _menu_position_features_rules_cleanup($rids);
  }
}

/**
 * Helper to load position rule by plid path and menu name.
 */
function menu_position_read_db_rule($plid_path, $menu_name) {
  $select = db_select('menu_position_rules', 'm')
    ->fields('m', array());
  $select->join('menu_links', 'ml', 'm.plid = ml.mlid');
  $rule = $select->condition('m.menu_name', $menu_name)
    ->condition('ml.link_path', $plid_path)
    ->execute()
    ->fetchAssoc();
  if (!empty($rule['conditions'])) {
    // Store serialized data to compare with featues content.
    $rule['raw_conditions'] = $rule['conditions'];
    $rule['conditions'] = unserialize($rule['conditions']);
  }
  return $rule;
}
