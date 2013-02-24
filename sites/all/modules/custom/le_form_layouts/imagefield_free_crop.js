(function ($) {
  Drupal.behaviors.imagefield_free_crop = {
    attach: function (context, settings) {
      setTimeout(function () {
        if (typeof(settings.imagefield_crop) !== 'undefined') {
          $('#edit-field-asset-free-crop .form-radio', 'form').once(function () {
            var $this = $(this);
            if ($this.attr('checked')) {
              if (!parseInt($this.val(), 10)) {
                Drupal.settings.imagefield_crop[id].box = {
                  ratio : 0,
                  box_width : box.box_width,
                  box_height : box.box_height
                };
                $('.form-item-field-asset-image-und-0 .imagefield-crop-preview').css({display: 'none'});
              } else if (parseInt($this.val(), 10)) {
                Drupal.settings.imagefield_crop[id].box = box;
                $('.form-item-field-asset-image-und-0 .imagefield-crop-preview').css({display: 'block'});
              }
            }
            $this.change(function() {leCropProcess($this, id, box, settings);})});
        }
      }, 10, context);

      var id = 'edit-field-asset-image-und-0';
      if (typeof(settings.imagefield_crop) != 'undefined') {
        var box = settings.imagefield_crop[id].box;
        /* Set crop area when image has been reuploaded. */
        $('#edit-field-asset-free-crop .form-radio', 'form').each(function() {
          var elem = $(this);
          if (elem.attr('checked')) {
            var date1 = new Date();
            setTimeout(
              function() {
                leCropProcess(elem, id, date1, settings)
              },
              1200
            );
          }
        })
      }

      if ($('span.file').html() == null) {
        $('span.cropbox-description').hide();
      }
      else {
        $('div.cropbox-description').show();
      }
    },
    weight : 10
  };
})(jQuery);

function leCropProcess(elem, id, box, settings) {
  var cropTimer = setInterval(
    function() {
      if (typeof(Jcrop_api[id]) !== 'undefined') {
        clearInterval(cropTimer);
        if (jQuery(elem).attr('checked')) {
          if (parseInt(jQuery(elem).val(), 10)) {
            var size = jQuery(elem).val().split('x');
            var rate = size[1] / size[0];
            Jcrop_api[id].destroy();
            jQuery('img.cropbox').removeClass('jquery-once-2-processed');
            jQuery('img.cropbox').attr('id', 'edit-field-asset-image-und-0-cropbox');
            if (Drupal.settings.imagefield_crop['edit-field-asset-image-und-0'].preview != undefined) {
              Drupal.settings.imagefield_crop['edit-field-asset-image-und-0'].preview.height = Drupal.settings.imagefield_crop['edit-field-asset-image-und-0'].preview.width * rate;
            }

            if (jQuery('#asset-edit-image-form').html() != null) {
              Drupal.behaviors.imagefield_crop.attach(jQuery('#asset-edit-image-form'), Drupal.settings);
            }
            else if (jQuery('#assets-wysiwyg-form').html() != null) {
              Drupal.behaviors.imagefield_crop.attach(jQuery('#assets-wysiwyg-form'), Drupal.settings);
            }
            leLoadDefaultPreviewState(elem, id, box, settings);

            setTimeout(
              function() {
                var widget = jQuery('.cropbox').parent().parent().parent('.form-item');
                jQuery('.preview-existing', widget).css({display: 'none'});
                var cropBox = Jcrop_api[id].tellSelect();
                jQuery(".edit-image-crop-x", widget).val(cropBox.x);
                jQuery(".edit-image-crop-y", widget).val(cropBox.y);
                jQuery(".edit-image-crop-width", widget).val(cropBox.w);
                jQuery(".edit-image-crop-height", widget).val(cropBox.h);
                jQuery(".edit-image-crop-changed", widget).val(1);
              },
              1500
            );
          }
        }
      }
    },
    1000
  );
}

function leLoadDefaultPreviewState(elem, id, box, settings) {
  var options = {};
  if (jQuery(elem).attr('checked')) {
    setTimeout(function() {
      var size = jQuery(elem).val().split('x');
      options = {
        aspectRatio : parseFloat(size[0]/size[1]),
        boxWidth : box.box_width,
        boxHeight : parseInt(box.box_width/parseFloat(size[0]/size[1]))
      };
      Jcrop_api[id].setOptions(options);
      jQuery('.jcrop-preview-wrapper').height(Drupal.settings.imagefield_crop[id].preview.height);
      jQuery('.form-item-field-asset-image-und-0 .imagefield-crop-preview').css({display: 'block'});
    }, 1200);
  }
}
