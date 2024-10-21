add_compile_definitions(LED_DELAY_MS=100)

add_executable(task_delay task_delay.c)
pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)
target_link_libraries(task_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  pico_cyw43_arch_none
  FreeRTOS-Kernel-Heap4
)
pico_add_extra_outputs(task_delay)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:task_delay> DEPENDS task_delay)


add_executable(timer timer.c)
pico_enable_stdio_uart(timer 0)
pico_enable_stdio_usb(timer 1)
target_link_libraries(timer PRIVATE pico_stdlib pico_cyw43_arch_none)
pico_add_extra_outputs(timer)
add_custom_target(flash_timer picotool load -f $<TARGET_FILE:timer> DEPENDS timer)


add_executable(sleep sleep.c)
pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)
target_link_libraries(sleep PRIVATE pico_stdlib pico_cyw43_arch_none)
pico_add_extra_outputs(sleep)
add_custom_target(flash_sleep picotool load -f $<TARGET_FILE:sleep> DEPENDS sleep)


add_executable(rtc_alarm rtc.c)
pico_enable_stdio_uart(rtc_alarm 0)
pico_enable_stdio_usb(rtc_alarm 1)
target_link_libraries(rtc_alarm PRIVATE pico_stdlib pico_cyw43_arch_none hardware_rtc)
pico_add_extra_outputs(rtc_alarm)
add_custom_target(flash_rtc picotool load -f $<TARGET_FILE:rtc_alarm> DEPENDS rtc_alarm)
