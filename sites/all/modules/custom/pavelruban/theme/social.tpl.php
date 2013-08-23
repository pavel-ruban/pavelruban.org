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
      <?php if (!empty($voted)): ?>
        <?php $uri = "ajax/vote/node/$nid/delete"; ?>
      <?php else: ?>
        <?php $uri = "ajax/vote/node/$nid"; ?>
      <?php endif; ?>
      <a href="<?php echo url($uri); ?>" title="<?php echo !empty($voted) ? 'оценено' : 'мне нравится'; ?>" class="like-ajax-img<?php echo !empty($voted) ? ' voted' : ''; ?>"></a>
      <span><?php echo $votes_count; ?></span>
      <div class="like-popup-angle"></div>
      <div class="like-popup<?php echo $empty_likes_count ? ' empty' : ''; ?>">
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
          VK.Widgets.Like('vk-like-<?php echo $nid; ?>', {pageImage: '<?php echo $social_meta['image']; ?>', pageTitle: '<?php echo $social_meta['title']; ?>', pageDescription: '<?php  echo $social_meta['description']; ?>',  pageUrl: '<?php echo $social_meta['url']; ?>', height: 20, type: 'button'});
        </script>
        <a href="https://twitter.com/share"
          data-text="<?php echo $social_meta['tweeter_text']; ?>"
          data-url="<?php echo $social_meta['url']; ?>"
          data-counturl="<?php echo $social_meta['url']; ?>"
          class="twitter-share-button"
          data-lang="en"
        >
          Tweet
        </a>
        <div class="fb-like" data-href="<?php echo $social_meta['url']; ?>" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div>
      </div>
    </div>
  </div>
<?php else: ?>
   <div class="admin edit">
     <?php if (user_access('edit any article content')): ?>
       <a class="updated-info" href="<?php echo url("node/$nid/edit"); ?>" title="Обновлено"></a>
     <?php else: ?>
       <div class="updated-info" title="Обновлено"></div>
     <?php endif; ?>
     <span class="updated-text"><?php echo $last_changed; ?></span>
   </div>
<?php endif;?>
