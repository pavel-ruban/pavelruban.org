<?php
/**
 * @file
 * Template for related articles view mode.
 */
?>
<div class="img">
  <?php if (!empty($media_content)): ?>
    <?php print $media_content; ?>
  <?php endif; ?>
</div>
<?php if (!empty($title_link)): ?>
  <p><?php print $title_link; ?></p>
<?php endif; ?>
