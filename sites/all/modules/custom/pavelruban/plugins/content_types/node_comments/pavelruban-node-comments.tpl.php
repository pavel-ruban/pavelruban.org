<?php
/**
 * @file
 * Template.
 */
?>
<h1 class="entryTitle">
  Comments:<span class="comment-login"><?php echo $login_comment_link; ?></span>
</h1>
<?php if (!empty($comment_list)): ?>
  <?php echo $comment_list; ?>
<?php endif; ?>
<h1 class="comment-bottom-line"><span><?php echo $add_comment_link; ?></span></h1>
