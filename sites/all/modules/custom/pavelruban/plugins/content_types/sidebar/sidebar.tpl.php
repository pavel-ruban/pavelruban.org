<?php
/**
 * @file
 * Header template.
 */
?>
<?php if (!empty($rows)): ?>
    <h3 class="recent-posts"><span class="prefix">+</span> Recent Posts</h3>
    <ul class="recent-posts">
      <?php foreach ($rows as $row): ?>
        <li><?php echo $row; ?></li>
      <?php endforeach; ?>
    </ul>
    <h3>Get SSL CA certificate</h3>
    <ul>
      <li><a href="/get-and-set-ca-ssl-certificate-for-pavelrubanorg">download CA certificate</a></li>
    </ul>
<?php endif; ?>
