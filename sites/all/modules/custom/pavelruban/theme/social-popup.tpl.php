<?php if (!empty($social_meta)): ?>
  <div id="vk-like-<?php echo $nid; ?>"></div>
  <script type="text/javascript">
    jQuery(document).ready(function() {
      setTimeout(function() {
        VK.Widgets.Like(
          'vk-like-<?php echo $nid; ?>',
          {
            pageImage: '<?php echo $social_meta['image']; ?>',
            pageTitle: '<?php echo $social_meta['title']; ?>',
            pageDescription: "<?php  echo $social_meta['description']; ?>",
            pageUrl: '<?php echo $social_meta['url']; ?>',
            height: 20,
            type: 'button'
          }
        );
      }, 2000)
    })
  </script>
  <a href="https://twitter.com/share"
     data-text="<?php echo $social_meta['tweeter_text']; ?>"
     data-url="<?php echo $social_meta['url']; ?>"
     data-counturl="<?php echo $social_meta['raw_url']; ?>"
    <?php if (!empty($social_meta['hashtags'])): ?>
      data-hashtags="<?php echo $social_meta['hashtags']; ?>"
    <?php endif; ?>
     class="twitter-share-button"
     data-lang="en"
  >Tweet</a>

  <div class="fb-like" data-href="<?php echo $social_meta['url']; ?>" data-send="false" data-layout="button_count" data-width="450" data-show-faces="true"></div>
<?php endif; ?>