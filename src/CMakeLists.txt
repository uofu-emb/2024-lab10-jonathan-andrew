add_compile_definitions(
    DELAY_MS=100
    IN_PIN=6
    OUT_PIN=7)

add_executable(task_delay task_delay.c)
pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)
target_link_libraries(task_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
pico_add_extra_outputs(task_delay)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:task_delay> DEPENDS task_delay)


add_executable(sleep sleep.c)
pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)
target_link_libraries(sleep PRIVATE pico_stdlib)
pico_add_extra_outputs(sleep)
add_custom_target(flash_sleep picotool load -f $<TARGET_FILE:sleep> DEPENDS sleep)


add_executable(irq gpio_interrupt.c)
pico_enable_stdio_uart(irq 0)
pico_enable_stdio_usb(irq 1)
target_link_libraries(irq PRIVATE pico_stdlib)
pico_add_extra_outputs(irq)
add_custom_target(flash_irq picotool load -f $<TARGET_FILE:irq> DEPENDS irq)


add_executable(loop loop.c)
pico_enable_stdio_uart(loop 0)
pico_enable_stdio_usb(loop 1)
target_link_libraries(loop PRIVATE pico_stdlib)
pico_add_extra_outputs(loop)
add_custom_target(flash_loop picotool load -f $<TARGET_FILE:loop> DEPENDS loop)


add_executable(sleep_alarm hello_sleep_alarm.c)
pico_enable_stdio_uart(sleep_alarm 0)
pico_enable_stdio_usb(sleep_alarm 1)
target_link_libraries(sleep_alarm PRIVATE pico_stdlib hardware_sleep)
pico_add_extra_outputs(sleep_alarm)
add_custom_target(flash_sleep_alarm picotool load -f $<TARGET_FILE:sleep_alarm> DEPENDS sleep_alarm)


add_executable(dormant hello_dormant_gpio.c)
pico_enable_stdio_uart(dormant 0)
pico_enable_stdio_usb(dormant 1)
target_link_libraries(dormant PRIVATE pico_stdlib hardware_sleep)
pico_add_extra_outputs(dormant)
add_custom_target(flash_dormant picotool load -f $<TARGET_FILE:dormant> DEPENDS dormant)