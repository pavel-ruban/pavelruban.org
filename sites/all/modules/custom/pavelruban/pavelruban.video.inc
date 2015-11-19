<?php

/**
 * Provides video rendering workflow for embedded_video formatter. Added support for vk.com player.
 */

function pavelruban_emvideo_parse($url) {
  if (!empty($url)) {
    switch (TRUE) {
      case preg_match('/vk\.com\/video_ext.php/', $url):
        return array('source' => trim($url), 'provider' => 'vk.com');;
    }
  }
}

function pavelruban_emvideo_emcode($data) {
  if (!empty($data['source']) && !empty($data['provider'])) {
    switch ($data['provider']) {
      case 'vk.com':
        $output = <<<EOL
<iframe src="{$data['source']}" frameborder="0" height="{$data['height']}" width="{$data['width']}" />
EOL;
        return trim($output);
    }
  }

  return FALSE;
}