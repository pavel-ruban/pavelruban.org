<?php
/**
 * @file
 * Template for fb comments.
 */
?>
<div class="title">
  <h3><?php print t('Vos commentaires'); ?></h3>
</div>
<div class="facebook-widget">
  <div class="fb-like" data-href="<?php print $url; ?>" data-send="false" data-width="450" data-show-faces="true"></div>
  <div class="fb-comments" data-href="<?php print $url; ?>" data-width="599" data-num-posts="2"></div>
</div>
