<?php
/**
 * @file
 * Header template.
 */
?>

<div class="footer-top">
  <div class="footer-holder">
    <div class="column">
      <div class="ttl">
        <h3><span>Sondage 360</span></h3>
      </div>
      <p>Titre du sondage en relation ou pas qui peut aller sur deux lignes</p>
      <form action="#">
        <fieldset>
          <ul class="review-list">
            <li>
              <div class="radioAreaChecked"></div><input checked="checked" class="outtaHere" id="lbl04" name="footer-rd" type="radio">
              <label for="lbl04">Réponse à la question du sondage qui peut aussi aller sur deux lignes</label>
            </li>
            <li>
              <div class="radioArea"></div><input class="outtaHere" id="lbl05" name="footer-rd" checked="checked" type="radio">
              <label for="lbl05">Réponse à la question du sondage qui peut aussi aller sur deux lignes</label>
            </li>
            <li>
              <div class="radioArea"></div><input class="outtaHere" id="lbl06" name="footer-rd" type="radio">
              <label for="lbl06">Réponse à la question du sondage qui peut aussi aller sur deux lignes</label>
            </li>
          </ul>
          <input class="btn-submit" value="VOTER" type="submit">
        </fieldset>
      </form>
    </div>
    <div class="column">
      <div class="ttl">
        <h3><span><?php echo t('Le 360 en un clic'); ?></span></h3>
      </div>
      <?php if (!empty($footer_menu)): ?>
        <div class="holder">
          <?php foreach($footer_menu as $side): ?>
            <ul class="footer-list">
              <?php foreach($side as $link): ?>
                <li><?php echo $link; ?></li>
              <?php endforeach; ?>
            </ul>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="column-last">
      <div class="ttl">
        <h3><span>Suivez-nous !</span></h3>
      </div>
      <ul class="footer-soc-list">
        <li><a class="facebook" href="#">facebook</a></li>
        <li><a class="twitter" href="#">twitter</a></li>
        <li><a class="youtube" href="#">youtube</a></li>
        <li><a class="google" href="#">google</a></li>
        <li><a class="linkedin" href="#">linkedin</a></li>
        <li><a class="pinterest" href="#">pinterest</a></li>
        <li><a class="email" href="#">email</a></li>
        <li><a class="rss" href="#">rss</a></li>
      </ul>
      <div class="newletter-form">
        <h4>Abonnement Newsletter</h4>
        <p>Saisissez votre adresse email pour recevoir la newsletter du 360.</p>
        <form action="#">
          <fieldset>
            <div class="row">
              <div class="text-form ">
                <input class=" " value="" type="text">
              </div>
              <input class="btn-submit" value="ENOYER" type="submit">
            </div>
          </fieldset>
        </form>
      </div>
    </div>
  </div>
</div>
<div class="footer-bottom">
  <div class="footer-holder">
    <strong class="logo-footer"><?php echo l('le360', '<front>'); ?></strong>
    <span class="copy"><?php echo t('© Web News / le 360.ma / Tout droit réservé 2013'); ?></span>
  </div>
</div>

