<?php
/**
 * @file
 * Header template.
 */
?>

<?php if (!empty($home_img_link)): ?>
  <div class="home-link">
    <?php echo $home_img_link; ?>
  </div>
<?php endif; ?>

<?php if (!empty($git_img_link)): ?>
  <div class="git-link">
    <?php echo $git_img_link; ?>
  </div>
<?php endif; ?>

<?php if (!empty($admin_img_link)): ?>
  <div class="admin-link">
    <?php echo $admin_img_link; ?>
  </div>
<?php endif; ?>

<?php if (!empty($last_comments)): ?>
  <div class="last-comment-counter">
    <?php echo $last_comments; ?>
  </div>
<?php endif; ?>

<div class="menu">
<!--  <a href="#">Minds</a>-->
<!--  <a href="#">Forum</a>-->
  <?php echo $aboutme_link; ?>
  <?php echo $user_link; ?>

  <?php if (!empty($user_logout)): ?>
    <?php echo $user_logout; ?>
  <?php endif; ?>
</div>
