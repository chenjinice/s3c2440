#include "s3c2440_defs.h"
#include "led.h"

void led_init(void)
{
	GPFCON |= ((1<<8)|(1<<10)|(1<<12));

	led10_off();
	led11_off();
	led12_off();
}

void led10_on(void)
{
	GPFDAT &= ~(1<<4);
}

void led10_off(void)
{
	GPFDAT |= 1<<4;
}

void led10_toggle(void)
{
	GPFDAT ^= (1<<4);
}

void led11_on(void)
{
	GPFDAT &= ~(1<<5);
} 

void led11_off(void)
{
	GPFDAT |= 1<<5;
}

void led11_toggle(void)
{
	GPFDAT ^= (1<<5);
}

void led12_on(void)
{
	GPFDAT &= ~(1<<6);
}

void led12_off(void)
{
	GPFDAT |= 1<<6;
}

void led12_toggle(void)
{
	GPFDAT ^= (1<<6);
}


