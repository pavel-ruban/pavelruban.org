<?php
/**
 * @file
 * le_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function le_user_user_default_roles() {
  $roles = array();

  // Exported role: Administrateur.
  $roles['Administrateur'] = array(
    'name' => 'Administrateur',
    'weight' => '2',
  );

  // Exported role: Blogueur.
  $roles['Blogueur'] = array(
    'name' => 'Blogueur',
    'weight' => '5',
  );

  // Exported role: Journaliste.
  $roles['Journaliste'] = array(
    'name' => 'Journaliste',
    'weight' => '3',
  );

  // Exported role: Superviseur.
  $roles['Superviseur'] = array(
    'name' => 'Superviseur',
    'weight' => '4',
  );

  return $roles;
}
