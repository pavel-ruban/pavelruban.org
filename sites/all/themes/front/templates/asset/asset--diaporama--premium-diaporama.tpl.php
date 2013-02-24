<?php
/**
 * @file
 * Premiun diaporama asset template.
 */
?>
<div id="diaporama_premium">
  <div class="display loading">
    <ul class="_main">
      <?php if(!empty($diaporama_items_list)): ?>
        <?php foreach ($diaporama_items_list as $item): ?>
          <li class="<?php print $item['type']; ?>">
            <div class="ftv_media">
              <?php if (!empty($item['video'])): ?>
                <?php print $item['content']; ?>
                <?php print $item['video']; ?>
              <?php else: ?>
                <?php print $item['content']; ?>
              <?php endif; ?>
            </div>
            <div class="ftv_body">
              <h2 class="ftv_title">
                <?php print $item['title']; ?>
              </h2>
              <div class="ftv_desc">
                <?php print $item['description']; ?>
              </div>
              <?php if (!empty($item['copyright'])): ?>
                <p class="ftv_legend">
                  <span class="ftv_copyright">&copy; <?php print $item['copyright']; ?>
                  </span>
                </p>
              <?php endif; ?>
            </div>
          </li>
        <?php endforeach; ?>
      <?php endif; ?>
    </ul>
  </div>
</div>
