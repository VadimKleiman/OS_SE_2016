#include "idt.h"
#include "memory.h"
#include "desc.h"
#include "print.h"

#define IDT_SIZE 256
#define INT_SIZE 33

extern uint64_t table[];

struct desc_table_ptr IDTR;
struct IDTDescriptor IDT[IDT_SIZE];

static void SetIDT(const uint8_t index, const uint64_t offset)
{
	IDT[index].offset_1 = (offset & 0xFFFF);
	IDT[index].offset_2 = (offset >> 16) & 0xFFFF;
	IDT[index].offset_3 = (offset >> 32) & 0xFFFFFFFF;
	IDT[index].selector = (uint16_t)KERNEL_CS;
	IDT[index].type_attr = (uint8_t)0x8E;
	IDT[index].ist = 0;
	IDT[index].zero = 0;
}

void SetIDTR()
{
	for(unsigned int i = 0; i < INT_SIZE; ++i)
		SetIDT(i, (uint64_t)table[i]);
	IDTR.size = sizeof(struct IDTDescriptor) * IDT_SIZE - 0x1;
	IDTR.addr = (uint64_t)IDT;
	write_idtr(&IDTR);
}