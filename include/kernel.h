#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define NULL 0;

uint16 *vga_buffer;

enum vga_color {
        BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE
};

void kernel_main(void);
void init_vgabuffer(void);
uint16 vga_entry(unsigned char ch, uint8 background, uint8 foreground);
#endif