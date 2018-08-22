
.text
.global _start

_start:
	/* 中断向量表, 按手册来设置
	0x00000000 Reset 
	0x00000004 Undefined instruction
	0x00000008 Software Interrupt 
	0x0000000C Abort (prefetch) 
	0x00000010 Abort (data) 
	0x00000014 Reserved 
	0x00000018 IRQ
	0x0000001C FIQ 
	*/
	b Reset_handler
	b Undefined_instruction_handler
	b Swi_handler
	b Abort_prefetch_handler
	b Abort_data_handler
	b Reserved_handler
	b Irq_handler
	b Fiq_hender


Reset_handler:

//1.关闭看门狗
	ldr r0,=0x53000000
	mov r1,#0
	str r1,[r0]	
	
//2.设置时钟,
	//tFCLK：tHCLK：tPCLK = 1:4:8
	ldr r0,=0x4C000014
	ldr r1,=0x5
	str r1,[r0]
	//设置cup工作在异步模式
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xC0000000
	mcr p15,0,r0,c1,c0,0
	//设置MPLL，输出频率设为 400M
	ldr r0,=0x4C000004
	ldr r1,=(92<<12)|(1<<4)|(1<<0)
	str r1,[r0]

//3.初始化sdram
	ldr r0,=0x48000000
	add r1,r0,#(13*4)
	adr r2,sdram_config
sdram:
	ldr r3,[r2],#4
	str r3,[r0],#4
	cmp r1,r0
	bne sdram


	//设置栈顶指针
	ldr sp,=(0x30000000+100000)

	bl nand_init

	//代码拷贝进sdram
	ldr r0,=_start
	mov r1,#0
	ldr r2,=_bss_start
	sub r2,r2,r0
	bl copy_to_sdram

	bl clear_bss

//	bl main	  // 使用bl是相对跳转，程序仍在nor或片内4k的sram中运行

	ldr lr,=halt  //保存main函数返回后要运行的地址
	ldr pc,=main  //使用绝对跳转，去sdram中运行


halt:
	b halt


sdram_config:
	.long 0x22011110	 //BWSCON
	.long 0x00000700	 //BANKCON0
	.long 0x00000700	 //BANKCON1
	.long 0x00000700	 //BANKCON2
	.long 0x00000700	 //BANKCON3  
	.long 0x00000700	 //BANKCON4
	.long 0x00000700	 //BANKCON5
	.long 0x00018005	 //BANKCON6
	.long 0x00018005	 //BANKCON7
	.long 0x008C04F4	 // REFRESH
	.long 0x000000B1	 //BANKSIZE
	.long 0x00000030	 //MRSRB6
	.long 0x00000030	 //MRSRB7


