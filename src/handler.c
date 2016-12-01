#include "print.h"
#include <stdint.h>
#include "ioport.h"
struct frame{
	uint64_t rsp;
	uint64_t r15;
	uint64_t r14;
	uint64_t r13;
	uint64_t r12;
	uint64_t r11;
	uint64_t r10;
	uint64_t r9;
	uint64_t r8;
	uint64_t rbp;
	uint64_t rdi;
	uint64_t rsi;
	uint64_t rdx;
	uint64_t rcx;
	uint64_t rbx;
	uint64_t rax;
	uint64_t intno;
	uint64_t error;
	uint64_t old_rip;
	uint64_t old_cs;
	uint64_t old_flags;
	uint64_t old_rsp;
	uint64_t old_ss;
} __attribute__((packed));

void HandlerInt(struct frame* param)
{
	printf("\n\n%s\n", "------------------------------------------");
	switch (param->intno)
	{
		case 0: printf("%s %d: %s\n", "Interrupt code ", 0, "Divide by 0"); break;
		case 1: printf("%s %d: %s\n", "Interrupt code ", 1, "Reserved"); break;
		case 2: printf("%s %d: %s\n", "Interrupt code ", 2, "NMI Interrupt"); break;
		case 3: printf("%s %d: %s\n", "Interrupt code ", 3, "Breakpoint (INT3)"); break;
		case 4: printf("%s %d: %s\n", "Interrupt code ", 4, "Overflow (INTO)"); break;
		case 5: printf("%s %d: %s\n", "Interrupt code ", 5, "Bounds range exceeded (BOUND)"); break;
		case 6: printf("%s %d: %s\n", "Interrupt code ", 6, "Invalid opcode (UD2)"); break;
		case 7: printf("%s %d: %s\n", "Interrupt code ", 7, "Device not available (WAIT/FWAIT)"); break;
		case 8: printf("%s %d: %s\n", "Interrupt code ", 8, "Double fault"); break;
		case 9: printf("%s %d: %s\n", "Interrupt code ", 9, "Coprocessor segment overrun"); break;
		case 10: printf("%s %d: %s\n", "Interrupt code ", 10, "Invalid TSS"); break;
		case 11: printf("%s %d: %s\n", "Interrupt code ", 11, "Segment not present"); break;
		case 12: printf("%s %d: %s\n", "Interrupt code ", 12, "Stack-segment fault"); break;
		case 13: printf("%s %d: %s\n", "Interrupt code ", 13, "General protection fault"); break;
		case 14: printf("%s %d: %s\n", "Interrupt code ", 14, "Page fault"); break;
		case 15: printf("%s %d: %s\n", "Interrupt code ", 15, "Reserved"); break;
		case 16: printf("%s %d: %s\n", "Interrupt code ", 16, "x87 FPU error"); break;
		case 17: printf("%s %d: %s\n", "Interrupt code ", 17, "Alignment check"); break;
		case 18: printf("%s %d: %s\n", "Interrupt code ", 18, "Machine check"); break;
		case 19: printf("%s %d: %s\n", "Interrupt code ", 19, "SIMD Floating-Point Exception"); break;
		case 20: printf("%s %d: %s\n", "Interrupt code ", 20, "Reserved"); break;
		case 21: printf("%s %d: %s\n", "Interrupt code ", 21, "Reserved"); break;
		case 22: printf("%s %d: %s\n", "Interrupt code ", 22, "Reserved"); break;
		case 23: printf("%s %d: %s\n", "Interrupt code ", 23, "Reserved"); break;
		case 24: printf("%s %d: %s\n", "Interrupt code ", 24, "Reserved"); break;
		case 25: printf("%s %d: %s\n", "Interrupt code ", 25, "Reserved"); break;
		case 26: printf("%s %d: %s\n", "Interrupt code ", 26, "Reserved"); break;
		case 27: printf("%s %d: %s\n", "Interrupt code ", 27, "Reserved"); break;
		case 28: printf("%s %d: %s\n", "Interrupt code ", 28, "Reserved"); break;
		case 29: printf("%s %d: %s\n", "Interrupt code ", 29, "Reserved"); break;
		case 30: printf("%s %d: %s\n", "Interrupt code ", 30, "Reserved"); break;
		case 31: printf("%s %d: %s\n", "Interrupt code ", 31, "Reserved"); break;
		case 32: printf("%s\n", "Hello!"); out8(0x20,32); return; break;
	}
	printf("%s\n", "------------------------------------------");
	printf("|%s\t|\t%s            |\n", "Register", "Value");
	printf("%s\n", "------------------------------------------");
	printf("|Register r15\t|\t%llx|\n", param->r15);
	printf("|Register r14\t|\t%llx|\n", param->r14);
	printf("|Register r13\t|\t%llx|\n", param->r13);
	printf("|Register r12\t|\t%llx|\n", param->r12);
	printf("|Register r11\t|\t%llx|\n", param->r11);
	printf("|Register r10\t|\t%llx|\n", param->r10);
	printf("|Register r9\t|\t%llx|\n", param->r9);
	printf("|Register r8\t|\t%llx|\n", param->r8);
	printf("|Register rbp\t|\t%llx|\n", param->rbp);
	printf("|Register rdi\t|\t%llx|\n", param->rdi);
	printf("|Register rsi\t|\t%llx|\n", param->rsi);
	printf("|Register rdx\t|\t%llx|\n", param->rdx);
	printf("|Register rcx\t|\t%llx|\n", param->rcx);
	printf("|Register rbx\t|\t%llx|\n", param->rbx);
	printf("|Register rax\t|\t%llx|\n", param->rax);
	printf("|Register rsp\t|\t%llx|\n", param->rsp);
	printf("%s\n", "------------------------------------------");
	printf("|Old RIP\t|\t%llx|\n", param->old_rip);
	printf("|Old CS \t|\t%llx|\n", param->old_cs);
	printf("|Old Flags\t|\t%llx|\n", param->old_flags);
	printf("|Old RSP \t|\t%llx|\n", param->old_rsp);
	printf("|Old SS \t|\t%llx|\n", param->old_ss);
	printf("%s\n", "------------------------------------------");
	printf("|Error code\t|\t%llx|\n", param->error);
	printf("%s\n", "------------------------------------------");
}