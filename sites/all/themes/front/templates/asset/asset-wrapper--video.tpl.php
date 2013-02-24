<?php if (in_array($view_mode, array('in_body', 'full', 'diaporama_teaser', 'premium_diaporama', 'video_article'))): ?>
  <?php print $content; ?>
<?php else: ?>
  <div <?php print $attributes; ?>><?php print $content; ?></div>
<?php endif; ?>
