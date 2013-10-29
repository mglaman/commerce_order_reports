<?php

/**
 * @file
 * Default rules configurations for Commerce Order Reports.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_order_reports_default_rules_configuration() {
  $configs = array();
  $rule = '{ "rules_commerce_order_report_create_report_record" : {
    "LABEL" : "Commerce Order Report: create report record",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "10",
    "TAGS" : [ "Commerce Order Report" ],
    "REQUIRES" : [ "commerce_order_reports", "commerce_payment" ],
    "ON" : [ "commerce_payment_order_paid_in_full" ],
    "DO" : [
      { "commerce_order_report_add_entry" : {
          "USING" : { "commerce_order" : [ "commerce_order" ] },
          "PROVIDE" : { "commerce_order_reports_entity" : { "commerce_order_reports_entity" : "Report Entity" } }
        }
      }
    ]
  }
}';
  $configs['rules_commerce_order_report_create_report_record'] = rules_import($rule);

  return $configs;
}
