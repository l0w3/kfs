# Set up the cross compiler and options
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker/linker.ld -ffreestanding -O2 -nostdlib
OBJS = boot.o kernel.o


# Target to build the kernel object
boot.o: boot/boot.asm
	nasm -felf32 boot/boot.asm -o boot.o
# Target to build the kernel object
kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c kernel/kernel.c -o kernel.o

# Target to build the final OS binary
myos.bin: kernel.o boot.o
	$(CC) $(LDFLAGS) -o myos.bin $(OBJS) -lgcc

# Move the binary to the isodir
move_bin: myos.bin
	mkdir -p isodir/boot
	cp myos.bin isodir/boot/
	mkdir isodir/boot/grub
	cp grub.cfg isodir/boot/grub

# Build the ISO with GRUB
myos.iso: move_bin
	grub-mkrescue -o myos.iso isodir

# Clean up object files and ISO
clean:
	rm -rf $(OBJS) myos.bin myos.iso isodir

# Default target to build everything
all: myos.iso

.PHONY: all clean
