<?php
/**
 * @file
 * geopolis_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function geopolis_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function geopolis_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function geopolis_search_default_search_api_index() {
  $items = array();
  $items['nodes_index'] = entity_import('search_api_index', '{
    "name" : "Nodes index",
    "machine_name" : "nodes_index",
    "description" : null,
    "server" : "search_server_multi",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_signature" : { "type" : "integer", "entity_type" : "user" },
        "field_signature_free" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "field_body:value" : { "type" : "text" },
        "field_signature:name" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "article" : "article", "review" : "review" }
          }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "metatags" : []
  }');
  $items['terms_index'] = entity_import('search_api_index', '{
    "name" : "Terms index",
    "machine_name" : "terms_index",
    "description" : null,
    "server" : "search_server_multi",
    "item_type" : "taxonomy_term",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "name" : { "type" : "text", "boost" : "5.0" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "place" : "place",
              "slugs" : "slugs",
              "institution" : "institution",
              "personality" : "personality",
              "event" : "event",
              "thematic" : "thematic",
              "language" : "language"
            }
          }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "metatags" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function geopolis_search_default_search_api_server() {
  $items = array();
  $items['search_server_multi'] = entity_import('search_api_server', '{
    "name" : "Search server multi",
    "machine_name" : "search_server_multi",
    "description" : "",
    "class" : "search_api_solr_service_multi",
    "options" : {
      "host" : "solr.adyax.com",
      "port" : "80",
      "path" : "\\/solr\\/geopolis-dev",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 1,
      "highlight_data" : 1
    },
    "enabled" : "1",
    "metatags" : []
  }');
  return $items;
}
