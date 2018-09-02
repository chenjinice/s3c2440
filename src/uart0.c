#include "s3c2440_defs.h"
#include "uart0.h"

void uart0_init(void)
{
    __REG(0x56000070) |= (2<<4)|(2<<6);
//    GPHUP  &= !((1<<2)|(1<<3)); //使能上拉
    GPHUP = 0x7FF;

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

void printHex(int value)
{
    unsigned char arr[8] = {0};
    int i ;
    for(i=0;i<8;i++)
    {
        arr[i] = value & 0xf;
        value >>= 4;
    }
    puts("0x");
    for(i=7;i>=0;i--)
    {
        if(arr[i] >= 0 && arr[i] <= 9)
        {
            putchar(arr[i]+'0');
        }
        else if(arr[i] >= 0xA)
        {
            putchar(arr[i]-0xA+'A');
        }
    }
}