<?php

/**
 * @file
 * Default rules configurations for Commerce Gift Card.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_gift_card_default_rules_configuration() {
  $configs = array();
  $rule = '{ "rules_commerce_order_report_set_checkout_tmestamp" : {
    "LABEL" : "Commerce Order Report: Set checkout tmestamp",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "commerce order report" ],
    "REQUIRES" : [ "rules", "commerce_checkout" ],
    "ON" : [ "commerce_checkout_complete" ],
    "IF" : [
      { "entity_has_field" : {
          "entity" : [ "commerce-order" ],
          "field" : "commerce_order_reports_checkout"
        }
      }
    ],
    "DO" : [
      { "data_set" : {
          "data" : [ "commerce-order:commerce-order-reports-checkout" ],
          "value" : "now"
        }
      },
      { "entity_save" : { "data" : [ "commerce-order" ], "immediate" : 1 } }
    ]
  }
}';
  $configs['rules_commerce_order_report_set_checkout_tmestamp'] = rules_import($rule);
  return $configs;
}
