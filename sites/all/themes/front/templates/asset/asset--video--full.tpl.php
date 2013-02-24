<div class='video'>
  <?php print render($content['field_asset_video']); ?>
  <?php if(!empty($description)): ?>
    <?php if(!empty($asset->in_editor)): ?>
      <br>
    <?php endif; ?>
    <em>
      <?php print $description; ?>
    </em>
  <?php endif; ?>
</div>
