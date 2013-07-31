<?php
/**
 * @file
 * Template.
 */
?>
<?php if (empty($mode) || $mode == 'teaser'): ?>
  <?php if (empty($likedCount)): ?>
    <a class="like-quantity">
      Зарегестрированных нет
    </a>
  <?php elseif ($likedCount == 1): ?>
    <a href="<?php echo url("ajax/full-voted-user-statistic/$nid"); ?>" class="like-quantity">
      Понравилось 1 человеку:
    </a>
  <?php else: ?>
    <a href="<?php echo url("ajax/full-voted-user-statistic/$nid"); ?>" class="like-quantity">
      Понравилось <?php echo $likedCount; ?> людям:
    </a>
  <?php endif; ?>
  <br>
  <?php echo $likedUsers; ?>
<?php else: ?>
  <div class="people-popup">
  <div class="people-popup-header">
    <?php if ($likedCount == 1): ?>
      <span class="people-popup-title">Понравилось 1 человеку:</span>
    <?php else: ?>
      <span class="people-popup-title">Понравилось <?php echo $likedCount; ?> людям:</span>
    <?php endif; ?>
    <a href="#" class="fancybox-close-link">закрыть</a>
  </div>
  <?php echo $likedUsers; ?>
<?php endif; ?>
