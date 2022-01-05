#ifndef _ELFPARSER_H
	#define _ELFPARSER_H
#endif

#if !(defined (_STDIO_H) && defined (_STRING_H))
	#include <stdio.h>
	#include <string.h>
#endif

#if !(defined (_STDLIB_h) && defined (_FCNTL_H) && defined (_ELF_H) && defined (_UNISTD_H))
	#include <fcntl.h>
	#include <stdlib.h>
	#include <elf.h>
	#include <unistd.h>
#endif

int ELFparse(int);
