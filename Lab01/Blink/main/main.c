#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    gpio_config_t config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << GPIO_NUM_2,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&config));
    uint8_t state = 0;
    while (1) {
        gpio_set_level(GPIO_NUM_2,state);
        printf("LED state: %d\r\n",state);
        // vtaskm
        vTaskDelay(1000/portTICK_PERIOD_MS);
        state = !state;
    }

}