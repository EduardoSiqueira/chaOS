# Copyright © 2016
# 
#   Ali de França Husseinat         n°USP: 9292966 
#   Eduardo de Sousa Siqueira       n°USP: 9278299
#   Lucas Silva Marcondes           n°USP: 9293612
#   Ricardo Fernandes França do Vale    n°USP: 9293477 
# 
# This file is part of ChaOS.
# 
# ChaOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# ChaOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# 
# You should have received a copy of the GNU General Public License
# along with ChaOS.  If not, see <http://www.gnu.org/licenses/>.


TARGET = kernel.iso
BIN = isodir/boot/kernel.bin
OBJECTS = boot.o kernel.o stdio.o stdlib.o string.o tty.o registers.o
VPATH = boot:src:kernel:include:arch
CFLAGS = -ffreestanding -nostdinc -m32 -I include/ -g -Wall -std=c99 
LDFLAGS = -m32 -nostdlib -ffreestanding -g -Wall
GRUB = grub2

all: $(TARGET)

$(TARGET): $(BIN)
	$(GRUB)-mkrescue -o $(TARGET) isodir/

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
