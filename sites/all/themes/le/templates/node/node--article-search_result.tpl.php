<?php
/**
 * @file
 * Template for article search view mode.
 */
?>

<div class="search-result-article">
  <?php if (!empty($img)): ?>
    <?php print $img; ?>
  <?php endif; ?>
  <div class="description">
    <h3 class="_titre">
      <?php print $title_link; ?>
    </h3>
    <div class="content">
      <div class="ftv_text">
        <?php if ($node->search_teaser): ?>
        <p class="descr"><?php print $node->search_teaser; ?></p>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
<div class="search-result-article-separator"></div>
