<?php

/**
 * @file
 * Rules integration for Gift Card.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Rules Actions
 */
function commerce_order_reports_rules_action_info() {
  return array(
    'commerce_order_report_add_entry' => array(
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
    ),
  );
}
/**
 * @}
 */
