<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile"<?php print $attributes; ?>>
  <h3>
    <?php echo drupal_ucfirst($target_user->name); ?>
    <?php if (!empty($access)): ?>
      <span class="access">последнее посещение: <?php echo $access; ?></span>
    <?php endif; ?>
  </h3>
  <?php if (!empty($edit_link)): ?>
    <?php echo $edit_link; ?>
  <?php endif; ?>
  <div class="image">
    <?php echo render($user_profile['field_asset_image']); ?>
  </div>
  <h4>Конакты:</h4>
  <div class="contacts">
    <?php echo render($user_profile['field_user_contacts']); ?>
  </div>
  <h4>Участник в течении:</h4>
  <div class="contacts">
    <?php echo $user_profile['summary']['member_for']['#markup']; ?>
  </div>
  <h4>Обо мне:</h4>
  <div class="about-me">
    <?php echo render($user_profile['field_about_me']); ?>
  </div></div>
