#include <esp_system.h>
#include <nvs_flash.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_http_server.h"
#include "esp_timer.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

/* user defined libraries */
#include "wifi.h"
#include "http.h"

static const char *TAG_MAIN = "MAIN";

void app_main(void) {
    ESP_LOGI(TAG_MAIN, "initializing");

    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

    if (init_wifi() == ESP_OK) {
        httpd_handle_t server = init_http();
    }

}