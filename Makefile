.PHONY: all debug clean gdb

all:
	aarch64-none-linux-gnu-gcc -c bootloader.c
	aarch64-none-linux-gnu-ld -T linker.ld -o kernel8.elf bootloader.o
	aarch64-none-linux-gnu-objcopy -O binary kernel8.elf kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

debug:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -S -s

gdb:
	aarch64-none-linux-gnu-gdb

clean:
	rm -f bootloader.o;
	rm -f kernel8.elf;
	rm -f kernel8.img;
