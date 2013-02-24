<?php
/**
 * @file
 * Template for wrapper of asset with type diaporama.
 */
?>

<?php if ($view_mode == 'tooltip' || $view_mode == 'full'
  || $view_mode == 'premium_diaporama' || $view_mode == 'diaporama_teaser'): ?>
  <?php print $content; ?>
<?php else: ?>
  <div <?php print $attributes; ?>><?php print $content; ?></div>
<?php endif; ?>
