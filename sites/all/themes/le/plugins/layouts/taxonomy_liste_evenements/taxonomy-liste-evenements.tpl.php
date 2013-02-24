<?php
/**
 * @file
 * Template for a geopolis content page layout.
 */
?>

<div class="site_content">
  <div class="term-listing-heading">
    <div class="liste_evenements liste">
      <?php print $content['column_left']; ?>
    </div>
  </div>
</div>

<div class="site_side">
  <?php print $content['column_right']; ?>
</div>
