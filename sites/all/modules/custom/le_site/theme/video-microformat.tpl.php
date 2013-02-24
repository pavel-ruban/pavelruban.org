<?php
/**
 * @file
 * Template for video microformat.
 */
?>
<div itemprop="video" itemscope itemtype="http://schema.org/VideoObject">

  <span class="google-schema-item" itemprop="name"><?php print $video['title']; ?></span>

  <meta itemprop="thumbnailUrl" content="<?php print $video['preview']['snapshot']; ?>" />

  <?php if ($video['url']): ?>
    <meta itemprop="embedURL" content="<?php print $video['url']; ?>" />
  <?php endif; ?>

  <meta itemprop="uploadDate" content="<?php print $video['date']; ?>" />

  <?php print $emcode; ?>

  <span class="google-schema-item" itemprop="description"><?php print $video['description']; ?></span>
</div>
