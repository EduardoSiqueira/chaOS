all:    
	as --32 boot/boot.s -o boot.o
	gcc -c kernel/kernel.c -o kernel.o -ffreestanding -nostdinc -m32 
	gcc -m32 -T linker.ld *.o -o kernel.bin -nostdlib -ffreestanding
	grub2-mkrescue -o kernel.iso isodir/
	qemu-system-i386 -cdrom kernel.iso

.PHONY: clean

clean:
	rm -f ./*.bin ./*.o ./*.elf

