<?php
/**
 * @file
 * common_input_formats.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function common_input_formats_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'skin' => 'kama',
        'ckeditor_path' => '%l/ckeditor',
        'ckeditor_local_path' => '',
        'ckeditor_plugins_path' => '%m/plugins',
        'ckeditor_plugins_local_path' => '',
        'ckfinder_path' => '%m/ckfinder',
        'ckfinder_local_path' => '',
        'ckeditor_aggregate' => 'f',
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
        'show_toggle' => 'f',
        'uicolor' => 'custom',
        'uicolor_user' => '#D3D3D3',
        'toolbar' => '[
    [\'Source\'],
    [\'SpellChecker\'],
    [\'Undo\',\'Redo\',\'Find\',\'Replace\',\'-\',\'SelectAll\',\'RemoveFormat\'],
    [\'SpecialChar\',\'Format\',\'Font\',\'FontSize\'],
    [\'TextColor\',\'BGColor\'],
    [\'Maximize\'],
    \'/\',
    [\'Bold\',\'Italic\',\'Underline\',\'Strike\',\'-\',\'Subscript\',\'Superscript\'],
    [\'NumberedList\',\'BulletedList\',\'-\',\'Outdent\',\'Indent\',\'Blockquote\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\',\'-\',\'BidiLtr\',\'BidiRtl\'],
    [\'Link\',\'Unlink\',\'Anchor\',\'Code\',\'asset_image\',\'asset_video\',\'asset_gallery\',\'assetSearch\']
]',
        'expand' => 't',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 'f',
        'extraAllowedContent' => 'config.allowedContent = true;',
        'enter_mode' => 'br',
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
        'css_mode' => 'self',
        'css_path' => '/sites/all/themes/common_admin/css/ckeditor_custom.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'asset' => array(
            'name' => 'asset',
            'desc' => 'Media assets',
            'path' => '%base_path%sites/all/modules/contrib/asset/ckeditor/',
            'buttons' => array(
              'asset_video' => array(
                'label' => 'Asset: Video',
                'icon' => 'buttons/AddVideo.png',
              ),
              'asset_image' => array(
                'label' => 'Asset: Image',
                'icon' => 'buttons/AddImage.png',
              ),
              'asset_gallery' => array(
                'label' => 'Asset: Gallery',
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
            'path' => '%plugin_dir%counter/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'iframedialog' => array(
            'name' => 'iframedialog',
            'desc' => 'Plugin file: iframedialog',
            'path' => '%plugin_dir%iframedialog/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'syntaxhighlight' => array(
            'name' => 'syntaxhighlight',
            'desc' => 'Plugin file: syntaxhighlight',
            'path' => '%plugin_dir%syntaxhighlight/',
            'buttons' => array(
              'Code' => array(
                'label' => 'Code',
                'icon' => 'images/syntaxhighlight.gif',
              ),
            ),
            'default' => 'f',
          ),
        ),
      ),
      'input_formats' => array(
        'full_html' => 'Full HTML',
      ),
    ),
  );
  return $data;
}
