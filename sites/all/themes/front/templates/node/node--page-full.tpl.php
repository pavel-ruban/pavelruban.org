<?php
/**
 * @file
 * Template for page full view mode.
 */

?>

<?php if (empty($is_404) && empty($is_403)): ?>
  <?php if (!empty($media)): ?>
    <?php echo $media; ?>
  <?php endif; ?>

  <h2><?php echo $title; ?></h2>

  <?php if (!empty($description)): ?>
    <?php echo $description; ?>
    <br/>
  <?php endif; ?>
<?php endif; ?>

<?php echo $body; ?>