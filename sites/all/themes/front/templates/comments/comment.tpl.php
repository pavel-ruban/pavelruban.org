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
<div class="<?php echo $id == 1 ? 'first ' : ''; ?>reply reply_dived clear reply_replieable comment-wrapper">
  <div class="reply_table">
    <?php if (!empty($picture)): ?>
      <?php print $picture; ?>
    <?php else: ?>
      <?php echo $anonym_picture; ?>
    <?php endif; ?>
    <div class="reply_info">
      <div class="fl_r reply_actions_wrap">
        <div class="reply_actions">
          <div class="reply_delete_button fl_r" style="opacity: 0;"></div>
        </div>
      </div>
      <div class="reply_text">
        <?php if (!empty($comment->recent_list)): ?>
          <?php $n = node_load($comment->nid); ?>
          <?php print l(check_plain($n->title), "node/$comment->nid",
            array('fragment' => "comment-$comment->cid", 'attributes' => array('class' => array('comments-node')))); ?>
        <?php endif; ?>
        <?php if (!empty($author)): ?>
          <?php print $author ?>
        <?php endif; ?>
        <div>
          <div class="wall_reply_text comment-body">
            <?php if (!empty($comment->recent_list)): ?>
              <?php print l(render($content['comment_body']), "node/$comment->nid", array('html' => TRUE, 'fragment' => "comment-$comment->cid")); ?>
              <?php unset($comment->recent_list); ?>
            <?php else: ?>
              <?php print render($content['comment_body']); ?>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <a class="wd_lnk"><span class="rel_date"><?php echo $date; ?></span></a>
    </div>
    <?php if (!empty($delete)): ?>
      <?php echo $delete_link; ?>
    <?php endif; ?>
  </div>
</div>
