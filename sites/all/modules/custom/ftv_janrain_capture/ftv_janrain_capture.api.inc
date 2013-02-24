<?php

/**
 * @file
 * An API Client for making calls to the Janrain Capture web service.
 */


class FtvJanrainCaptureApi extends JanrainCaptureApi {

 /**
  * Retrieve origin_id value or client_id if empty
  *
  * @return string $response
  *
  */
  public function getOriginId() {
    $command = "settings/get";
    $arg_array = array(
      'key' => 'origin_id',
    );

    $response = $this->call($command, $arg_array);
    $response = !empty($response['result']) ? $response['result'] : $this->args['client_id'];
    return $response;
  }

 /**
  * Retrives the user entity from Capture
  *
  * @param array $capture_profile
  *   The capture profile of the user
  * @param string $origin_id
  *   The value of origin_id
  *
  * @return mixed
  *   The entity retrieved or null
  */
  public function setOriginId($capture_profile = NULL, $origin_id = NULL) {
    $command = "entity.update";
    $arg_array = array(
      'type_name'      => 'user',
      'id'             => $capture_profile['id'],
      'attribute_name' => 'origin_id',
      'value'          => drupal_json_encode($origin_id),
    );

    $response = $this->call($command, $arg_array);
    return $this;
  }


  public function tokenIsFromRegister() {
    return (
      isset($_SESSION['janrain_capture_transaction_state']['capture']['action'])
      && in_array($_SESSION['janrain_capture_transaction_state']['capture']['action'], array('legacy_register', 'finish_third_party'))
    );
  }

}
