<?php
/**
 * @file
 * Specific template for image asset in Full build mode.
 */
?>
<div class="full-item">
  <div class="holder">
    <?php if (!empty($content['field_asset_image'])): ?>
      <?php print render($content['field_asset_image']); ?>
    <?php endif; ?>
    <?php if (!empty($content['field_asset_description'])): ?>
      <div class="desc"><p><?php print render($content['field_asset_description']); ?></p></div>
    <?php endif; ?>
  </div>
</div>
<?php if (!empty($content['field_asset_image_copyright'])): ?>
  <span class="copy-item">© Copyright : <?php print render($content['field_asset_image_copyright']); ?></span>
<?php endif; ?>
