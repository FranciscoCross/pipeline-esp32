
#include <stdint.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED 5     // LED connected to GPIO2
#define DELAY 500 // milliseconds to delay blink

void blink_led(uint8_t led, uint16_t delay);

int app_main()
{
    // Configure pin
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << LED);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    // Main loop
    // TEST WORKFLOW2
    blink_led(LED, DELAY);

    return 0;
}


void blink_led(uint8_t led, uint16_t delay)
{

    while (1)
    {
        gpio_set_level(led, 0);
        vTaskDelay(pdMS_TO_TICKS(delay));
        gpio_set_level(led, 1);
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
}
