<div <?php print preg_replace('/(class=".*?)"/', "$1 " . str_replace('_', '-', $view_mode) . "\"", $attributes); ?>><?php print $content; ?></div>
