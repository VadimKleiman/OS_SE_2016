#ifndef __IDT__
#define __IDT__

#include <stdint.h>

struct IDTDescriptor{
	uint16_t offset_1;
	uint16_t selector;
	uint8_t ist;
	uint8_t type_attr;
	uint16_t offset_2;
	uint32_t offset_3;
	uint32_t zero;
} __attribute__((packed));

void SetIDTR();

#endif