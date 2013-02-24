<?php
/**
 * @file
 * pruban_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function pruban_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: teaser.
  $styles['teaser'] = array(
    'name' => 'teaser',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '200',
          'height' => '159',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
