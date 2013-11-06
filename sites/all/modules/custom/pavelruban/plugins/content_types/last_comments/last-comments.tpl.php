<?php
/**
 * @file
 * Header template.
 */
?>
<div class="last-comments">
  <?php if (!empty($last_comments)): ?>
    <h1 class="entryTitle">Recent Comments</h1>
    <?php foreach (array_reverse($last_comments) as $comment): ?>
      <?php if (!empty($comment['cid'])): ?>
        <?php $c = comment_load($comment['cid']); ?>
        <?php $c->recent_list = TRUE; ?>
        <?php $view = comment_view($c, node_load($comment['nid'])); ?>
        <?php echo render($view); ?>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php else: ?>
    <span><?php echo t('There is no any available new comments yet.'); ?></span>
  <?php endif; ?>
</div>
