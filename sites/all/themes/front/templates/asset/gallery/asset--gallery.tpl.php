<?php
/**
 * @file
 * Template for diaporama tooltip.
 */
?>
<?php static $counter = 1; ?>
<?php if (!empty($field_asset_gallery_images)): ?>
  <?php if (empty($asset->in_editor)): ?>
    <div id="wowslider-container<?php echo $counter;?>">
      <?php $counter++; ?>
      <div class="ws_images">
        <ul>
          <?php foreach ($field_asset_gallery_images as $item): ?>
            <li>
              <?php $item['entity']->gallery_item = TRUE; ?>
              <?php $item['entity']->gallery_name = $title; ?>
              <?php print render(entity_view('asset', array($item['entity']), 'slider_viewport')); ?>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>
      <div class="ws_thumbs">
        <div>
          <?php foreach ($field_asset_gallery_images as $item): ?>
            <?php $item['entity']->gallery_item = TRUE; ?>
            <?php print render(entity_view('asset', array($item['entity']), 'slider_thumbnail')); ?>
          <?php endforeach; ?>
        </div>
      </div>
      <div class="ws_shadow"></div>
      <a class="fullscreen-toggle"></a>
    </div>
  <?php else: ?>
    <div>
      <?php for($i = 0; $i < 9; $i++): ?>
        <?php if (!empty($field_asset_gallery_images[$i])): ?>
          <?php $item['entity']->gallery_item = TRUE; ?>
          <?php print render(entity_view('asset', array($field_asset_gallery_images[$i]['entity']), 'slider_thumbnail')); ?>
        <?php else: ?>
          <a><img></a>
        <?php endif; ?>
      <?php endfor; ?>
    </div>
  <?php endif; ?>
<?php endif; ?>


