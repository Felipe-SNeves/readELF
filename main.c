#include "elfparser.h"

int main (int argc, char ** argv) {

	if (argc < 2) {
		printf ("Usage: %s object_file\n", *argv);
		return EXIT_FAILURE;
	}

	int fileDescriptor;
	if ((fileDescriptor = (open (*(++argv), O_RDONLY))) < 0) {
		printf ("Could not open the %s file! Is the correct file?\n", *argv);
		return EXIT_FAILURE;	
	}

	printf ("Parsing the ELF header of %s!\n", *argv);
	if (ELFparse (fileDescriptor) < 0) {
		puts ("Format file doesn't recognized! Is it ELF?");
		return EXIT_FAILURE;
	}

	close (fileDescriptor);
	return 0;
}
