<?php
/**
 * @file
 * Template for article full view mode.
 */
?>

<?php if (!empty($rubrique)): ?>
  <span class="label-ttl"><span><?php print $rubrique; ?></span></span>
<?php endif; ?>

<?php if (!empty($share_top)): ?>
  <?php print $share_top; ?>
<?php endif; ?>

<div class="articles-holder">
  <h1><?php print $title; ?></h1>
  <span class="date-ttl">
    <?php if (!empty($signature)): ?>
      <?php print $signature; ?>
    <?php endif; ?>
  </span>

  <?php if (!empty($media_content)): ?>
    <?php print $media_content; ?>
  <?php endif; ?>

  <p class="marker"><?php print render($content['field_article_catchline']); ?></p>

  <?php if (!empty($content['field_body'])): ?>
    <?php print render($content['field_body']); ?>
  <?php endif; ?>

  <?php if (!empty($content['pagination_pager'])): ?>
    <?php print render($content['pagination_pager']); ?>
  <?php endif; ?>

</div>

<?php if (!empty($share_bottom)): ?>
  <?php print $share_bottom; ?>
<?php endif; ?>
