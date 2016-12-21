CROSS = arm-none-linux-gnueabi-
CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy
    
all:
	$(CC) -g -c -o main.o main.c
	$(CC) -g -c -o first.o first.s
	$(LD) main.o first.o  -Tmap.lds -o led.elf
	$(OBJCOPY)  -O binary -S led.elf led.bin
	 
clean:
	rm -f *.o *.elf *.bin *.dis
