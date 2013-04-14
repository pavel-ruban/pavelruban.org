<?php
/**
 * @file
 * Template.
 */
?>
<h1 class="comments">
  Comments:
</h1>
<?php if (!empty($comment_list)): ?>
  <?php echo $comment_list; ?>
<?php endif; ?>
<h1 class="comment-bottom-line<?php echo empty($comment_list) ? ' empty' : ''; ?>">
  <span><?php echo $add_comment_link; ?></span>
  <?php if (!empty($anonym)): ?>
    <span class="comment-login">
      <?php echo $login_comment_link; ?>
    </span>
  <?php endif; ?>
</h1>
