<?php
/**
 * @file
 * Template.
 */
?>
<?php if (empty($mode) || $mode == 'teaser'): ?>
  <div class="statistic">
    <?php if (user_access('edit any article content')): ?>
      <a class="updated-info" href="<?php echo url("node/$nid/edit"); ?>" title="Обновлено"></a>
    <?php else: ?>
      <div class="updated-info" title="Обновлено"></div>
    <?php endif; ?>
    <span class="updated-text"><?php echo $last_changed; ?></span>
    <div class="like-info">
      <a href="<?php echo url("ajax/vote/node/$nid"); ?>" title="<?php echo !empty($voted) ? 'вы уже оставили свой голос' : 'мне нравится'; ?>" class="like-ajax-img<?php echo !empty($voted) ? ' voted' : ''; ?>"></a>
      <span><?php echo $votes_count; ?></span>
      <div class="like-popup-angle"></div>
      <div class="like-popup">
        <?php if (!empty($like_popup)): ?>
          <?php echo $like_popup; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="comments-info" title="комментариев">
      <?php echo l('', "node/$nid", array('html' => TRUE, 'fragment' => 'comment-end', 'attributes' => array('class' => array("comments-img")))); ?>
      <span><?php echo $comment_count; ?></span>
    </div>
    <div class="views-quantity">
      <div class="views-quantity-img" title="просмотров"></div>
      <span><?php echo $access_count; ?></span>
    </div>
    <div class="social">
      <div class="social-img" title="социальные сети"></div>
      <div class="social-popup-angle" style=""></div>
      <div class="social-popup">
        <div id="vk-like-<?php echo $nid; ?>"></div>
        <script type="text/javascript">
         VK.Widgets.Like('vk-like-<?php echo $nid; ?>', {pageUrl: 'node/<?php echo $nid; ?>'});
        </script>
        <a href="https://twitter.com/share" data-text="<?php echo truncate_utf8("$share_title | $share_description", 90, TRUE, TRUE); ?>" data-url="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>" data-counturl="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>"class="twitter-share-button" data-lang="en">Tweet</a>
        <div class="fb-like" data-href="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div>
      </div>
    </div>
  </div>
<?php else: ?>
  <?php if (empty($part) || $part == 'bottom'): ?>
    <div class="statistic">
      <div class="like-info">
        <a href="<?php echo url("ajax/vote/node/$nid"); ?>" title="<?php echo !empty($voted) ? 'вы уже оставили свой голос' : 'мне нравится'; ?>" class="like-ajax-img<?php echo !empty($voted) ? ' voted' : ''; ?>"></a>
        <span><?php echo $votes_count; ?></span>
        <div class="like-popup-angle"></div>
        <div class="like-popup">
          <?php if (!empty($like_popup)): ?>
            <?php echo $like_popup; ?>
          <?php endif; ?>
        </div>
      </div>
      <div class="comments-info" title="комментариев">
        <?php echo l('', "node/$nid", array('html' => TRUE, 'fragment' => 'comment-end', 'attributes' => array('class' => array("comments-img")))); ?>
        <span><?php echo $comment_count; ?></span>
      </div>
      <div class="views-quantity">
        <div class="views-quantity-img" title="просмотров"></div>
        <span><?php echo $access_count; ?></span>
      </div>
      <div class="social">
        <div class="social-img" title="социальные сети"></div>
        <div class="social-popup-angle" style=""></div>
        <div class="social-popup">
          <div id="vk-like-<?php echo $nid; ?>"></div>
          <script type="text/javascript">
           VK.Widgets.Like('vk-like-<?php echo $nid; ?>', {pageUrl: 'node/<?php echo $nid; ?>'});
          </script>
          <a href="https://twitter.com/share" data-text="<?php echo truncate_utf8("$share_title | $share_description", 90, TRUE, TRUE); ?>" data-url="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>" data-counturl="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>"class="twitter-share-button" data-lang="en">Tweet</a>
          <div class="fb-like" data-href="<?php echo url("node/$nid", array('absolute' => TRUE, 'alias' => TRUE)); ?>" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div>
        </div>
      </div>
    </div>
  <?php else:?>
      <div class="admin edit">
        <?php if (user_access('edit any article content')): ?>
          <a class="updated-info" href="<?php echo url("node/$nid/edit"); ?>" title="Обновлено"></a>
        <?php else: ?>
          <div class="updated-info" title="Обновлено"></div>
        <?php endif; ?>
        <span class="updated-text"><?php echo $last_changed; ?></span>
      </div>
  <?php endif;?>
<?php endif;?>
