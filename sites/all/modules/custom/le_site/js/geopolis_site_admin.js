/**
 * @file
 * Culturebox site admin tricks.
 */

(function ($){

  /* Behavior for set preview of Illustration field. */
  Drupal.behaviors.showIllustrationPreview = {
    attach: function() {
      var ids = ['diaporama', 'edit-field-article-media-und-0-target-id', 'edit-field-article-main-media-und-0-target-id'];
      for (key in ids) {
        geopolis_site.showPreview(ids[key]);
      }
    }
  }

  Drupal.behaviors.geopolisExposedFormSubmit = {
    attach: function (context, settings) {
      $('.views-exposed-form').find(':text, :password, :radio, :checkbox', context).once('exposedFormSubmit', function() {
        $(this).keypress(function(event) {
          // Don't affect on autocomplete event.
          if ($(this).not('.throbbing') && !$('#autocomplete').size()) {
            if (event.which == 13) {
              this.form.submit();
            }
          }
        });
      });
    }
  };
})(jQuery);

geopolis_site = {

  needProcess : false,

  showPreview : function(id) {
    if (id == 'diaporama') {
      var count = 0;
      var divParent;
      var currents = [];
      while (jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").html() != null) {
        if (jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']")
          .parents('td:first').find("div[id^='div-edit-field-asset-diaporama-und-" + count + "-target-id']")
          .html() == null) {

          divParent = jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']")
            .parents('td:first').find('.form-item-field-asset-diaporama-und-' + count + '-target-id');

          jQuery(divParent).after('<div id="div-edit-field-asset-diaporama-und-' + count + '-target-id"></div>');

          if (jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").val() != currents[count]
            && jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").val() != '') {

            currents[count] = jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").val();
            jQuery.ajax({
              type: 'POST',
              dataType: 'json',
              url: Drupal.settings.basePath + 'culturebox/ajax/media-preview/' + currents[count] + '/' + count,
              success: function(response) {
                if (response[1] != -1 && typeof(response[1]) != 'undefined') {
                  jQuery("div[id^='div-edit-field-asset-diaporama-und-" + response[1] + "-target-id']")
                    .html(response[0]);
                }
              }
            });
          }
        }
        if (!(jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").hasClass('processed'))) {
          jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").bind('change', function() {
            var parent = jQuery(this).parents('tr:first');
            var index = $("table[id^='field-asset-diaporama-values'] > tbody > tr").index(parent);
            var current;

            if (index != -1 && typeof(index) == 'number') {
              if (jQuery("input[id^='edit-field-asset-diaporama-und-" + index + "-target-id']").val() != current
                && jQuery("input[id^='edit-field-asset-diaporama-und-" + index + "-target-id']").val() != '') {

                current = jQuery("input[id^='edit-field-asset-diaporama-und-" + index + "-target-id']").val();
                jQuery.ajax({
                  type: 'POST',
                  dataType: 'json',
                  url: Drupal.settings.basePath + 'culturebox/ajax/media-preview/' + current + '/' + index,
                  success: function(response) {
                    if (response[1] != -1 && typeof(response[1]) != 'undefined') {
                      jQuery("div[id^='div-edit-field-asset-diaporama-und-" + response[1] + "-target-id']")
                        .html(response[0]);
                    }
                  }
                });
              }
            }
          });
          jQuery("input[id^='edit-field-asset-diaporama-und-" + count + "-target-id']").addClass('processed');
        }
        count++;
      }
    }
    else if (jQuery('#div-' + id).html() != null) {
      var current;
      if (!(jQuery('#div-' + id).hasClass('processed'))) {
        jQuery('#' + id).change(function() {
          geopolis_site.needProcess = true;
        });
        setInterval(function() {
          if ((jQuery('#' + id).val() != current && jQuery('#' + id).val() != '') || geopolis_site.needProcess) {
            current = jQuery('#' + id).val();
            var $field = jQuery('#' + id);
            // Show 'modify' link and set proper href for modify dialog.
            var matches = current.match(/.*\((\d+)\).*/);
            if (matches) {
              var $modifyLink = $field.parents('div.field-type-entityreference').find('a.edit-dialog.references-dialog-activate');
              if ($modifyLink) {
                $modifyLink.show().attr('href', Drupal.settings.basePath + 'admin/content/assets/manage/' + matches[1]);
              }
            }

            jQuery.ajax({
              type: 'POST',
              url: Drupal.settings.basePath + 'geopolis/ajax/illustration-preview/' + current,
              success: function(msg) {
                jQuery('#div-' + id).html(msg);
                geopolis_site.needProcess = false;
              }
            });
          }
          else if (jQuery('#' + id).val() == '') {
            jQuery('#div-' + id).html('');
          }
        }, 1000);
        jQuery('#div-' + id).addClass('processed');
      }
    }
  }
};
