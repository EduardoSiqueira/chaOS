#!/bin/bash

if grub2-file --is-x86-multiboot ./kernel.bin; then
    echo Multiboot confirmed
else
    echo the file is not multiboot
fi
