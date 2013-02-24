<?php
/**
 * @file
 * Template for field collection item field wrapper.
 */
 ?>
<?php if ($class == 'title'): ?>
  <h3>
<?php elseif ($class): ?>
  <div class="<?php print $class; ?>">
<?php endif; ?>
<?php print $elements['#children']; ?>
<?php if ($class == 'title'): ?>
  </h3>
<?php elseif ($class): ?>
  </div>
<?php endif; ?>
