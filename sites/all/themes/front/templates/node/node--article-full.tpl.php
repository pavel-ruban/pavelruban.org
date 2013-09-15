<?php
/**
 * @file
 * Template for article full view mode.
 */
?>
<?php if (!empty($media)): ?>
  <?php echo $media; ?>
<?php endif; ?>
<h2><?php echo $title; ?></h2>
<?php echo $description; ?>
<br/>
<?php echo $body; ?>
<?php if (!empty($tags)): ?>
  <?php echo $tags; ?>
<?php endif; ?>
