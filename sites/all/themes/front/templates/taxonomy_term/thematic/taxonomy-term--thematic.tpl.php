<?php
/**
 * @file
 * Template for taxonomy-term in event view mode.
 */
?>
<h2 class="header"><?php print $name; ?></h2>
<?php if (!empty($term_header_root)): ?>
<div class="header header-text">
  <p class="_soustitre"><?php print geopolis_site_l($term_header_root->name, 'taxonomy/term/' . $term_header_root->tid); ?></p>
</div>
<?php endif; ?>
<div class="description">
  <?php if (!empty($description)): ?>
    <p><?php print $description; ?></p>
  <?php endif; ?>
</div>
