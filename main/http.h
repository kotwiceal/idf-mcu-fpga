#include <string.h>
#include "esp_log.h"
#include "esp_system.h"
#include "esp_http_server.h"
#include "config.h"

static const char *TAG_HTTP_SERVER = "HTTP";

esp_err_t handle_url_root(httpd_req_t *req) {
    ESP_LOGI(TAG_HTTP_SERVER, "GET request");
    return httpd_resp_send(req, "test", HTTPD_RESP_USE_STRLEN);
}

httpd_uri_t uri_get_root = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = handle_url_root,
    .user_ctx = NULL
};

httpd_handle_t init_http(void) {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = ESP_HTTP_PORT;
    httpd_handle_t server  = NULL;

    if (httpd_start(&server , &config) == ESP_OK) {
        httpd_register_uri_handler(server , &uri_get_root);
    } else {
        ESP_LOGI(TAG_HTTP_SERVER, "failed to launch server");
    }

    return server;
}