<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 */
?>
<ul class="top360-list">
  <?php foreach ($rows as $id => $row): ?>
  <li>
    <span class="num"><?php print $id + 1; ?></span>
    <div class="text">
      <?php print $row; ?>
    </div>
  </li>
  <?php endforeach; ?>
</ul>
