#include "init.h"


/* NAND FLASH控制器 */
#define NFCONF (*((volatile unsigned long *)0x4E000000))
#define NFCONT (*((volatile unsigned long *)0x4E000004))
#define NFCMMD (*((volatile unsigned char *)0x4E000008))
#define NFADDR (*((volatile unsigned char *)0x4E00000C))
#define NFDATA (*((volatile unsigned char *)0x4E000010))
#define NFSTAT (*((volatile unsigned char *)0x4E000020))

/* GPIO */
#define GPHCON              (*(volatile unsigned long *)0x56000070)
#define GPHUP               (*(volatile unsigned long *)0x56000078)

/* UART registers*/
#define ULCON0              (*(volatile unsigned long *)0x50000000)
#define UCON0               (*(volatile unsigned long *)0x50000004)
#define UFCON0              (*(volatile unsigned long *)0x50000008)
#define UMCON0              (*(volatile unsigned long *)0x5000000c)
#define UTRSTAT0            (*(volatile unsigned long *)0x50000010)
#define UTXH0               (*(volatile unsigned char *)0x50000020)
#define URXH0               (*(volatile unsigned char *)0x50000024)
#define UBRDIV0             (*(volatile unsigned long *)0x50000028)

#define TXD0READY   (1<<2)


void nand_read(unsigned int addr, unsigned char *buf, unsigned int len);


int check_boot_flash(void)
{
	volatile int *offset_sram =  (volatile int *)0x10;
	volatile int *offset_sdram = (volatile int *)0x30000010;

	int v1 = *offset_sram;
	int v2 = *offset_sdram;

	if(v1 == v2)
	{
		*offset_sdram = v2 + 1;
		if(*offset_sram == *offset_sdram)
		{
			*offset_sdram = v2;
			return 0;
		}
		else
		 {
		 	*offset_sdram = v2;
			return 1;
		}
	}
	else
	{
		return 1;
	}

}

void copy_to_sdram(unsigned char *dest,unsigned char *src,unsigned int len)
{
	if(check_boot_flash())
	{
		unsigned int count  = 0;
		while(count++ < len)
		{
			*dest++ = *src++;
		}
	}
	else
	{
		nand_read((unsigned int)src, dest, len);
	}

}

void clear_bss(void)
{
	extern int _bss_start,_bss_end;
	int *p;

	for(p = &_bss_start;p<&_bss_end;p++)
	{
		*p = 0;
	}
}


void nand_init(void)
{
#define TACLS   0
#define TWRPH0  1
#define TWRPH1  0
	/* 设置时序 */
	NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
	/* 使能NAND Flash控制器, 初始化ECC, 禁止片选 */
	NFCONT = (1<<4)|(1<<1)|(1<<0);	
}

void nand_select(void)
{
	NFCONT &= ~(1<<1);	
}

void nand_deselect(void)
{
	NFCONT |= (1<<1);	
}

void nand_cmd(unsigned char cmd)
{
	volatile int i;
	NFCMMD = cmd;
	for (i = 0; i < 10; i++);
}

void nand_addr(unsigned int addr)
{
	unsigned int col  = addr % 2048;
	unsigned int page = addr / 2048;
	volatile int i;

	NFADDR = col & 0xff;
	for (i = 0; i < 10; i++);
	NFADDR = (col >> 8) & 0xff;
	for (i = 0; i < 10; i++);
	
	NFADDR  = page & 0xff;
	for (i = 0; i < 10; i++);
	NFADDR  = (page >> 8) & 0xff;
	for (i = 0; i < 10; i++);
	NFADDR  = (page >> 16) & 0xff;
	for (i = 0; i < 10; i++);	
}

void nand_wait_ready(void)
{
	while (!(NFSTAT & 1));
}

unsigned char nand_data(void)
{
	return NFDATA;
}

void nand_read(unsigned int addr, unsigned char *buf, unsigned int len)
{
	int col = addr % 2048;
	int i = 0;
		
	/* 1. 选中 */
	nand_select();

	while (i < len)
	{
		/* 2. 发出读命令00h */
		nand_cmd(0x00);

		/* 3. 发出地址(分5步发出) */
		nand_addr(addr);

		/* 4. 发出读命令30h */
		nand_cmd(0x30);

		/* 5. 判断状态 */
		nand_wait_ready();

		/* 6. 读数据 */
		for (; (col < 2048) && (i < len); col++)
		{
			buf[i] = nand_data();
			i++;
			addr++;
		}
		
		col = 0;
	}

	/* 7. 取消选中 */		
	nand_deselect();
}

