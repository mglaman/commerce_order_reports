## Commerce Order Reports

This module aims to provide a solid reporting system for Drupal Commerce, hoping to be a successor of Commerce Reports.

Reasoning for this module:

* Commerce Reports is based on order creation date and not checkout, technically certain orders could be created a day before checkout is finished, or midnight purchases.
* Commerce Google Analytics triggers on checkout complete, therefore if you're using Commerce Reports and Google Analytics you will have two different datasets.
* Reliable data from time of checkout.

### How it works

Commerce Order Reports creates a new entity that stores data about orders, specifically (for now):

* Base price (includes discounts and coupons)
* Shipping cost
* Tax amount

The module enables a rule which triggers on the event "Order paid in full" - this was chosen over completed checkout for admin created and fulfilled orders.
