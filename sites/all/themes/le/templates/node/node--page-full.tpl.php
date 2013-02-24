<?php
/**
 * @file
 * Template for page full view mode.
 */

?>
<div class="_block page-misc last">
  <h1 class="_head"><?php print $title; ?></h1>
  <div class="ftv_text last">
  <?php if (!empty($body)): ?>
    <?php print $body; ?>
  <?php endif; ?>
  </div>
</div>    
