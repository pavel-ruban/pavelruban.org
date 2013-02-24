<?php
/**
 * @file
 * Template for related articles view.
 */
?>
<div class="title">
  <h3><?php print t('LES CONTENUS LIÉS'); ?></h3>
</div>
<div class="<?php print $classes; ?> content-slider">

  <?php if ($rows): ?>
    <a href="#" class="btn-prev"><?php print t('prev'); ?></a>
    <a href="#" class="btn-next"><?php print t('next'); ?></a>
    <?php print $rows; ?>
  <?php elseif ($empty): ?>
    <?php print $empty; ?>
  <?php endif; ?>
</div>
