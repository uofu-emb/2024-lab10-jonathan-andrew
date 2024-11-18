#include <stdio.h>
#include <pico/stdlib.h>

int main(void)
{
    while (1)
    {
        volatile uint32_t k;
        for (volatile int i = 0; i < 30)
        {
            volatile uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
}
