<?php
/**
 * @file
 * Provides text process logic like text filters & regExpr.
 */

/**
 * Wrapp text nodes following last asset.
 */
function pavelruban_text_following_last_asset_wrapper($text) {
  $text = preg_replace('/(\\[\\[asset:image:[0-9]+\\s\\{"mode":"small"(?:\\n|(?(?=(?!\\[\\[asset)).))*?\\}\\]\\])(?!(?=\\[\\[asset))(?(?=(?:\\s*?<br \\/>|\\n+\\s*?<br \\/>))(?:((?:\\s*?<\\s*?br\\s*?\\/\\s*?>\\s*?)+)|\\n)+)((?:[^<]|\\n)+?)</mu',
    '${1}${2}<span class="text-node-wrapper">${3}</span><',
    $text
  );
  return $text;
}

