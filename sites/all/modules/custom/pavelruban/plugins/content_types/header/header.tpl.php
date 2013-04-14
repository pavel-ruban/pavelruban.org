<?php
/**
 * @file
 * Header template.
 */
?>
<div class="logo">
  <?php if (!empty($image)): ?>
    <?php echo l(
      '',
      '<front>',
      array(
        'html' => TRUE,
        'attributes' => array('class' => array('logo-img')),
      )
    ); ?>
  <?php endif; ?>
</div>
<div class="menu">
<!--  <a href="#">Minds</a>-->
<!--  <a href="#">Forum</a>-->
<!--  <a href="#">About me</a>-->
  <?php echo $user_link; ?>
  <?php if (!empty($user_logout)): ?>
    <?php echo $user_logout; ?>
  <?php endif; ?>
</div>
