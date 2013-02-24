<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 */
?>
<div class="holder">
  <ul class="content-slider-list">
    <?php foreach ($rows as $id => $row): ?>
      <li><?php print $row; ?></li>
    <?php endforeach; ?>
  </ul>
</div>
