<?php
/**
 * @file
 * Template for taxonomy-term in event view mode.
 */

?>
<div class="mea_main">
  <?php if (!empty($media_content)): ?>
    <?php print $media_content; ?>
  <?php endif; ?>
  <div class="description">
    <h2 class="_titre"><?php print $name; ?></h2>
    <?php if (!empty($date_start) && !empty($date_end)): ?>
      <h3 class="_soustitre"><?php print "- Du $date_start au $date_end"; ?></h3>
    <?php endif; ?>
    <?php if (!empty($date_start) && empty($date_end)): ?>
      <h3 class="_soustitre"><?php print "- Du $date_start"; ?></h3>
    <?php endif; ?>
    <?php if (!empty($date_end) && empty($date_start)): ?>
      <h3 class="_soustitre"><?php print "Au $date_end"; ?></h3>
    <?php endif; ?>
    <div class="content">
      <ul class="links">
        <?php if (!empty($site_officiel)): ?>
          <li class="link_site"><?php print $site_officiel; ?></li>
        <?php endif; ?>

        <?php if (!empty($facebook)): ?>
          <li class="link_facebook"><?php print $facebook; ?></li>
        <?php endif; ?>

        <?php if (!empty($twitter)): ?>
          <li class="link_twitter last"><?php print $twitter; ?></li>
        <?php endif; ?>
      </ul>
      <div class="text">
        <?php if (!empty($description)): ?>
          <?php print $description; ?>
        <?php endif; ?>
      </div>
    </div>
    <div class="facebook_like">
      <a href="/taxonomy/term/<?php print $tid; ?>" class="facebook recommend button_count" width="100"></a>
    </div>
  </div>
</div>
