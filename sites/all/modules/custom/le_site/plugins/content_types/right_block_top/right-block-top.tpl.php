<?php
/**
 * @file
 * Header template.
 */
?>
<div class="top360">
  <div class="title">
    <h3><?php print t('TOP 360'); ?></h3>
  </div>
  <ul class="tabset top360-nav">
    <li><a class="active" href="#tab1"><?php print t('Articles'); ?></a></li>
    <li><a href="#tab2" class=""><?php print t('Vidéos'); ?></a></li>
    <li><a href="#tab3" class=""><?php print t('Photos'); ?></a></li>
  </ul>
  <?php print $views['articles']; ?>
  <?php print $views['videos']; ?>
  <?php print $views['diaporamas']; ?>
</div>
