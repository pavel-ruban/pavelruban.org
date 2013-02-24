<?php
/**
 * @file
 * Template for field asset diaporama.
 */
?>

<?php if (count($items)) : ?><ul>
  <?php foreach ($items as $delta => $item): ?>
    <li><?php print render($item); ?></li>
  <?php endforeach; ?>
</ul>
<?php endif; ?>
