#include "s3c2440_defs.h"
#include "uart0.h"

void uart0_init(void)
{
    GPHCON |= (2<<4)|(2<<6);
    GPHUP  &= !((1<<2)|(1<<3)); //使能上拉

	 //设置数据格式
    ULCON0 = 0x00000003;    //8n1:8数据位，无校验位，1停止位

	 //设置波特率 ,PCLK在start.S已设置为 50M，
    //则 (50000000)/(115200x16) - 1 = 26
    UBRDIV0 = 26;

	 UCON0 = 0x00000005; //PCLK,中断查询模式

}

int putchar(int c)
{
    while (!(UTRSTAT0 & (1<<2)));
    UTXH0 = (unsigned char)c;
    return 0;
}

int getchar(void)
{
    while(!(UTRSTAT0 & (1<<0)));
    return URXH0;
}

int puts(char *s)
{
    while(*s)
    {
        putchar(*s);
        s++;
    }
}

