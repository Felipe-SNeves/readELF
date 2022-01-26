segment .data
	LF		equ 0x0A
	NULL		equ 0x00
	SYS_EXIT	equ 0x01
	RET_EXIT	equ 0x00
	STD_IN		equ 0x00
	STD_OUT		equ 0x01
	SYS_READ	equ 0x03
	SYS_WRITE	equ 0x04
	SYS_CALL	equ 0x80

section .data
	numero_1	dd 22
	numero_2	dd 34
	mensagem_1	db "O numero 1 eh maior que o numero 2", LF, NULL
	tamanho_mensagem_1 equ $-mensagem_1
	mensagem_2 	db "O numero 1 eh menor que o numero 2", LF, NULL
	tamanho_mensagem_2 equ $-mensagem_2


section .text
	global _start

_start:
	MOV EAX, DWORD [numero_1]
	MOV EBX, DWORD [numero_2]

	CMP EAX, EBX
	JGE maior

	MOV ECX, mensagem_2
	MOV EDX, tamanho_mensagem_2
	JMP final

maior:
	MOV ECX, mensagem_1
	MOV EDX, tamanho_mensagem_1

final:
	MOV EAX, SYS_WRITE
	MOV EBX, STD_OUT
	INT SYS_CALL

	MOV EAX, SYS_EXIT
	MOV EBX, RET_EXIT
	INT SYS_CALL
	
