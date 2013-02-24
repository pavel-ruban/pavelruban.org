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

  <?php if (!empty($content['field_article_main_media'])): ?>
    <div class="full-item video-content">
      <div class="holder">
        <?php print render($content['field_article_main_media']); ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="wording-article">
    <strong class="logo-tv"><?php echo l('le360', '<front>'); ?></strong>
    <p><?php print render($content['field_article_catchline']); ?></p>
  </div>
</div>
