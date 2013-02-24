<div class="<?php print $classes; ?> block-fr3-image-gallery">
  <h4><?php print $title; ?></h4>
  <div class="block-gallery-items">
    <div class="block-fr3-gallery-carousel">
      <div class="item-list">
        <?php print render($content['field_asset_diaporama']); ?>
      </div>
      <div class="block-pager-trigger">
        <ul class="pager"><li class="first"><?php print t('Prev'); ?></li><li class="last"><?php print t('Next'); ?></li></ul>
      </div>
    </div>
  </div>
  <div class="block-gallery-preview">
    <div class="item-list">
      <ul><?php foreach ($preview_images as $img) : ?>
        <li><a href="javascript:;"><?php print $img; ?><span class="prv-mask">&nbsp;</span></a></li>
        <?php endforeach; ?></ul>
    </div>
  </div>
  <?php if (!empty($content['field_asset_description'])): ?>
    <br />
    <div class="diaporama-description">
        <em>
          <?php kpr($content);die;print render($content['field_asset_description']); ?>
        </em>
    </div>
  <?php endif; ?>
</div>
