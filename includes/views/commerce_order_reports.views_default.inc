<?php
/**
 * @file
 * Default views.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_order_reports_views_default_views() {

  $view = new view();
  $view->name = 'daily_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order_reports';
  $view->human_name = 'Daily Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Daily Report';
  $handler->display->display_options['css_class'] = 'commerce-order-reports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Commerce Order Reports: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order_reports';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order Reports: Commerce Order */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_order_reports';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order Reports: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  /* Field: Commerce Order Reports: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Commerce Order Reports: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order Number';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order Reports: Order Total */
  $handler->display->display_options['fields']['base_total']['id'] = 'base_total';
  $handler->display->display_options['fields']['base_total']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['base_total']['field'] = 'base_total';
  $handler->display->display_options['fields']['base_total']['label'] = 'Total';
  /* Field: Commerce Order Reports: Order Shipping */
  $handler->display->display_options['fields']['shipping']['id'] = 'shipping';
  $handler->display->display_options['fields']['shipping']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['shipping']['field'] = 'shipping';
  $handler->display->display_options['fields']['shipping']['label'] = 'Shipping';
  /* Field: Commerce Order Reports: Order Tax */
  $handler->display->display_options['fields']['tax']['id'] = 'tax';
  $handler->display->display_options['fields']['tax']['table'] = 'commerce_order_reports';
  $handler->display->display_options['fields']['tax']['field'] = 'tax';
  $handler->display->display_options['fields']['tax']['label'] = 'Tax';
  /* Filter criterion: Date: Date (commerce_order_reports) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order_reports';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Orders from day';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Pick which day you would like to generate a report of sales for.';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order_reports.created' => 'commerce_order_reports.created',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/daily-report';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Daily Report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /**
   * Integration with views data export.
   */
  if (module_exists('views_data_export')) {
    /* Display: CSV Export */
    $handler = $view->new_display('views_data_export', 'CSV Export', 'views_data_export_1');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
    $handler->display->display_options['style_options']['provide_file'] = 1;
    $handler->display->display_options['style_options']['parent_sort'] = 0;
    $handler->display->display_options['style_options']['quote'] = 1;
    $handler->display->display_options['style_options']['trim'] = 1;
    $handler->display->display_options['style_options']['replace_newlines'] = 0;
    $handler->display->display_options['style_options']['header'] = 1;
    $handler->display->display_options['style_options']['encoding'] = 'ASCII';
    $handler->display->display_options['path'] = 'admin/commerce/daily-report/csv';
    $handler->display->display_options['displays'] = array(
      'page' => 'page',
      'default' => 0,
    );

    /* Display: XLS Export */
    $handler = $view->new_display('views_data_export', 'XLS Export', 'views_data_export_2');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
    $handler->display->display_options['style_options']['provide_file'] = 1;
    $handler->display->display_options['style_options']['parent_sort'] = 0;
    $handler->display->display_options['path'] = 'admin/commerce/daily-report/xls';
    $handler->display->display_options['displays'] = array(
      'page' => 'page',
      'default' => 0,
    );
  }

  $views[$view->name] = $view;

  return $views;

}
