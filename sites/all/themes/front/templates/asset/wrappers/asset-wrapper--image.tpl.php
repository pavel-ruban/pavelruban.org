<?php if (empty($asset->gallery_item) && in_array($view_mode, array('in_body', 'small', 'small_right'))): ?>
  <div class="asset content-<?php echo str_replace('_', '-', $view_mode); ?> wrapper">
    <?php print $content; ?>
  </div>
<?php else: ?>
  <?php print $content; ?>
<?php endif; ?>
