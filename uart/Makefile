CROSS = arm-none-linux-gnueabi-
CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
    
all:
	$(CC) -g -c -o main.o main.c
	$(CC) -g -c -o uart.o uart.s
	$(LD) uart.o  -Tmap.lds main.o -o uart.elf
	$(OBJCOPY)  -O binary -S uart.elf uart.bin
	 
clean:
	rm -f *.o *.elf *.bin *.dis
