<?php
/**
 * @file
 * Template for article full view mode.
 */
?>
<div class="header">
  <h1 class="_titre"><?php print $title; ?></h1>
  <?php if (!empty($signature)): ?>
    <p class="_soustitre">
      <?php print $signature; ?>
    </p>
  <?php endif; ?>
</div>

<div class="main">
  <div class="content">
    <div class="text">
      <?php if (!empty($content['field_article_catchline']) || !empty($content['field_body'])): ?>
        <?php if (!empty($content['field_article_catchline'])): ?>
          <p class="_summary">
            <?php print render($content['field_article_catchline']); ?>
          </p>
        <?php endif; ?>
        <?php if (!empty($content['field_body'])): ?>
          <p><?php print render($content['field_body']); ?></p>
        <?php endif; ?>
      <?php endif; ?>
    </div>
    <?php if (!empty($content['field_article_main_media'])): ?>
      <?php print render($content['field_article_main_media']); ?>
    <?php endif; ?>
  </div>
  <?php if (!empty($share_top)): ?>
    <div class="share">
      <?php print $share_top; ?>
    </div>
  <?php endif; ?>
</div>

<div class="meta" style="clear: none">
  <?php if (!empty($share)): ?>
    <div class="share">
      <?php print $share; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($read_more) || !empty($tags)): ?>
    <div class="related_articles">
      <?php if (!empty($read_more)): ?>
        <p class="_titre"><?php print t('Aller plus loin'); ?></p>
        <ul>
          <?php $num_items = count($read_mode); ?>
          <?php foreach ($read_more as $num => $item): ?>
            <?php $classes = array(); ?>
            <?php if ($num == 0) $classes[] = 'first'; ?>
            <?php if ($num == $num_items - 1) $classes[] = 'last'; ?>
            <?php $classes = !empty($classes) ? ' class="' . implode(' ', $classes) . '"' : ''; ?>
            <li<?php print $classes; ?>>
              <?php print $item; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      <?php endif; ?>
      <?php if (!empty($tags)): ?>
        <div class="tags">
          <?php print $tags; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
