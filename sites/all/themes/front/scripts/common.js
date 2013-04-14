/**
 * Common js functional.
 */
(function ($) {
  Drupal.behaviors.prComments = {
    attach: function () {
      $('body').once('comment-links', function () {
        $('a.add-comment').click(function (e) {
          e.preventDefault()
          $('#comment-form').toggle();
        });
        $('div.comment-wrapper').hover(
          function () {
            $(this).find('a.comment-delete-link').show();
          },
          function () {
            $(this).find('a.comment-delete-link').hide();
          }
        );
        $('a.comment-delete-link').click(function (e) {
          var $this = $(this);
          e.preventDefault()

          $.ajax({
            type: 'POST',
            dataType: 'json',
            global: false,
            context: {
              element: this,
              event: e
            },
            url: $this.attr('href'),
            success: function ($response) {
              if ($response.status != undefined && $response.status == 'success') {
                $(this.element).closest('div.comment-wrapper').remove();
              }
            }
          });
        });

        var $desc = $('form div.description');
        $desc.hide();
        $desc.each(function () {
          var $this = $(this);
          $this.siblings('input, textarea, select').hover(
            function () {
              $this.show();
            },
            function () {
              setTimeout(function () {
                $this.hide();
              }, 2000);
            }
          )
        })
        $('a.tea-mug').click(function (e) {
          e.preventDefault();
          $("html, body").animate({"scrollTop":0},"slow");
        })
      });
    }
  }
})(jQuery);
