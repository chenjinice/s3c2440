#ifndef __S3C2440_DEFS_H__
#define __S3C2440_DEFS_H__


//GPIOA 
#define GPACON (*(volatile unsigned int *)0x56000000)
#define GPADAT (*(volatile unsigned int *)0x56000004)
//GPIOB
#define GPBCON (*(volatile unsigned int *)0x56000010)
#define GPBDAT (*(volatile unsigned int *)0x56000014)
#define GPBUP  (*(volatile unsigned int *)0x56000018)
//GPIOC
#define GPCCON (*(volatile unsigned int *)0x56000020)
#define GPCDAT (*(volatile unsigned int *)0x56000024)
#define GPCUP  (*(volatile unsigned int *)0x56000028)
//GPIOD
#define GPDCON (*(volatile unsigned int *)0x56000030)
#define GPDDAT (*(volatile unsigned int *)0x56000034)
#define GPDUP  (*(volatile unsigned int *)0x56000038)
//GPIOE
#define GPECON (*(volatile unsigned int *)0x56000040)
#define GPEDAT (*(volatile unsigned int *)0x56000044)
#define GPEUP  (*(volatile unsigned int *)0x56000048)
//GPIOF
#define GPFCON (*(volatile unsigned int *)0x56000050)
#define GPFDAT (*(volatile unsigned int *)0x56000054)
#define GPFUP  (*(volatile unsigned int *)0x56000058)
//GPIOG
#define GPGCON (*(volatile unsigned int *)0x56000060)
#define GPGDAT (*(volatile unsigned int *)0x56000064)
#define GPGUP  (*(volatile unsigned int *)0x56000068) 
//GPIOH
#define GPHCON (*(volatile unsigned int *)0x56000070)
#define GPHDAT (*(volatile unsigned int *)0x56000074)
#define GPHUP  (*(volatile unsigned int *)0x56000078) 
//GPIOJ
#define GPJCON (*(volatile unsigned int *)0x560000d0)
#define GPJDAT (*(volatile unsigned int *)0x560000d4)
#define GPJUP  (*(volatile unsigned int *)0x560000d8) 

#endif 



