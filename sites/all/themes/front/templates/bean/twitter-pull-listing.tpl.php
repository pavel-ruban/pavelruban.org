<?php

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *   $tweet->time_ago
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 */
?>
<?php if (!empty($tweets)): ?>
  <div class="_block_side twitter">
    <div class="liveTwitter twtr-widget twtr-scroll widget-twitter" id="widget_twitter_<?php print $bloc_number; ?>">
      <div class="twtr-doc">
        <div class="twtr-hd">
          <h3>
            <?php print $search_url; ?>
          </h3>
        </div>
        <div class="twtr-bd">
          <div style="" class="twtr-timeline">
            <div class="twtr-tweets">
              <div class="twtr-reference-tweet">
              </div>
              <?php foreach ($tweets as $tweet): ?>
                <div id="tweet-id-<?php print $twitt_number; ?>" class="twtr-tweet">
                  <div class="twtr-tweet-wrap">
                    <div class="twtr-avatar">
                      <div class="twtr-img">
                        <?php print $user_images[$twitt_number]; ?>
                      </div>
                    </div>
                    <div class="twtr-tweet-text">
                      <p>
                        <?php print $user_name_links[$twitt_number]; ?>
                        <?php print $user_messages[$twitt_number]; ?>
                        <em>
                          <?php print $twitter_links[$twitt_number]['status']; ?>
                          ·
                          <?php print $twitter_links[$twitt_number]['reply']; ?>
                          ·
                          <?php print $twitter_links[$twitt_number]['retweet']; ?>
                          ·
                          <?php print $twitter_links[$twitt_number]['favorite']; ?>
                        </em>
                      </p>
                    </div>
                  </div>
                </div>
                <?php $twitt_number++; ?>
              <?php endforeach; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>
