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
<p class="img"><?php echo preg_replace('/<\s*?\/?p\s*?>/', '', $body); ?></p>
