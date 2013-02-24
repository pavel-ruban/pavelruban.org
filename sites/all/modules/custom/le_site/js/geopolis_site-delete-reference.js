(function ($) {
  Drupal.behaviors.referencesDelete = {
    attach: function (context, settings) {
      $('a.delete-dialog').unbind('click');
      $('a.delete-dialog').click(function() {
        var $input = $(this).parents('div.field-type-entityreference').find('input.form-autocomplete');
        $input.val('');
        return false;
      });
    }
  }
})(jQuery);