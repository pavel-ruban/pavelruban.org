<?php
/**
 * @file
 * Template for sharing widgets and links.
 */
?>

<?php if ($mode == 'bottom'): ?>
  <div class="social-bar-bottom">
    <ul class="social-list">
      <li><div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div></li>
      <li><a href="https://twitter.com/share" class="twitter-share-button" data-via="Le360" data-lang="fr">Tweeter</a></li>
      <li><div class="g-plusone" data-size="medium"></div></li>
      <li><img src="<?php print LE_THEME_PATH; ?>/images/ico-bullet.gif" height="20" width="45" alt=""></li>
    </ul>
    <?php if (!empty($data['author'])): ?>
      <h3><?php print $data['author']; ?></h3>
    <?php endif; ?>
  </div>
<?php elseif ($mode == 'top'): ?>
  <div class="social-bar">
    <ul class="social-list">
      <li><div class="fb-like" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div></li>
      <li><a href="https://twitter.com/share" class="twitter-share-button" data-via="Le360" data-lang="fr">Tweeter</a></li>
      <li><div class="g-plusone" data-size="medium"></div></li>
      <li><img src="<?php print LE_THEME_PATH; ?>/images/ico-bullet.gif" height="20" width="45" alt=""></li>
    </ul>
  </div>
<?php endif; ?>
