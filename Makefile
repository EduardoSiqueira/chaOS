
TARGET = kernel.iso
BIN = isodir/boot/kernel.bin
OBJECTS = boot.o kernel.o
VPATH = boot:src:kernel:include:arch
CFLAGS = -ffreestanding -nostdinc -m32 -I include/
LDFLAGS = -m32 -nostdlib -ffreestanding 

all: $(TARGET)

$(TARGET): $(BIN)
	grub2-mkrescue -o $(TARGET) isodir/

$(BIN): $(OBJECTS)
	gcc -T linker.ld $^ -o $@ $(LDFLAGS)

%.o: %.c
	gcc -c $^ -o $@ $(CFLAGS)

boot.o: boot.s
	as --32 $^ -o $@

kernel.c:

.PHONY: clean test

test: $(TARGET)
	qemu-system-i386 -cdrom $(TARGET)

clean:
	rm -f ./*.bin ./*.o ./*.elf ./*.iso
	rm -f ./isodir/boot/*.bin
