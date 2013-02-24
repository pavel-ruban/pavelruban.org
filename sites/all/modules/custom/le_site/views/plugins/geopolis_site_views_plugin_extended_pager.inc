<?php

/**
 * @file
 * The plugin to handle full pager.
 *
 * @ingroup views_pager_plugins
 */
class geopolis_site_views_plugin_extended_pager extends views_plugin_pager {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'Paged, @count item, skip @skip', 'Paged, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
    return format_plural($this->options['items_per_page'], 'Paged, @count item', 'Paged, @count items', array('@count' => $this->options['items_per_page']));
  }

  /**
   * Definition of default options for plugin.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['items_per_page'] = array('default' => 10);
    $options['items_on_first_page'] = array('default' => 0);
    $options['offset'] = array('default' => 0);
    $options['id'] = array('default' => 0);
    $options['total_pages'] = array('default' => '');

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    $form['items_per_page'] = array(
      '#title' => t('Items per page'),
      '#type' => 'textfield',
      '#description' => t('The number of items to display per page. Enter 0 for no limit.'),
      '#default_value' => $this->options['items_per_page'],
    );

    $form['items_on_first_page'] = array(
      '#title' => t('Items on first page'),
      '#type' => 'textfield',
      '#description' => t("The number of items to display on the first page. Enter 0 for same number as for rest of the pages or -1 to show NO nodes on the first page."),
      '#default_value' => $this->options['items_on_first_page'],
    );

    $form['offset'] = array(
      '#type' => 'textfield',
      '#title' => t('Offset'),
      '#description' => t('The number of items to skip. For example, if this field is 3, the first 3 items will be skipped and not displayed.'),
      '#default_value' => $this->options['offset'],
    );

    $form['id'] = array(
      '#type' => 'textfield',
      '#title' => t('Pager ID'),
      '#description' => t("Unless you're experiencing problems with pagers related to this view, you should leave this at 0. If using multiple pagers on one page you may need to set this number to a higher value so as not to conflict within the ?page= array. Large values will add a lot of commas to your URLs, so avoid if possible."),
      '#default_value' => $this->options['id'],
    );

    $form['total_pages'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of pages'),
      '#description' => t('The total number of pages. Leave empty to show all pages.'),
      '#default_value' => $this->options['total_pages'],
    );
  }

  /**
   * Overrides base query() function, adds limits for pager.
   */
  function query() {
    if ($this->current_page == 0) {
      $limit = $this->options['items_on_first_page'];
      $offset = $this->options['offset'];
    }
    else {
      $limit = $this->options['items_per_page'];
      if (isset($this->options['items_on_first_page']) && $this->options['items_on_first_page'] != 0) {
        $items_on_first_page = $this->options['items_on_first_page'] > 0 ? $this->options['items_on_first_page'] : 0;
        $offset = ($this->current_page - 1) * $this->options['items_per_page'] + $items_on_first_page + $this->options['offset'];
      }
      else {
        $offset = $this->current_page * $this->options['items_per_page'] + $this->options['offset'];
      }
    }
    if (!empty($this->options['total_pages'])) {
      if ($this->current_page >= $this->options['total_pages']) {
        $limit = $this->options['items_per_page'];
        if ($this->get_items_on_first_page() != 0) {
          $offset = ($this->options['total_pages'] -1) * $this->options['items_per_page'] + $this->get_items_on_first_page();
        }
        else {
          $offset = $this->options['total_pages'] * $this->options['items_per_page'];
        }
      }
    }

    $this->view->query->set_limit($limit);
    $this->view->query->set_offset($offset);
  }

  /**
   * Pager render function.
   * @return string
   */
  function render($input) {
    $pager_theme = views_theme_functions('pager', $this->view, $this->display);
    $output = theme($pager_theme, array(
      'tags' => $input, 'element' => $this->options['id']));
    return $output;
  }

  /**
   * Getter method for "items on first page" option
   * @return array
   *    Number of items to show on the first page of the view
   */
  function get_items_on_first_page() {
    if (!isset($this->options['items_on_first_page'])) {
      return $this->options['items_per_page'];
    }
    if ($this->options['items_on_first_page'] < 0) {
      return 0;
    }
    else {
      return $this->options['items_on_first_page'] > 0 ? $this->options['items_on_first_page'] : $this->options['items_per_page'];
    }
  }

  /**
   * Set the current page.
   *
   * @param $number
   *   If provided, the page number will be set to this. If NOT provided,
   *   the page number will be set from the global page array.
   */
  function set_current_page($number = NULL) {
    if (isset($number)) {
      $this->current_page = $number;
      return;
    }

    // If the current page number was not prespecified, default to pulling it from 'page'
    // based upon
    global $pager_page_array;
    // Extract the ['page'] info.
    $pager_page_array = isset($_GET['page']) ? explode(',', $_GET['page']) : array(0);

    $this->current_page = 0;
    if (!empty($pager_page_array[$this->options['id']])) {
      $this->current_page = intval($pager_page_array[$this->options['id']]);
    }
  }

  /**
   * Returns number of pages for the view.
   * @return float|int
   */
  function get_pager_total() {
    if ($items_per_page = intval($this->get_items_per_page())) {
      if ((isset($this->options['items_on_first_page'])) && $this->options['items_on_first_page'] != 0) {
        $items_on_first_page = $this->options['items_on_first_page'] > 0 ? $this->options['items_on_first_page'] : 0;
        return 1 + ceil(($this->total_items - $items_on_first_page) / $items_per_page);
      }
      else {
        return ceil($this->total_items / $items_per_page);
      }
    }
    else {
      return 1;
    }
  }

  /**
   * Update global paging info.
   *
   * This is called after the count query has been run to set the total
   * items available and to update the current page if the requested
   * page is out of range.
   */
  function update_page_info() {
    if (!empty($this->options['total_pages'])) {
      if ((isset($this->options['items_on_first_page'])) && $this->options['items_on_first_page'] != 0) {
        $items_on_first_page = $this->options['items_on_first_page'] > 0 ? $this->options['items_on_first_page'] : 0;
        $total = ($this->options['total_pages'] -1) * $this->options['items_per_page'] + $items_on_first_page;
      }
      else {
        $total = $this->options['total_pages'] * $this->options['items_per_page'];
      }
      if ($total < $this->total_items) {
        $this->total_items = $total;
      }
    }

    // Don't set pager settings for items per page = 0.
    $items_per_page = $this->get_items_per_page();
    if (!empty($items_per_page)) {
      // Dump information about what we already know into the globals.
      global $pager_page_array, $pager_total, $pager_total_items;
      // Set the item count for the pager.
      $pager_total_items[$this->options['id']] = $this->total_items;
      // Calculate and set the count of available pages.
      $pager_total[$this->options['id']] = $this->get_pager_total();

      // See if the requested page was within range:
      if ($this->current_page < 0) {
        $this->current_page = 0;
      }
      else if ($this->current_page >= $pager_total[$this->options['id']]) {
        // Pages are numbered from 0 so if there are 10 pages, the last page is 9.
        $this->current_page = $pager_total[$this->options['id']] - 1;
      }

      // Put this number in to guarantee that we do not generate notices when the pager
      // goes to look for it later.
      $pager_page_array[$this->options['id']] = $this->current_page;
    }
  }

}
