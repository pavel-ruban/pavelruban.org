<?php
/**
 * @file
 * Panel pane template.
 */
?>
<?php if (strlen(trim($content)) > 0): ?>
  <?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
  <?php endif; ?>
  <div class="<?php print $classes; ?>" <?php print $id; ?>>
    <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
    <?php endif; ?>

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div class="pane-content">
      <?php print render($content); ?>
    </div>

  </div>
  <?php if ($pane_suffix): ?>
  <?php print $pane_suffix; ?>
  <?php endif; ?>
<?php endif; ?>
