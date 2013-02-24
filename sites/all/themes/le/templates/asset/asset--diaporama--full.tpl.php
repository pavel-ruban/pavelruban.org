<?php if (empty($asset->in_editor)): ?>
  <div class="diaporama<?php print ' ' . $counter; ?>">
    <ul class="_main">
      <?php if(!empty($diaporama_items_list)): ?>
        <?php foreach ($diaporama_items_list as $item): ?>
          <li class="<?php print $item['type']; ?>">
            <?php print $item['content']; ?>
            <?php if (!empty($item['video'])): ?>
              <?php print $item['video']; ?>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      <?php endif; ?>
    </ul>
  </div>
  <?php if (!empty($content['field_asset_description'])): ?>
    <div class="diaporama-description">
      <em>
        <?php print render($content['field_asset_description']); ?>
      </em>
    </div>
  <?php endif; ?>
<?php else: ?>
  <div class="diaporama">
    <ul class="_main">
      <?php if(!empty($diaporama_items_list)): ?>
        <?php foreach ($diaporama_items_list as $item): ?>
          <li class="<?php print $item['type']; ?>">
            <?php print $item['content']; ?>
          </li>
        <?php endforeach; ?>
      <?php endif; ?>
    </ul>
  </div>
  <?php if (!empty($content['field_asset_description'])): ?>
    <br />
    <div class="diaporama-description">
      <em>
        <?php print render($content['field_asset_description']); ?>
      </em>
    </div>
  <?php endif; ?>
<?php endif; ?>
