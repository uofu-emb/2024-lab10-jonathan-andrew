#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include <pico/sync.h>

int toggle = 1;
bool timer_callback(__unused struct repeating_timer *t)
{
    toggle = !toggle;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, toggle);
    return true;
}

int main(void)
{
    hard_assert(cyw43_arch_init() == PICO_OK);
    stdio_init_all();
    // Create a repeating timer that calls timer_callback.
    // If the delay is > 0 then this is the delay between the previous
    // callback ending and the next starting.
    // If the delay is negative (see below) then the next call to the
    // callback will be exactly 500ms after the start of the call to
    // the last callback
    repeating_timer_t timer;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, toggle);
    add_repeating_timer_ms(-LED_DELAY_MS, timer_callback, NULL, &timer);
    while(1) __nop();
    return 0;
}
