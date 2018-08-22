#include "led.h"
#include "s3c2440_defs.h"

int g_a = 0x63;
int g_b = 20;
int g_c;

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
//	     puts("hello ,chen jin\n");
	     putchar(g_a);
	     led10_toggle();
    }
    return 0;

}


