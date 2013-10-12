<?php

/**
 * @file
 * Default rules configurations for Commerce Gift Card.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_order_reports_default_rules_configuration() {
  $configs = array();
  $rule = '{ "rules_commerce_order_report_create_report_record" : {
    "LABEL" : "Commerce Order Report: create report record",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "Commerce Order Report" ],
    "REQUIRES" : [ "commerce_order_reports", "commerce_checkout", "entity" ],
    "ON" : [ "commerce_checkout_complete", "commerce_order_update" ],
    "DO" : [
      { "commerce_order_report_add_entry" : { "commerce_order" : [ "commerce_order" ] } }
    ]
  }
}';
  $configs['rules_commerce_order_report_create_report_record'] = rules_import($rule);
  return $configs;
}
