PROJECT_NAME=ELFparser
CC=gcc

all: main.c header
	$(CC) $< elfparser.c -o $(PROJECT_NAME)
	rm elfparser.o elfparser.h.gch

header: elfparser.c elfparser.h
	$(CC) -c $^
