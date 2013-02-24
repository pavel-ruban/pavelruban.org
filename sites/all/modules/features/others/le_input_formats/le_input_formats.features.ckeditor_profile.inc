<?php
/**
 * @file
 * le_input_formats.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function le_input_formats_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '%l/ckeditor',
        'ckeditor_local_path' => '',
        'ckeditor_plugins_path' => '%l/ckeditor_plugins',
        'ckeditor_plugins_local_path' => '',
        'ckfinder_path' => '%m/ckfinder',
        'toolbar_wizard' => 't',
        'loadPlugins' => array(),
      ),
      'input_formats' => array(),
    ),
    'Full' => array(
      'name' => 'Full',
      'settings' => array(
        'ss' => '2',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'toolbar' => '[
    [\'Maximize\'],
    [\'Undo\',\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\',\'SpecialChar\'],
    [\'Bold\',\'Italic\',\'Underline\'],
    [\'Subscript\',\'Superscript\',\'NumberedList\',\'BulletedList\'],
    [\'JustifyLeft\',\'JustifyRight\',\'Blockquote\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'assetSearch\'],
    \'/\',
    [\'Format\',\'Styles\',\'Font\',\'FontSize\']
]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'fr',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'br',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 't',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 0,
            'breakBeforeOpen' => 0,
            'breakAfterOpen' => 0,
            'breakBeforeClose' => 0,
            'breakAfterClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%hsites/all/themes/geopolis/css/geopolis-asset-tooltip-theme.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => '0',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 't',
        'js_conf' => '',
        'loadPlugins' => array(
          'asset' => array(
            'name' => 'asset',
            'desc' => 'Media assets',
            'path' => '%base_path%sites/all/modules/contrib/asset/ckeditor/',
            'buttons' => array(
              'asset_image' => array(
                'label' => 'Asset: Image',
                'icon' => 'buttons/AddImage.png',
              ),
              'asset_video' => array(
                'label' => 'Asset: Video',
                'icon' => 'buttons/AddVideo.png',
              ),
              'asset_poll' => array(
                'label' => 'Asset: Sondage',
                'icon' => 'buttons/AddEncadre.png',
              ),
              'asset_free_html' => array(
                'label' => 'Asset: Free HTML',
                'icon' => 'buttons/AddFreeHTML.png',
              ),
              'asset_gallery' => array(
                'label' => 'Asset: Diaporama',
                'icon' => 'buttons/AddSlideshow.png',
              ),
              'assetSearch' => array(
                'label' => 'Assets library',
                'icon' => 'search.png',
              ),
            ),
          ),
          'counter' => array(
            'name' => 'counter',
            'desc' => 'Plugin to count symbols, symbols without blanks and words',
            'path' => '%plugin_dir_extra%counter/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir_extra%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(),
    ),
    'Full_with_pagebreaks' => array(
      'name' => 'Full_with_pagebreaks',
      'settings' => array(
        'ss' => '2',
        'default' => 't',
        'show_toggle' => 't',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'toolbar' => '[
    [\'Maximize\'],
    [\'Undo\',\'Cut\',\'Copy\',\'Paste\',\'PasteText\',\'PasteFromWord\',\'SpecialChar\'],
    [\'Bold\',\'Italic\',\'Underline\'],
    [\'Subscript\',\'Superscript\',\'NumberedList\',\'BulletedList\'],
    [\'JustifyLeft\',\'JustifyRight\',\'Blockquote\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'assetSearch\'],
    \'/\',
    [\'Format\',\'Styles\',\'Font\',\'FontSize\',\'PageBreak\']
]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => '0',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'asset' => array(
            'name' => 'asset',
            'desc' => 'Media assets',
            'path' => '%base_path%sites/all/modules/contrib/asset/ckeditor/',
            'buttons' => array(
              'asset_image' => array(
                'label' => 'Asset: Image',
                'icon' => 'buttons/AddImage.png',
              ),
              'asset_video' => array(
                'label' => 'Asset: Video',
                'icon' => 'buttons/AddVideo.png',
              ),
              'asset_poll' => array(
                'label' => 'Asset: Sondage',
                'icon' => 'buttons/AddEncadre.png',
              ),
              'asset_free_html' => array(
                'label' => 'Asset: Free HTML',
                'icon' => 'buttons/AddFreeHTML.png',
              ),
              'asset_gallery' => array(
                'label' => 'Asset: Diaporama',
                'icon' => 'buttons/AddSlideshow.png',
              ),
              'assetSearch' => array(
                'label' => 'Assets library',
                'icon' => 'search.png',
              ),
            ),
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir_extra%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'tableresize' => array(
            'name' => 'tableresize',
            'desc' => 'Table Resize plugin',
            'path' => '%editor_path%plugins/tableresize/',
            'buttons' => FALSE,
            'default' => 't',
          ),
        ),
      ),
      'input_formats' => array(),
    ),
    'Simple' => array(
      'name' => 'Simple',
      'settings' => array(
        'ss' => '2',
        'default' => 't',
        'show_toggle' => 'f',
        'skin' => 'kama',
        'uicolor' => 'default',
        'uicolor_textarea' => '<p>
	Click the <strong>UI Color Picker</strong> button to set your color preferences.</p>
',
        'uicolor_user' => 'default',
        'toolbar' => '[
    [\'Bold\',\'Italic\'],
    [\'NumberedList\',\'BulletedList\'],
    [\'Link\',\'Unlink\']
]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'fr',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'enter_mode' => 'br',
        'shift_enter_mode' => 'br',
        'font_format' => 'p',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%hsites/all/themes/geopolis/css/geopolis-asset-tooltip-theme.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'ckeditor_load_method' => 'ckeditor.js',
        'ckeditor_load_time_out' => '0',
        'forcePasteAsPlainText' => 't',
        'html_entities' => 't',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 't',
        'js_conf' => '',
        'title' => '',
        'loadPlugins' => array(),
      ),
      'input_formats' => array(
        'filtered_html' => 'Simple HTML',
      ),
    ),
  );
  return $data;
}
