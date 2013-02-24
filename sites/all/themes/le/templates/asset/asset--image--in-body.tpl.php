<?php
/**
 * @file
 * Specific template for image asset in In body build mode.
 */
?>
<div class="ftv_illustr">
  <?php if (!empty($content['field_asset_image'])): ?>
    <?php print render($content['field_asset_image']); ?>
  <?php endif; ?>
  <?php if (!empty($content['field_asset_image_copyright']) || !empty($content['field_asset_description'])): ?>
    <p class="ftv_legend">
      <?php print render($content['field_asset_description']); ?>
      <?php if (!empty($content['field_asset_image_copyright'])): ?>
        <span class="ftv_copyright">&copy; <?php print render($content['field_asset_image_copyright']); ?></span>
      <?php endif; ?>
    </p>
  <?php endif; ?>
</div>
