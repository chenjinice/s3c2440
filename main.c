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
	     delay(3000000);
	     puts("hello ,chen jin\n\r");
//	     putchar(g_a);
	     led11_toggle();

         // extern int _bss_start,_start;
         // puts("-----------------------\n\r");
         // printHex(_bss_start);puts("\n\r");
         // printHex(&_bss_start);puts("\n\r");
         // printHex(_start);puts("\n\r");
         // printHex(&_start);puts("\n\r");

    }
    return 0;

}


