<?php

/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */
?>
<div class="<?php echo $id == 1 ? 'first ' : ''; ?>reply reply_dived clear reply_replieable">
  <div class="reply_table">
    <?php if (!empty($picture)): ?>
      <?php print $picture ?>
    <?php endif; ?>
    <div class="reply_info">
      <div class="fl_r reply_actions_wrap">
        <div class="reply_actions"><div onmouseout="wall.deactiveDeletePost('25864363_6060', 'reply_delete')" onmouseover="wall.activeDeletePost('25864363_6060', 'Удалить', 'reply_delete')" onclick="wall.deletePost('25864363_6060', 'dfafbc92e6dafa53c2');" class="reply_delete_button fl_r" id="reply_delete25864363_6060" style="opacity: 0;"></div></div>
      </div>
      <div class="reply_text">
        <?php print $author ?> <div id="wpt25864363_6060"><div class="wall_reply_text"><?php print render($content['comment_body']); ?></div></div>
      </div>
      <div id="wpe_bottom25864363_6060" class="info_footer">
        <div onmouseout="wall.likeOut('25864363_wall_reply6060')" onmouseover="wall.likeOver('25864363_wall_reply6060')" onclick="wall.like('25864363_wall_reply6060', 'f00710da61bf60aca1'); event.cancelBubble = true;" class="like_wrap fl_r">
          <span id="like_link25864363_wall_reply6060" class="like_link fl_l" style="opacity: 0;">Мне нравится</span>
          <i id="like_icon25864363_wall_reply6060" class="no_likes fl_l" style="visibility: hidden; opacity: 0;"></i>
          <span id="like_count25864363_wall_reply6060" class="like_count fl_l"></span>
        </div>
        <a onclick="return showWiki({w: 'wall25864363_4851', reply: '6060'}, false, event);" href="/wall25864363_4851?reply=6060" class="wd_lnk"><span class="rel_date">13 янв в 23:26</span></a>
      </div>
    </div>
  </div>
</div>