<?php
/**
 * @file
 * Template.
 */
?>
<?php if (!empty($tags_info)): ?>
  <div class="tags">
    <?php foreach ($tags_info as $tag): ?>
      <?php echo l($tag['name'], "taxonomy/term/{$tag['tid']}", array('attributes' => array('class' => array('tag')), 'title' => $tag['name'])); ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
