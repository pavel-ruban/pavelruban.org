<?php
/**
 * @file
 * Header template.
 */
?>
<div class="header-holder">
  <strong class="logo"><a href="<?php print base_path(); ?>">le360</a></strong>
  <nav>
    <ul>
      <?php foreach ($rubrique_links as $link): ?>
        <li><?php print $link; ?></li>
      <?php endforeach; ?>
    </ul>
  </nav>
  <ul class="top-nav">
    <ul class="top-nav">
      <li><span><a class="blog" href="#">Blogs 360</a></span></li>
      <li><span><a class="mail" href="#">mail</a></span></li>
      <li><span><a class="share" href="#">share</a></span></li>
      <li class="search-btn"><span><a class="search open-search-panel" href="#"><?php print t('search'); ?></a></span></li>
      <li><span><a class="arabe" href="#">العربية</a></span></li>
    </ul>
  </ul>
</div>
