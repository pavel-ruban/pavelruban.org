<?php if ($view_mode == 'dashboard_article_thumbnail'): ?>
  <?php print $content; ?>
<?php else: ?>
  <div <?php print $attributes; ?>><?php print $content; ?></div>
<?php endif; ?>
