CROSS = arm-none-linux-gnueabi-
CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
    
all:
	$(CC) -g -c -o main.o main.c
	$(CC) -g -c -o start.o start.s
	$(LD) start.o  -Tmap.lds main.o -o start.elf
	$(OBJCOPY)  -O binary -S start.elf interrupt.bin
	 
clean:
	rm -f *.o *.elf *.bin *.dis
