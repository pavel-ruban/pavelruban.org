/**
 * @file
 * JavaScript for the FTV Disqus Drupal module.
 */

// The Disqus global variables.
var disqus_shortname = '';
var disqus_url = '';
var disqus_title = '';
var disqus_identifier = '';
var disqus_developer = 0;
var disqus_def_name = '';
var disqus_def_email = '';
var disqus_config;


(function ($) {
/**
 * Drupal Disqus behavior.
 */
Drupal.behaviors.ftv_disqus = {
  attach: function (context, settings) {
    $('body').once('disqus', function() {
      // Load the Disqus comments.
      if (settings.disqus || false) {
        // Setup the global JavaScript variables for Disqus.
        disqus_shortname = settings.disqus.domain;
        disqus_url = settings.disqus.url;
        disqus_title = settings.disqus.title;
        disqus_identifier = settings.disqus.identifier;
        disqus_developer = settings.disqus.developer || 0;
        disqus_def_name = settings.disqus.name || '';
        disqus_def_email = settings.disqus.email || '';
      }
    });
  }
};


$(function() {
  Drupal.ajax.prototype.commands.ftv_disqus_user_config = function (ajax, response, status) {
    var disqus_override_config = response.data.disqus_override_config;

    // Language and SSO settings are passed in through disqus_config().
    disqus_config = function() {
      if (disqus_override_config.remote_auth_s3 || false) {
        this.page.remote_auth_s3 = disqus_override_config.remote_auth_s3;
      }
      if (disqus_override_config.api_key || false) {
        this.page.api_key = disqus_override_config.api_key;
      }      
      //Configure le lien de deconnexion quand connecte janrain
      //Si connecte disqus, le lien de deconnexion est disqus
      this.sso = {
          name:   disqus_shortname,
          logout:  "javascript:CAPTURE.logout()"
      };
    };

    // Make the AJAX call to get the Disqus comments.
    jQuery.ajax({
      type: 'GET',
      url: 'http://' + disqus_shortname + '.disqus.com/embed.js',
      dataType: 'script',
      cache: false
    });
  };
});

})(jQuery);
