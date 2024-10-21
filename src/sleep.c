#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>

int main(void)
{
    hard_assert(cyw43_arch_init() == PICO_OK);
    stdio_init_all();
    int toggle = 0;
    while (true) {
        toggle = !toggle;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, toggle);
        sleep_ms(LED_DELAY_MS);
    }
}
