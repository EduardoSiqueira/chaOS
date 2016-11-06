
OBJECTS = kernel.o

all: kernel.iso

kernel.iso: isodir/boot/kernel.bin
	grub2-mkrescue -o kernel.iso isodir/

isodir/boot/kernel.bin: $(OBJECTS) boot.o
	gcc -m32 -T linker.ld $^ -o $@ -nostdlib -ffreestanding

kernel.o: kernel/kernel.c
	gcc -c $^ -o kernel.o -ffreestanding -nostdinc -m32 

boot.o: boot/boot.s
	as --32 $^ -o $@


.PHONY: clean test

test: kernel.iso
	qemu-system-i386 -cdrom kernel.iso

clean:
	rm -f ./*.bin ./*.o ./*.elf ./*.iso

