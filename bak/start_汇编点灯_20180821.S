

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

	//设置栈顶指针
   ldr sp,=4096

	//1.关闭看门狗
	ldr r0,=0x53000000
	mov r1,#0
	str r1,[r0]	
	
	//2.设置时钟
	
	//3.初始化sdram
	
		
//	ldr r14,=halt
//	bl main	
	b test

test:
	ldr r0,=0x56000050
	ldr r1,=(1<<8)|(1<<10)|(1<<12)
	str r1,[r0]

	ldr r0,=300000
	bl	delay

	ldr r0,=0x56000054
	ldr r1,[r0]
	orr r1,r1,#(1<<4)
	str r1,[r0]


halt:
	ldr r0,=300000
	bl	delay

	ldr r0,=0x56000054
	ldr r1,[r0]
	orr r1,r1,#(1<<5)
	str r1,[r0]

	b halt


