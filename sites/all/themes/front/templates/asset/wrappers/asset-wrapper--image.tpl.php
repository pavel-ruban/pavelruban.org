<?php if (empty($asset->gallery_item) && in_array($view_mode, array('in_body', 'small', 'small_right'))): ?>
  <div class="asset content-<?php echo str_replace('_', '-', $view_mode); ?> wrapper">
    <?php print $content; ?>
  </div>
<?php // Allow view modes without rectangular borders, just raw image; ?>
<?php elseif (empty($asset->gallery_item) && in_array($view_mode, array('in_body_raw_width_auto', 'in_body_raw_height_288', 'in_body_raw_height_long',))): ?>
  <div class="asset content-<?php echo str_replace('_', '-', $view_mode); ?> raw">
    <?php print $content; ?>
  </div>
<?php else: ?>
  <?php print $content; ?>
<?php endif; ?>
