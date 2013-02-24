<?php
/**
 * @file
 * Functions for process video.
 */

/**
 * Implements hook_emvideo_video_alter().
 */
function le_site_emvideo_video_alter($item, &$element) {
  // If not in CKEditor now.
  if (!empty($item['entity']->in_editor) && $item['entity']->in_editor != TRUE) {
    $video_url = le_site_get_url_by_emcode($item['url']);
    $preview = le_site_emvideo_parse($item['url']);
    $description = field_get_items('asset', $item['entity'], 'field_asset_video');
    // If $preview is not empty.
    if (!empty($preview)) {
      $video = array(
        'url' => $video_url,
        'preview' => $preview,
        'title' => check_plain($item['entity']->title),
        'date' => format_date($item['entity']->created, 'custom', 'c'),
        'description' => (!empty($description[0]['safe_value'])) ? $description[0]['safe_value'] : check_plain($item['entity']->title),
      );
      $element['0']['#markup'] = theme('video_microformat', array('video' => $video, 'emcode' => $element['0']['#markup']));
    }
  }
}

/**
 * Implements hook_emvideo_emcode().
 */
function le_site_emvideo_emcode($params) {
  // Process urls.
  if (substr(trim($params['url']), 0, 1) != '<') {
    if (preg_match('/youtu.be/', $params['url']) || preg_match('/youtube.com/', $params['url'])) {
      return le_site_video_url_youtube($params);
    }
  }
  // Process embed code.
  if (substr(trim($params['url']), 0, 7) == '<iframe') {
    return le_site_video_embed_iframe($params);
  }
}

/**
 * Implements hook_emvideo_parse().
 */
function le_site_emvideo_parse($emcode) {
  if (preg_match('/youtube.com/', $emcode) || preg_match('/youtu.be/', $emcode)) {
    return le_site_get_snapshot_youtube($emcode);
  }
  else {
    return le_site_get_snapshot_default();
  }
}

/**
 * Process video with tag iframe.
 */
function le_site_video_embed_iframe($params) {
  $dom = new DomDocument();
  @$dom->loadHTML($params['url']);
  $xml = simplexml_import_dom($dom);
  $iframe = $xml->xpath("//iframe");
  $output = '';
  foreach ($iframe as $res) {
    $width = strval($res['width']);
    $height = strval($res['height']);
    $res['width'] = $params['width'];
    $res['height'] = $params['height'];
    $sub_output = '<iframe';
    $iframe = $dom->getElementsByTagName('iframe');
    if ($iframe->length) {
      for ($i = 0; $i < $iframe->item(0)->attributes->length; $i++) {
        $sub_output .= ' ' . $iframe->item(0)->attributes->item($i)->nodeName
          . '="' . $iframe->item(0)->attributes->item($i)->nodeValue . '"';
      }
      $sub_output .= '></iframe>';
      // Case for ina.fr
      if (preg_match('/ina.fr/', $sub_output)) {
        $width  = $params['width'];
        $height = $params['height'];
        $src = $iframe->item(0)->attributes->getNamedItem('src')->nodeValue;
        $embed = explode('/', $src);
        $id_notice = $embed[5];
        $id_user   = $embed[6];
        $hashcode  = $embed[7];

        $output = '<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"
          id="Visionneuse" width="' . $width . '" height="' . $height . '"
          codebase="http://fpdownload.macromedia.com/get/flashplayer/current/swflash.cab">
          <param name="movie" value="http://www.ina.fr/video/ticket/' . $id_notice . '/' . $id_user . '/' . $hashcode . '" />
          <param name="pluginspage" value="http://www.macromedia.com/go/getflashplayer">
          <param name="align" value="middle">
          <param name="quality" value="high" />
          <param name="scale" value="showall">
          <param name="wmode" value="transparent">
          <param name="menu" value="true">
          <param name="devicefont" value="false">
          <param name="bgcolor" value="#FFFFFF" />
          <param name="allowScriptAccess" value="always" />
          <param name="allowFullScreen" value="true" />
          <param name="flashvars" value="config=http://www.ina.fr/player/configurationEmbed&amp;type_media=video">
          <embed src="http://www.ina.fr/video/ticket/' . $id_notice . '/' . $id_user . '/' . $hashcode . '" quality="high" bgcolor="#FFFFFF"
              width="' . $width . '" height="' . $height . '" name="Viewer" align="middle"
              quality="high"
              wmode="transparent"
              allowScriptAccess="always"
              allowFullScreen="true"
              type="application/x-shockwave-flash"
              pluginspage="http://www.adobe.com/go/getflashplayer"
              flashvars="config=http://www.ina.fr/player/configurationEmbed&amp;type_media=video">
          </embed>
        </object>';
        return $output;
      }
      $output .= $sub_output;
    }
  }
  return ($output === '') ? FALSE : $output;
}

/**
 * Common process object video;
 */
