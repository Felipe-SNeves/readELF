section .text
	global _start

_start:
	MOV EAX, 0x03
	MOV EBX, 0x00
	MOV ECX, name
	MOV EDX, 0x0A
	INT 0x80

	MOV EAX, 0x04
	MOV EBX, 0x01
	MOV ECX, name
	MOV EDX, 0x0A
	INT 0x80

	MOV EAX, 0x01
	MOV EBX, 0X00
	INT 0x80

section .bss
	name resb 0x0A 
