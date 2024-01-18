.PHONY: all debug clean gdb objdump

all:
	aarch64-none-linux-gnu-gcc -c _start.c
	aarch64-none-linux-gnu-ld -T linker.ld -o kernel8.elf _start.o
	aarch64-none-linux-gnu-objcopy -O binary kernel8.elf kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

objdump:
	aarch64-none-linux-gnu-objdump -D kernel8.elf

qemu:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -S -s

gdb:
	aarch64-none-linux-gnu-gdb

clean:
	rm -f *.o;
	rm -f *.elf;
	rm -f *.img;
