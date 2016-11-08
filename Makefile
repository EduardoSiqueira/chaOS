
TARGET = kernel.iso
BIN = isodir/boot/kernel.bin
OBJECTS = boot.o kernel.o stdio.o stdlib.o string.o tty.o
VPATH = boot:src:kernel:include:arch
CFLAGS = -ffreestanding -nostdinc -m32 -I include/ -g -Wall -std=c99 
LDFLAGS = -m32 -nostdlib -ffreestanding -g -Wall

all: $(TARGET)

$(TARGET): $(BIN)
	grub2-mkrescue -o $(TARGET) isodir/

$(BIN): $(OBJECTS)
	gcc -T linker.ld $^ -o $@ $(LDFLAGS)

%.o: %.c
	gcc -c $^ -o $@ $(CFLAGS)

boot.o: boot.s
	as --32 $^ -o $@

.PHONY: clean test

run: $(TARGET)
	qemu-system-i386 -cdrom $<

test: $(BIN)
	qemu-system-i386 -kernel $<

clean:
	rm -f ./*.bin ./*.o ./*.elf ./*.iso
	rm -f ./isodir/boot/*.bin
