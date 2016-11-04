all:    
	as --32 boot/boot.s -o boot.o
	gcc -m32 -c kernel/kernel.c -o kernel.o
	ld -m elf_i386 -T linker.ld *.o -o kernel.elf
	qemu-system-i386 -kernel kernel.elf
clean:
	rm -f ./*.bin ./*.o ./*.elf