function le_site_video_embed_object($params) {
  $dom = new DomDocument();
  @$dom->loadHTML($params['url']);

  $object = $dom->getElementsByTagName('object');
  if ($object->length) {
    $width = $object->item(0)->attributes->getNamedItem('width')->nodeValue;
    $height = $object->item(0)->attributes->getNamedItem('height')->nodeValue;
    if (!empty($width) && !empty($height)) {
      $output = preg_replace('/width="' . $width . '"/', 'width="' . $params['width'] . '"', $params['url']);
      $output = preg_replace('/height="' . $params['height'] . '"/', 'height="' . $params['height'] . '"', $output);
      return $output;
    }
  }
}

/**
 * Process video from youtube for get snapshot.
 */
function le_site_get_snapshot_youtube($emcode) {

  if (substr($emcode, 0, 4) == 'http') {
    $url = preg_replace('/^([^?]+)(\?.*?)?(#.*)?$/', '$1$3', $emcode);
    $url = explode('v/', $url);
    $url = explode('&', $url[count($url) - 1]);
    return array(
      'source' => 'http://www.youtube.com/v/' . $url[0],
      'provider' => 'youtube',
      'snapshot' => 'http://img.youtube.com/vi/' . $url[0] . '/0.jpg',
    );
  }

  $dom = new DomDocument();
  @$dom->loadHTML($emcode);

  $iframe = $dom->getElementsByTagName('iframe');
  // New format of video.
  if ($iframe->length) {
    $src = $iframe->item(0)->attributes->getNamedItem('src')->nodeValue;
    $url = parse_url($src);
    $url = explode('/', $url['path']);
    $id = (!empty($url[count($url) - 1])) ? $url[count($url) - 1] : $url[count($url) - 2];
    return array(
      'source' => 'http://www.youtube.com/v/' . $id,
      'provider' => 'youtube',
      'snapshot' => 'http://img.youtube.com/vi/' . $id . '/0.jpg',
    );
  }
  // Old format of video.
  else {
    $param = $dom->getElementsByTagName('param');
    if ($param->length) {
      $src = $param->item(0)->attributes->getNamedItem('value')->nodeValue;
      // Remove GET params from url.
      $url = preg_replace('/^([^?]+)(\?.*?)?(#.*)?$/', '$1$3', $src);
      $url = explode('v/', $url);
      $url = explode('&', $url[count($url) - 1]);
      return array(
        'source' => 'http://www.youtube.com/v/' . $url[0],
        'provider' => 'youtube',
        'snapshot' => 'http://img.youtube.com/vi/' . $url[0] . '/0.jpg',
      );
    }
  }

  return FALSE;
}

/**
 * Get default snapshot.
 */
function le_site_get_snapshot_default() {
  global $base_url;
  return array(
    'snapshot' => $base_url . '/' . LE_SITE_ADMIN_THEME_PATH . '/images/media_gallery/video-thumbnail.jpg',
  );
}

/**
 * Process video by url from youtube.
 */
function le_site_video_url_youtube($params) {
  $path = parse_url($params['url']);
  $args = array();
  if (isset($path['query'])) {
    parse_str($path['query'], $args);
  }
  $id = (!empty($args['v'])) ? '/' . $args['v'] : $path['path'];
  return '<iframe width="' . $params['width'] . '" height="' . $params['height'] . '" src="http://www.youtube.com/embed' . $id . '" frameborder="0" allowfullscreen></iframe>';
}

/**
 * Get url of video by emcode.
 */
function le_site_get_url_by_emcode($emcode) {

  if (substr(trim($emcode), 0, 1) != '<') {
    return $emcode;
  }
  // Process iframe.
  elseif (substr(trim($emcode), 0, 7) == '<iframe') {
    return le_site_get_url_from_iframe($emcode);
  }
  elseif (preg_match('/youtube.com/', $emcode)) {
    return le_site_get_url_from_youtube($emcode);
  }
  return FALSE;
}

/**
 * Get url of video from iframe.
 */
function le_site_get_url_from_iframe($emcode) {
  $dom = new DomDocument();
  @$dom->loadHTML($emcode);
  $iframe = $dom->getElementsByTagName('iframe');
  if ($iframe->length) {
    $link = $iframe->item(0)->attributes->getNamedItem('src')->nodeValue;
    if ($link) {
      return $link;
    }
  }
  return FALSE;
}

/**
 * Get url of video from youtube.
 */
function le_site_get_url_from_youtube($emcode) {
  $dom = new DomDocument();
  @$dom->loadHTML($emcode);
  $object = $dom->getElementsByTagName('object');

  if ($object->length) {
    $link = $object->item(0)->attributes->getNamedItem('data')->nodeValue;
    if ($link) {
      return $link;
    }
    // Get src from tag embed.
    else {
      $embed = $dom->getElementsByTagName('embed');
      $link = $embed->item(0)->attributes->getNamedItem('src')->nodeValue;
      $url = parse_url($link);
      if ($url) {
        return $url['scheme'] . '://' . $url['host'] . $url['path'];
      }
    }
  }
  return FALSE;
}
