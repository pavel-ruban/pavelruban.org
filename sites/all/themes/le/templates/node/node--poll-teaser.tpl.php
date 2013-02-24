<?php
/**
 * @file
 * Template for poll teaser view mode.
 */
?>
<div class="<?php print $classes; ?>">

  <?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>

  <?php if (!empty($content['poll_view_voting'])): ?>
    <div class="content">
      <?php print render($content['poll_view_voting']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['poll_view_results'])): ?>
    <div class="content">
      <?php print render($content['poll_view_results']); ?>
    </div>
  <?php endif; ?>
</div>
