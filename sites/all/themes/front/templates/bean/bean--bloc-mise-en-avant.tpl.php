<?php
/**
 * @file
 * Default theme implementation for beans.
 */
?>
<?php if (!empty($image_link)): ?>
  <div class="mea">
    <div class="bloc">
      <p class="header"><?php print check_plain($bean->label); ?></p>
      <div class="content">
        <?php print $image_link; ?>
      </div>
    </div>
  </div>
<?php else: ?>
  <?php print ''; ?>
<?php endif; ?>
