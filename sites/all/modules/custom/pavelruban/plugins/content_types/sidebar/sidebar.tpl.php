<?php
/**
 * @file
 * Header template.
 */
?>
<div id="sidebar">
  <?php if (!empty($rows)): ?>
    <div class="main">
      <h3>Recent Posts</h3>
      <ul class="recent-posts">
        <?php foreach ($rows as $row): ?>
          <li><?php echo $row; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
</div>
