<?php
/**
 * @file
 * Admin theme specific menu callbacks.
 */

/**
 * Ask for confirmation of node depublication.
 */
function le_site_node_unpublish_confirm($form, &$form_state, $node) {
  $form['#node'] = $node;
  $form['nid'] = array('#type' => 'value', '#value' => $node->nid);
  return confirm_form($form,
    t('Are you sure you want to unpublish %title?', array('%title' => $node->title)),
    'node/' . $node->nid,
    t('%title will be unpublished', array('%title' => $node->title)),
    t('Unpublish'),
    t('Cancel')
  );
}

/**
 * Execute node depublication.
 */
function le_site_node_unpublish_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $node = node_load($form_state['values']['nid'], NULL, TRUE);
    $node->original = clone $node;
    $node->status = 0;
    node_save($node);
    drupal_set_message(t('%title has been unpublished.', array('%title' => $node->title)));
  }
  $form_state['redirect'] = '<front>';
}

/**
 * Ask for confirmation of node publication.
 */
function le_site_node_publish_confirm($form, &$form_state, $node) {
  $form['#node'] = $node;
  $form['nid'] = array('#type' => 'value', '#value' => $node->nid);
  if (!empty($node->scheduler['publish_on'])) {
    drupal_set_message(
      t('This material is queued for publication in !date at !time.
        If you want publish it now, it will be removed from the queue and published immediately.',
        array(
          '!date' => format_date($node->scheduler['publish_on'], 'custom', 'Y/m/d'),
          '!time' => format_date($node->scheduler['publish_on'], 'custom', 'H:i:s'),
        )
      ),
      'warning'
    );
  }
  return confirm_form($form,
    t('Are you sure you want to publish %title?', array('%title' => $node->title)),
    'node/' . $node->nid,
    t('%title will be published', array('%title' => $node->title)),
    t('Publish'),
    t('Cancel')
  );
}

/**
 * Execute node publication.
 */
function le_site_node_publish_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $node = node_load($form_state['values']['nid'], NULL, TRUE);
    $node->original = clone $node;
    drupal_set_message(t('%title has been published.', array('%title' => $node->title)));
    unset($node->publish_on);
    $node->status = 1;
    node_save($node);
  }
  $form_state['redirect'] = '<front>';
}
