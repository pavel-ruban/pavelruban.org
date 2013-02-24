<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 */
?>
<ul class="top360-list">
  <?php foreach ($view->result as $id => $res): ?>
    <li>
      <span class="num"><?php print $id + 1; ?></span>
      <div class="text">
        <span>
          <?php print l($res->node_title, 'node/' . $res->nid); ?>
        </span>
      </div>
    </li>
  <?php endforeach; ?>
</ul>
