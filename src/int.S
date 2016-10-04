.text
.extern HandlerInt

common:
	pushq %rax
	pushq %rbx
	pushq %rcx
	pushq %rdx
	pushq %rsi
	pushq %rdi
	pushq %rbp
	pushq %r8
	pushq %r9
	pushq %r10
	pushq %r11
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
    pushq %rsp
	movq %rsp, %rdi
	call HandlerInt
	popq %rsp
    popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %r11
	popq %r10
	popq %r9
	popq %r8
	popq %rbp
	popq %rdi
	popq %rsi
	popq %rdx
	popq %rcx
	popq %rbx
	popq %rax
	addq $16, %rsp
	iretq


.global table
table:
    .quad entry0
    .quad entry1
    .quad entry2
    .quad entry3
    .quad entry4
    .quad entry5
    .quad entry6
    .quad entry7
    .quad entry8
    .quad entry9
    .quad entry10
    .quad entry11
    .quad entry12
    .quad entry13
    .quad entry14
    .quad entry15
    .quad entry16
    .quad entry17
    .quad entry18
    .quad entry19
    .quad entry20
    .quad entry21
    .quad entry22
    .quad entry23
    .quad entry24
    .quad entry25
    .quad entry26
    .quad entry27
    .quad entry28
    .quad entry29
    .quad entry30
    .quad entry31
    .quad entry32

entry0:
    pushq $0
    pushq $0
    jmp common
entry1:
    pushq $0
    pushq $1
    jmp common
entry2:
    pushq $0
    pushq $2
    jmp common
entry3:
    pushq $0
    pushq $3
    jmp common
entry4:
    pushq $0
    pushq $4
    jmp common
entry5:
    pushq $0
    pushq $5
    jmp common
entry6:
    pushq $0
    pushq $6
    jmp common
entry7:
    pushq $0
    pushq $7
    jmp common
entry8:
    pushq $0
    pushq $8
    jmp common
entry9:
    pushq $0
    pushq $9
    jmp common
entry10:
    pushq $10
    jmp common
entry11:
    pushq $11
    jmp common
entry12:
    pushq $12
    jmp common
entry13:
    pushq $13
    jmp common
entry14:
    pushq $14
    jmp common
entry15:
    pushq $0
    pushq $15
    jmp common
entry16:
    pushq $0
    pushq $16
    jmp common
entry17:
    pushq $17
    jmp common
entry18:
    pushq $0
    pushq $18
    jmp common
entry19:
    pushq $0
    pushq $19
    jmp common
entry20:
    pushq $0
    pushq $20
    jmp common
entry21:
    pushq $0
    pushq $21
    jmp common
entry22:
    pushq $0
    pushq $22
    jmp common
entry23:
    pushq $0
    pushq $23
    jmp common
entry24:
    pushq $0
    pushq $24
    jmp common
entry25:
    pushq $0
    pushq $25
    jmp common
entry26:
    pushq $0
    pushq $26
    jmp common
entry27:
    pushq $0
    pushq $27
    jmp common
entry28:
    pushq $0
    pushq $28
    jmp common
entry29:
    pushq $0
    pushq $29
    jmp common
entry30:
    pushq $0
    pushq $30
    jmp common
entry31:
    pushq $0
    pushq $31
    jmp common

entry32:
    pushq $0
    pushq $32
    jmp common   