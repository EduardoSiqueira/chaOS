#all:    
#	as --32 boot.s -o boot.o
#	ld -m elf_i386 -nostdlib -N -Ttext 7C00 boot.o -o boot.elf
#	objcopy -O binary boot.elf boot.bin
#	qemu-system-i386 boot.bin -boot a
#
#clean:
#	rm ./*.bin ./*.o ./*.elf
