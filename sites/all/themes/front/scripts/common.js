/**
 * Common js functional.
 */

counter = 0;

(function ($) {
  Drupal.behaviors.prSidebar = {
    attach: function () {
      $('h3.recent-posts').click(function(){
        var $this = $(this), $ul = $this.parent().find('ul.recent-posts');
        if ($ul.hasClass('expanded')) {
          $ul.removeClass('expanded').addClass('minimized').animate(
            {height: '0px'},
            {
              duration: 1000,
              complete: function() {
                $ul.siblings('h3.recent-posts').find('span.prefix').html('+');
              }
            }
          );
        }
        else {
          var height = 0;
          $('ul.recent-posts > *').each(function(a, b) {
            height += jQuery(b).outerHeight(true);
          });

          $ul.removeClass('minimized').addClass('expanded')
            .animate(
              {height: height + 'px'},
              {
                duration: 1000,
                complete: function() {
                  $ul.siblings('h3.recent-posts').find('span.prefix').html('-');
                }
              }
          );
        }
      });
    }
  }

  Drupal.behaviors.assetFrontWrappers = {
    attach: function () {
      $('.content-small + .content-small').once(function () {
        $(this).each(function () {
          var $this = $(this);
          if (counter == 0) {
            counter++;
            $this.addClass('right');
            if (!$this.find('+ .content-small').size()) {
              counter = 0;
            }
          }
          else {
            counter = 0;
          }
        });
      });
    }
  }

  Drupal.behaviors.galleryInit = {
    attach: function () {
      $("#wowslider-container1").once(function () {
        $(this).wowSlider({
          effect: "kenburns", prev: "", next: "",
          duration: 12 * 100, delay: 52 * 100,
          width: 450, height: 405, autoPlay: true,
          stopOnHover: true, loop: true, bullets: 0,
          caption: true, captionEffect: "fade", controls: true,
          onBeforeStep: function (i, c) {
            return (i + 1 + Math.floor((c - 1) * Math.random()))
          }
        });
      });
    }
  }

  Drupal.behaviors.shadowbox = {
    attach: function () {
      if (typeof(Shadowbox) != 'undefined') {
        Shadowbox.init({
          handleOversize: "resize",
          modal: false,
          continuous: true,
          displayNav: true,
          resizeDuration: 0,
          overlayOpacity: 0.9,
          viewportPadding: 5,
          counterType: "skip"
        });
      }
    }
  }

  Drupal.behaviors.magicMag = {
    attach: function () {
      $('body').once('magic-mug', function() {
        var $doc = $(document), $win = $(window), $mug = $('.tea-mug-cloud'),
          viewportHeight = $doc.height() - $win.height(),
          unit = viewportHeight / 100;

        setInterval(function() {
          var location = $doc.scrollTop();
          var opacityLevel = location / unit / 100;
          if (opacityLevel < 1) {
            opacityLevel = opacityLevel.toPrecision(2);
          } else opacityLevel = 1;
          $mug.animate({opacity: opacityLevel}, 6000, function() {
            $(this).css('filter', 'none');
          });
        }, 8500);
      });
    }
  }

  Drupal.behaviors.peoplePopup = {
    attach: function () {
      $('a.like-quantity').click(function(e){
        var $this = $(this);
        e.preventDefault();
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
            if ($response.peoplePopup != undefined) {
              $.fancybox({content: $response.peoplePopup, closeBtn: false, helpers: {
                  overlay: {
                    css: {
                      'background': 'rgba(1, 1, 1, 0.1)'
                    }
                  }
                }
              });

              $('a.fancybox-close-link').once(function(){
                $(this).click(function(e){
                  e.preventDefault();
                  $.fancybox.close();
                });
              });
            }
          }
        });
      });
    }
  }

  Drupal.behaviors.likes = {
    attach: function () {
      $('div.like-info').once(function(){
        var $this = $(this);
        $this.bind({
          mouseenter: function(e) {
            $this.find('.like-popup-angle').show();
          },
          mouseleave: function(e) {
            $this.find('.like-popup-angle').hide();
          },
        });
      });

      $('div.like-popup').once(function(){
        var $this = $(this);
        $this.bind({
          mouseenter: function(e) {
            $this.siblings('.like-popup-angle').show();
          },
          mouseleave: function(e) {
            $this.siblings('.like-popup-angle').hide();
          },
        });
      });
      $('div.social').once(function(){
        var $this = $(this);
        $this.bind({
          mouseenter: function(e) {
            $this.find('.social-popup-angle').show();
          },
          mouseleave: function(e) {
            $this.find('.social-popup-angle').hide();
          },
        });
      });

      $('div.social-popup').once(function(){
        var $this = $(this);
        $this.bind({
          mouseenter: function(e) {
            $this.siblings('.social-popup-angle').show();
          },
          mouseleave: function(e) {
            $this.siblings('.social-popup-angle').hide();
          },
        });
      });
      $('a.like-ajax-img').click(function(e){
        var $this = $(this);
        e.preventDefault();
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
            if ($response.vote != undefined && $response.vote == 0) {
              $(this.element).removeClass('voted').attr('title', 'мне нравится');
            }
            else if ($response.vote != undefined && $response.vote == 1) {
              $(this.element).addClass('voted').attr('title', 'оценено');
            }

            if ($response.userLikesCount != undefined && $response.userLikesCount == 0) {
              $(this.element).find('~ div.like-popup').addClass('empty');
            }
            else if ($response.userLikesCount != undefined) {
              $(this.element).find('~ div.like-popup').removeClass('empty');
            }
            $(this.element).find('~ span').html($response.likesCount);
            $(this.element).find('~ div.like-popup').html($response.likedUsers);
            Drupal.behaviors.peoplePopup.attach();
          }
        });
      });
    }
  }

  Drupal.behaviors.prComments = {
    attach: function () {
      $('div.comment-wrapper:not(:first)').removeClass('first');
      var $firtWrapper = $('div.comment-wrapper:first');
      if (!$firtWrapper.addClass('first').size()) {
        $('.comment-bottom-line').addClass('hide');
      }
      else {
        $('.comment-bottom-line').removeClass('hide');
      }
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
                Drupal.behaviors.prComments.attach();
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
          $("html, body").animate({"scrollTop": 0}, "slow");
        })
      });
    }
  }
})(jQuery);
