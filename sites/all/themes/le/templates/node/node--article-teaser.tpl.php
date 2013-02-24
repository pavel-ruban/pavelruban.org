<?php
/**
 * @file
 * Template for article teaser view mode.
 */
?>
<?php if (!empty($content['field_slugs'])): ?>
  <p class="header"><?php print render($content['field_slugs']); ?></p>
<?php endif; ?>
<div class="content">
  <h3 class="header"><?php print $title_link; ?></h3>
  <?php if (!empty($tags)): ?>
    <div class="tags">
      <?php print $tags; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($article_media_link)): ?>
    <div class="illustration">
      <?php if ($is_diaporama_principal): ?>
        <?php print $article_media_link; ?>
      <?php else:?>
        <?php print $article_media_link; ?>
        <?php if ($is_video_principal): ?>
          <?php print $play_icon; ?>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
<div class="footer">
  <!-- <div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true" data-action="recommend" data-font="arial"></div> -->
  <div class="facebook_recommend">
    <div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true" data-action="recommend"></div>
  </div>
</div>
