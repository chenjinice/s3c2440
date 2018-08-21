#ifndef __S3C2440_DEFS_H__
#define __S3C2440_DEFS_H__


#define     __REG(x)		(*(volatile unsigned int *)(x)) 
#define     __REG_BYTE(x)	(*(volatile unsigned char *)(x)) 

//GPIOA 
#define GPACON __REG(0x56000000)
#define GPADAT __REG(0x56000004)
//GPIOB
#define GPBCON __REG(0x56000010)
#define GPBDAT __REG(0x56000014)
#define GPBUP  __REG(0x56000018)
//GPIOC
#define GPCCON __REG(0x56000020)
#define GPCDAT __REG(0x56000024)
#define GPCUP  __REG(0x56000028)
//GPIOD
#define GPDCON __REG(0x56000030)
#define GPDDAT __REG(0x56000034)
#define GPDUP  __REG(0x56000038)
//GPIOE
#define GPECON __REG(0x56000040)
#define GPEDAT __REG(0x56000044)
#define GPEUP  __REG(0x56000048)
//GPIOF
#define GPFCON __REG(0x56000050)
#define GPFDAT __REG(0x56000054)
#define GPFUP  __REG(0x56000058)
//GPIOG
#define GPGCON __REG(0x56000060)
#define GPGDAT __REG(0x56000064)
#define GPGUP  __REG(0x56000068) 
//GPIOH
#define GPHCON __REG(0x56000070)
#define GPHDAT __REG(0x56000074)
#define GPHUP  __REG(0x56000078) 
//GPIOJ
#define GPJCON __REG(0x560000d0)
#define GPJDAT __REG(0x560000d4)
#define GPJUP  __REG(0x560000d8) 

//UART
#define ULCON0  	__REG(0x50000000)
#define UCON0   	__REG(0x50000004)
#define UBRDIV0 	__REG(0x50000028)
#define UTXH0   	__REG_BYTE(0x50000020)
#define URXH0   	__REG_BYTE(0x50000024)
#define UTRSTAT0	__REG(0x50000010)
#define UERSTAT0	__REG(0x50000014)


/*Memory Controllers*/
#define     BWSCON	__REG(0x48000000)   //Bus width & wait status control   
#define     BANKCON0	__REG(0x48000004)   //Boot ROM control                  
#define     BANKCON1	__REG(0x48000008)   //BANK1 control                     
#define     BANKCON2	__REG(0x4800000C)   //BANK2 control                     
#define     BANKCON3	__REG(0x48000010)   //BANK3 control                     
#define     BANKCON4	__REG(0x48000014)   //BANK4 control                     
#define     BANKCON5	__REG(0x48000018)   //BANK5 control                     
#define     BANKCON6	__REG(0x4800001C)   //BANK6 control                     
#define     BANKCON7	__REG(0x48000020)   //BANK7 control                     
#define     REFRESH	__REG(0x48000024)   //DRAM/SDRAM refresh control        
#define     BANKSIZE	__REG(0x48000028)   //Flexible bank size                
#define     MRSRB6	__REG(0x4800002C)   //Mode register set for SDRAM BANK6 
#define     MRSRB7	__REG(0x48000030)   //Mode register set for SDRAM BANK7 




#endif 



