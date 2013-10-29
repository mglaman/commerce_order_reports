<?php

/**
 * @file
 * Rules integration for Commerce Order Reports
 * @addtogroup rules
 * @{
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_order_reports_rules_action_info() {
  $actions = array();

  $actions['commerce_order_report_add_entry'] = array(
    'label' => t('Add order report entry'),
    'group' => t('Commerce Order Reports'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Comemrce Order'),
      ),
    ),
    'provides' => array(
      'commerce_order_reports_entity' => array(
        'label' => t('Report Entity'),
        'type' => 'commerce_order_reports',
      ),
    ),
  );

  return $actions;
}
/**
 * @}
 */
