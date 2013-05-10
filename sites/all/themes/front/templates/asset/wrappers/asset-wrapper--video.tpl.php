<?php if (in_array($view_mode, array('in_body'))): ?>
  <div class="asset content-in-body wrapper">
    <?php print $content; ?>
  </div>
<?php else: ?>
  <?php print $content; ?>
<?php endif; ?>