<?php
/**
 * @file
 * Template for a main le360 layout.
 */
?>
<div class="header">
  <?php echo $content['header']; ?>
</div>
<div id="wrapper">
  <div class="main">
    <?php echo $content['content']; ?>
  </div>
  <div id="sidebar">
    <div class="main">
      <?php echo $content['sidebar']; ?>
    </div>
  </div>
</div>
<footer class="footer" role="contentinfo">
  <?php echo $content['footer']; ?>
</footer>
