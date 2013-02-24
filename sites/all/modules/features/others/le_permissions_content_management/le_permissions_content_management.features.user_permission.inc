<?php
/**
 * @file
 * le_permissions_content_management.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function le_permissions_content_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: access additional node settings.
  $permissions['access additional node settings'] = array(
    'name' => 'access additional node settings',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'le_form_layouts',
  );

  // Exported permission: access additional term settings.
  $permissions['access additional term settings'] = array(
    'name' => 'access additional term settings',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'le_form_layouts',
  );

  // Exported permission: access assets overview.
  $permissions['access assets overview'] = array(
    'name' => 'access assets overview',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: administer assets.
  $permissions['administer assets'] = array(
    'name' => 'administer assets',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'asset',
  );

  // Exported permission: cancel own vote.
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'poll',
  );

  // Exported permission: create article content.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Blogueur',
      2 => 'Journaliste',
      3 => 'Superviseur',
    ),
    'module' => 'node',
  );

  // Exported permission: create asset with type free_html.
  $permissions['create asset with type free_html'] = array(
    'name' => 'create asset with type free_html',
    'roles' => array(),
    'module' => 'asset',
  );

  // Exported permission: create asset with type gallery.
  $permissions['create asset with type gallery'] = array(
    'name' => 'create asset with type gallery',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: create asset with type image.
  $permissions['create asset with type image'] = array(
    'name' => 'create asset with type image',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: create asset with type poll.
  $permissions['create asset with type poll'] = array(
    'name' => 'create asset with type poll',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: create asset with type video.
  $permissions['create asset with type video'] = array(
    'name' => 'create asset with type video',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: create author content.
  $permissions['create author content'] = array(
    'name' => 'create author content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create flash_news content.
  $permissions['create flash_news content'] = array(
    'name' => 'create flash_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create folder content.
  $permissions['create folder content'] = array(
    'name' => 'create folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: create poll content.
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any article content.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any author content.
  $permissions['delete any author content'] = array(
    'name' => 'delete any author content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any flash_news content.
  $permissions['delete any flash_news content'] = array(
    'name' => 'delete any flash_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any folder content.
  $permissions['delete any folder content'] = array(
    'name' => 'delete any folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any poll content.
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete asset with type free_html.
  $permissions['delete asset with type free_html'] = array(
    'name' => 'delete asset with type free_html',
    'roles' => array(),
    'module' => 'asset',
  );

  // Exported permission: delete asset with type gallery.
  $permissions['delete asset with type gallery'] = array(
    'name' => 'delete asset with type gallery',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: delete asset with type image.
  $permissions['delete asset with type image'] = array(
    'name' => 'delete asset with type image',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: delete asset with type poll.
  $permissions['delete asset with type poll'] = array(
    'name' => 'delete asset with type poll',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: delete asset with type video.
  $permissions['delete asset with type video'] = array(
    'name' => 'delete asset with type video',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: delete own article content.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own author content.
  $permissions['delete own author content'] = array(
    'name' => 'delete own author content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own flash_news content.
  $permissions['delete own flash_news content'] = array(
    'name' => 'delete own flash_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own folder content.
  $permissions['delete own folder content'] = array(
    'name' => 'delete own folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own poll content.
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any article content.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Superviseur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any author content.
  $permissions['edit any author content'] = array(
    'name' => 'edit any author content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any flash_news content.
  $permissions['edit any flash_news content'] = array(
    'name' => 'edit any flash_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any folder content.
  $permissions['edit any folder content'] = array(
    'name' => 'edit any folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any poll content.
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit asset with type free_html.
  $permissions['edit asset with type free_html'] = array(
    'name' => 'edit asset with type free_html',
    'roles' => array(),
    'module' => 'asset',
  );

  // Exported permission: edit asset with type gallery.
  $permissions['edit asset with type gallery'] = array(
    'name' => 'edit asset with type gallery',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: edit asset with type image.
  $permissions['edit asset with type image'] = array(
    'name' => 'edit asset with type image',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: edit asset with type poll.
  $permissions['edit asset with type poll'] = array(
    'name' => 'edit asset with type poll',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: edit asset with type video.
  $permissions['edit asset with type video'] = array(
    'name' => 'edit asset with type video',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'asset',
  );

  // Exported permission: edit own article content.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Blogueur',
      2 => 'Journaliste',
      3 => 'Superviseur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own author content.
  $permissions['edit own author content'] = array(
    'name' => 'edit own author content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own flash_news content.
  $permissions['edit own flash_news content'] = array(
    'name' => 'edit own flash_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own folder content.
  $permissions['edit own folder content'] = array(
    'name' => 'edit own folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own poll content.
  $permissions['edit own poll content'] = array(
    'name' => 'edit own poll content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: inspect all votes.
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'poll',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: schedule (un)publishing of nodes.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Blogueur',
      2 => 'Journaliste',
      3 => 'Superviseur',
      4 => 'anonymous user',
      5 => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'Administrateur',
      1 => 'Journaliste',
      2 => 'Superviseur',
    ),
    'module' => 'filter',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'node',
  );

  // Exported permission: vote on polls.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      0 => 'Administrateur',
    ),
    'module' => 'poll',
  );

  return $permissions;
}
