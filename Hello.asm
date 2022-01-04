section .text
	global _start

_start:

; Imprindo mensagem
	MOV EAX, SYS_WRITE
	MOV EBX, STD_OUT
	MOV ECX, mensagem
	MOV EDX, tamanho
	INT SYS_CALL

; retorno ao SO
	MOV EAX, SYS_EXIT
	MOV EBX, RET_EXIT
	INT SYS_CALL

section .data
	mensagem db "Hello nasm!", 0x0A
	tamanho equ $-mensagem

segment .data
	LF		equ 0x0A
	NULL		equ 0x0D
	SYS_EXIT	equ 0x01
	RET_EXIT	equ 0x00
	STD_IN		equ 0x00
	STD_OUT		equ 0x01
	SYS_READ	equ 0x03
	SYS_WRITE	equ 0x04
	SYS_CALL	equ 0x80
