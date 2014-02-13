<?php
/**
 * @file
 * Template.
 */
?>
<?php if ((empty($mode) || $mode == 'teaser') || (empty($part) || $part == 'bottom')): ?>
  <div class="statistic">
    <?php if (empty($mode) || $mode == 'teaser'): ?>
      <?php if (user_access('edit any article content')): ?>
        <a class="updated-info" href="<?php echo url("node/$nid/edit"); ?>" title="Обновлено"></a>
      <?php else: ?>
        <div class="updated-info" title="Обновлено"></div>
      <?php endif; ?>
      <span class="updated-text"><?php echo $last_changed; ?></span>
    <?php endif; ?>
    <div class="like-info">
      <?php echo $like_link; ?>
      <span>
        <?php echo $votes_count; ?>
      </span>
      <div class="like-popup-angle"></div>
      <div class="like-popup<?php echo $empty_likes_count ? ' empty' : ''; ?>">
        <?php if (!empty($like_popup)): ?>
          <?php echo $like_popup; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="comments-info" title="комментариев">
      <?php echo $comment_link; ?>
      <span><?php echo $comment_count; ?></span>
    </div>
    <div class="views-quantity">
      <div class="views-quantity-img" title="просмотров"></div>
      <span><?php echo $access_count; ?></span>
    </div>
  </div>
<?php else: ?>
  <div class="admin edit">
    <?php if (!empty($edit_info_link)): ?>
      <?php echo $edit_info_link; ?>
    <?php else: ?>
      <div class="updated-info" title="Обновлено"></div>
    <?php endif; ?>
    <span class="updated-text"><?php echo $last_changed; ?></span>
  </div>
<?php endif; ?>
