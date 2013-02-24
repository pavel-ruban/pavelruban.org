<?php
/**
 * @file
 * Template for feed_item teaser.
 */
?>

<div class="mea_blog">
  <div class="header">
    <?php print $blog_image; ?>
    <h4 class="_titre">
      <?php print $title_link; ?>
    </h4>
    <p class="_soustitre"><?php print check_plain($parent_title); ?></p>
  </div>
  <div class="content">
    <?php print $field_feed_item_description[0]['value']; ?>
    <?php print $more_link; ?>
  </div>
</div>