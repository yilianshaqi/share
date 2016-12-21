CROSS = arm-none-linux-gnueabi-
CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
    
all:
	$(CC) -g -c -o start.o start.s
	$(LD) start.o -Tmap.lds -o led.elf
	$(OBJCOPY)  -O binary -S led.elf led.bin
	 
clean:
	rm -f *.o *.elf *.bin *.dis
