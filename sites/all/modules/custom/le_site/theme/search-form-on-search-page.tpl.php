<?php
/**
 * @file
 * Template for search form on page of search results.
 */
?>

<fieldset>
  <label><?php print t('Effectuer une nouvelle recherche'); ?></label>
</fieldset>
<fieldset>
  <?php print drupal_render($form['search_block_form']); ?>
  <?php print drupal_render($form['actions']['submit']); ?>
</fieldset>

<div style="display: none;">
  <?php print drupal_render($form['form_build_id']); ?>
  <?php print drupal_render($form['form_id']); ?>
  <?php print drupal_render($form['form_token']); ?>
</div>
