<?php
/**
 * @file
 * Template for article choose video view mode.
 */
?>
<p class="header">
  <?php print $header; ?>
</p>
<h2 class="_titre">
  <?php print $title_link; ?>
</h2>
<div class="content">
  <?php print $image_link; ?>
  <div class="footer">
    <div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true" data-action="recommend" data-font="arial">
    </div>
  </div>
</div>
<?php if(!empty($content['field_article_catchline'])): ?>
  <div class="chapo">
    <?php print render($content['field_article_catchline']); ?>
  </div>
<?php endif; ?>
