<?php
/**
 * @file
 * Template for article full view mode.
 */
?>
<?php if (!empty($media)): ?>
  <?php echo l($media, "node/{$node->nid}", array('html' => 1)); ?>
<?php endif; ?>
<h2><?php echo l($title, "node/{$node->nid}"); ?></h2>
<p class="img"><?php echo $description; ?></p>
