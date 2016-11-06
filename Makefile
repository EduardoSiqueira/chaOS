
OBJECTS = kernel.o
VPATH = boot:src:kernel:include:arch

all: kernel.iso

kernel.iso: isodir/boot/kernel.bin
	grub2-mkrescue -o kernel.iso isodir/

isodir/boot/kernel.bin: $(OBJECTS) boot.o
	gcc -m32 -T linker.ld $^ -o $@ -nostdlib -ffreestanding

%.o: %.c
	gcc -c $^ -o $@ -ffreestanding -nostdinc -m32 

boot.o: boot.s
	as --32 $^ -o $@

kernel.c:

.PHONY: clean test

test: kernel.iso
	qemu-system-i386 -cdrom kernel.iso

clean:
	rm -f ./*.bin ./*.o ./*.elf ./*.iso

