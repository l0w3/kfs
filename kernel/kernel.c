#include "../include/kernel.h"

/*
   VGA Buffer: Consists of 16 bytes (ax):
   Lower 8 bits: Character to be used (al)
   Upper 8 bits: Color (ah)
   Upper 4 bits: Background
   Lower 4 bits: Foreground
 */

uint16 vga_entry
(unsigned char ch, uint8 background, uint8 foreground) {
	uint16 ax = 0;
	uint8 ah, al = 0;
	// set background and foreground colors
	ah = background;
	ah <<= 4;
	ah |= foreground;
	ax = ah;
	//set character
	al = ch;
	ax <<= 8;
	ax |= al;

	return (ax);
}

void init_vgabuffer
(void) {
	vga_buffer = (uint16*)VGA_ADDRESS;
}

void kernel_main
(void) {
	init_vgabuffer();
	vga_buffer[0] = vga_entry('H', BLACK, WHITE);
	vga_buffer[1] = vga_entry('e', BLACK, WHITE);
	vga_buffer[2] = vga_entry('l', BLACK, WHITE);
	vga_buffer[3] = vga_entry('l', BLACK, WHITE);
	vga_buffer[4] = vga_entry('o', BLACK, WHITE);
	vga_buffer[5] = vga_entry(' ', BLACK, WHITE);
	vga_buffer[6] = vga_entry('W', BLACK, WHITE);
	vga_buffer[7] = vga_entry('o', BLACK, WHITE);
	vga_buffer[8] = vga_entry('r', BLACK, WHITE);
	vga_buffer[9] = vga_entry('l', BLACK, WHITE);
	vga_buffer[10] = vga_entry('d', BLACK, WHITE);
	vga_buffer[11] = vga_entry('!', BLACK, WHITE);

}
