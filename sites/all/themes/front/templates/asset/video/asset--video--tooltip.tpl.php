<?php
/**
 * @file
 * Template for render asset video in tooltip.
 */
?>
<div class="<?php print $classes; ?> block-fr3-image-gallery">
  <?php if ($content['field_asset_video']): ?>
    <?php print render($content['field_asset_video']); ?>
  <?php endif; ?>
  <?php if (!empty($content['field_asset_description'])): ?>
    <br />
    <?php print render($content['field_asset_description']); ?>
  <?php endif; ?>
</div>
