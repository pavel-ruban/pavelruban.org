<?php
/**
 * @file
 * Template for a main le360 layout.
 */
?>
<div class="search-panel">
  <div class="holder">
    <?php print $content['search_panel']; ?>
  </div>
</div>

<header>
  <?php print $content['header']; ?>
</header>

<section id="main">
  <?php print theme('status_messages'); ?>
  <?php print $content['content']; ?>
</section>

<footer>
  <?php print $content['footer']; ?>
</footer>
