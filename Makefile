
CC  = arm-linux-gcc
NAME = build/s3c2440
INC += -Iinc/
BIN = $(NAME).bin
ELF = $(NAME).elf
DIS = $(NAME).dis

OBJS += start.o
OBJS += main.o
OBJS += src/s3c2440_it.o
OBJS += src/led.o
OBJS += src/uart0.o

all:$(OBJS)
	arm-linux-ld -Ttext 0 $(OBJS) -o $(ELF) 
	arm-linux-objcopy -O binary -S $(ELF) $(BIN)
	arm-linux-objdump -D $(ELF) > $(DIS)

%.o:%.S
	arm-linux-gcc -c -o $@ $<

%.o:%.c
	arm-linux-gcc $(INC) -c -o $@ $<

clean:
	rm -f $(OBJS) $(BIN) $(ELF) $(DIS)



