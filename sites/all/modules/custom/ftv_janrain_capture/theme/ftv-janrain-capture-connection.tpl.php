<div class="ftv-janrain-catpure ftv-janrain-catpure-anonymous">
  <?php print $variables['user_links_anonymous']; ?>
</div>
<div class="ftv-janrain-catpure ftv-janrain-catpure-authenticated">
  <?php print $variables['user_links_authenticated']; ?>
</div>
<?php print l(t('Refresh user informations'), 'janrain_capture/user/nojs', array('attributes' => array('class' => array('use-ajax'), 'id' => 'ftv-janrain-catpure-user-ajax', 'style' => 'display:none'), 'query' => drupal_get_destination())); ?>
