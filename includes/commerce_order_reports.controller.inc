<?php

/**
 * @file
 * The controller for the order entity containing the CRUD operations.
 */

/**
 * The controller class for orders contains methods for the order CRUD
 * operations. The load method is inherited from the default controller.
 */
class CommerceOrderReportsEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default order.
   *
   * @param array $values
   *   An array of values to set, keyed by property name.
   *
   * @return
   *   An order object with all default fields initialized.
   */
  public function create(array $values = array()) {
    $values += array(
      'report_id' => NULL,
      'order_id' => 0,
      'order_number' => 0,
      'uid' => '',
      'data' => array(),
      'created' => REQUEST_TIME,
    );

    return parent::create($values);
  }

  /**
   * Saves an order.
   *
   * When saving an order without an order ID, this function will create a new
   * order at that time. For new orders, it will also determine and save the
   * order number and then save the initial revision of the order. Subsequent
   * orders that should be saved as new revisions should set $order->revision to
   * TRUE and include a log string in $order->log.
   *
   * @param $order
   *   The full order object to save.
   * @param $transaction
   *   An optional transaction object.
   *
   * @return
   *   SAVED_NEW or SAVED_UPDATED depending on the operation performed.
   */
  public function save($order, DatabaseTransaction $transaction = NULL) {
    if (!isset($transaction)) {
      $transaction = db_transaction();
      $started_transaction = TRUE;
    }

    try {
      global $user;

      // Determine if we will be inserting a new order.
      $order->is_new = empty($order->report_id);

      // Set the timestamp fields.
      if ($order->is_new && empty($order->created)) {
        $order->created = REQUEST_TIME;
      }
      else {
        // Otherwise if the order is not new but comes from an entity_create()
        // or similar function call that initializes the created timestamp, uid,
        // and hostname values to empty strings, unset them to prevent
        // destroying existing data in those properties on update.
        if ($order->created === '') {
          unset($order->created);
        }
        if ($order->uid === '') {
          unset($order->uid);
        }
      }

      return parent::save($order, $transaction);
    }
    catch (Exception $e) {
      if (!empty($started_transaction)) {
        $transaction->rollback();
        watchdog_exception($this->entityType, $e);
      }
      throw $e;
    }
  }

  /**
   * Unserializes the data property of loaded orders.
   */
  public function attachLoad(&$queried_orders, $revision_id = FALSE) {
    foreach ($queried_orders as $order_id => &$order) {
      $order->data = unserialize($order->data);
    }

    // Call the default attachLoad() method. This will add fields and call
    // hook_commerce_order_load().
    parent::attachLoad($queried_orders, $revision_id);
  }
}
