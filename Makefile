
# This is so far a win32 platform specific makefile.
CC=gcc
CFLAGS=-I. -I arch/win32
OBJ = console.o datastructures.o debugging.o encryption.o filemanagement.o keyboard.o libstring.o logging.o memory.o satefychecking.o testing.o timing.o
DEPS = console.h datastructures.h debugging.h encryption.h filemanagement.h keyboard.h libstring.h logging.h memory.h satefychecking.h testing.h timing.h

# .c files depend on .h files (these changes should recompile .c files)
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	gcc -o $@ $^ $(CFLAGS)