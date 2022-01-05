#include "elfparser.h"

Elf64_Ehdr * parse64bitsHeader (int fd, char * tmp_buffer) {
	char * current_position = tmp_buffer;
	read (fd, tmp_buffer, 0x40);
	Elf64_Ehdr * ElfHeader64 = malloc (0x40);
	memcpy (ElfHeader64->e_ident, current_position, 0x04);
	current_position += 0x04;
	memcpy (ElfHeader64->e_ident + 4, current_position, 0x01);
	current_position++;
	memcpy (ElfHeader64->e_ident + 5, current_position, 0x01);
	current_position++;
	memcpy (ElfHeader64->e_ident + 6, current_position, 0x01);
	current_position++;
	memcpy (ElfHeader64->e_ident + 7, current_position, 0x01);
	current_position++;
	memcpy (ElfHeader64->e_ident + 8, current_position, 0x01);
	current_position++;
	memcpy (ElfHeader64->e_ident + 9, current_position, 0x07);
	current_position += 0x07;
	memcpy (&ElfHeader64->e_type, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_machine, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_version, current_position, 0x04);
	current_position += 0x04;
	memcpy (&ElfHeader64->e_entry, current_position, 0x08);
	current_position += 0x08;
	memcpy (&ElfHeader64->e_phoff, current_position, 0x08);
	current_position += 0x08;
	memcpy (&ElfHeader64->e_shoff, current_position, 0x08);
	current_position += 0x08;
	memcpy (&ElfHeader64->e_flags, current_position, 0x04);
	current_position += 0x04;
	memcpy (&ElfHeader64->e_ehsize, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_phentsize, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_phnum, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_shentsize, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_shnum, current_position, 0x02);
	current_position += 0x02;
	memcpy (&ElfHeader64->e_shstrndx, current_position, 0x02);
	return ElfHeader64;
}

int ELFparse (int fd) {
	
	char * tmp_buffer = malloc (0x40);
	read (fd, tmp_buffer, 0x04);

	if (strcmp (tmp_buffer+1, "ELF"))
		return -1;

	read (fd, tmp_buffer, 0x01);
	lseek (fd, 0x00, SEEK_SET);

	if (*tmp_buffer == 0x01) {
		Elf32_Ehdr * header;
	}
	else {
		Elf64_Ehdr * header = parse64bitsHeader (fd, tmp_buffer);
		free (header);
	}

	free (tmp_buffer);
	return 0;
}
