static void qemu_gdb_hang(void)
{
#ifdef DEBUG
	static volatile int wait = 1;

	while (wait);
#endif
}

#include <desc.h>
#include <ints.h>
#include "ioport.h"
#include "print.h"
#include "idt.h"

void init()
{
	out8(0x3FB, 0);
	out8(0x3F9, 0);
	out8(0x3FB, 128);
	out8(0x3F8, 6);
	out8(0x3F9, 0);
	out8(0x3FB, 3);
}
void init_PIC()
{
	out8(0x43, 0x34);
	out8(0x40, 0xFF);
	out8(0x40, 0xFF);
}
void init_master_slave()
{
	disable_ints();
	out8(0x20, 0x11);
	out8(0x21, 32);
	out8(0x21, 4);
	out8(0x21, 1);

	out8(0xA0, 0x11);
	out8(0xA1, 40);
	out8(0xA1, 2);
	out8(0xA1, 1);

	out8(0x21, 0xFE);
	out8(0xA1, 0xFF);
	enable_ints();
}
void main(void)
{
	qemu_gdb_hang();
	init();
	SetIDTR();
	init_master_slave();
	init_PIC();
	while (1);
}
