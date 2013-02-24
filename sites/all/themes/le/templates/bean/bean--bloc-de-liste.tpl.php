<?php
/**
 * @file
 * Template for bean block de liste.
 */
?>
<div class="bloc block-fr3-simple">
  <p class="header"><?php print check_plain($bean->label); ?></p>
  <div class="content">
    <div class="block-culture-list block-partenaires-list">
      <?php if (!empty($items)): ?>
        <?php print theme('item_list', array('items' => $items, 'type' => 'ul', 'title' => NULL)); ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($content['field_bloc_read_more'])) : ?>
    <div class="block-view-all-link">
      <?php print render($content['field_bloc_read_more']); ?>
    </div>
  <?php endif; ?>
</div>
