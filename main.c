#include "led.h"
#include "s3c2440_defs.h"

void delay(int count)
{
    while (count--);
}

int main(void)
{
    led_init();
    uart0_init();

    while (1)
    {
	     delay(1000000);
	     puts("hello ,chen jin\n");
	     led11_toggle();
    }
    return 0;

}
