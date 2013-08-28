<?php
/**
 * @file
 * Default template for image asset.
 */
?>
<?php if (!empty($image)): ?>
  <?php if (empty($elements['#disable_shadowbox']) && empty($asset->gallery_item) && !pavelruban_is_ajax()): ?>
    <a rel="shadowbox" href="<?php echo file_create_url($field_asset_image[0]['uri']); ?>" class="fullscreen-toggle"></a><?php echo $image; ?>
  <?php else: ?>
    <?php echo $image; ?>
  <?php endif; ?>
<?php endif; ?>

<?php if (!empty($asset->gallery_item)): ?>
  <?php unset($asset->gallery_item); ?>
<?php endif; ?>

<?php if (!empty($asset->gallery_name)): ?>
  <?php unset($asset->gallery_name); ?>
<?php endif; ?>
