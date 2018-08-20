#include "led.h"
#include "s3c2440_defs.h"

void delay(int count)
{
	while(count--);
}

int main(void)
{
	led_init();
    led11_on();
	led10_on();
	led12_on();
    delay(100000);
	led11_off();
	led10_off();
	led12_off();

	while(1)
	{
		delay(100000);
		led11_toggle();
	}
	return 0;
	
}
