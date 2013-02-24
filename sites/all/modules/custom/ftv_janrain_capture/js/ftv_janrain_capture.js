(function ($) {


Drupal.behaviors.ftv_janrain_capture = {
  attach: function (context, settings) {
    if (Drupal.ajax) {
      // Call /janrain_capture/user ajax callback
      $('#ftv-janrain-catpure-user-ajax').get(0).click();
    }
  }
};


$(function() {

  Drupal.ajax.prototype.commands.ftv_janrain_capture_check_missing_data = function (ajax, response, status) {
    // Check if all fields required on the site are filled
    // if (response.data.user_missing_data != null) {
    //   text = '<p>Pour continuer de rester connecter sur ce site, vous devez renseigner les données suivantes :</p>';
    //   text += '<ul>';
    //   for (missing_field in response.data.user_missing_data) {
    //     text += '<li>' + response.data.user_missing_data[missing_field] + '</li>';
    //   };
    //   text += '</ul>';
    //   text += '<p>Cliquez sur continuer pour éditer ces données.</p>';
    //   text += '<a class="mising_data_continue_button" href="#">Continuer</a>';

    //   $.fancybox(
    //     text,
    //     {
    //     padding: 0,
    //     scrolling: "no",
    //     autoScale: true,
    //     width: 666,
    //     autoDimensions: false
    //   });
    // }
  };
});

})(jQuery);
