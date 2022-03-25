CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

all: testDynarr.o testDeque.o

clean: cleanDynarr cleanDeque

testDynarr.o: testDynamicArrays.c include/DynamicArrays.h
	$(CC) $(CFLAGS) -o $@ $<

testDynarr: testDynarr.o
	valgrind --quiet --leak-check=yes ./$<

cleanDynarr:
	rm testDynarr.o

testDeque.o: testDoubleEndQueue.c include/DoubleEndQueue.h
	$(CC) $(CFLAGS) $< src/DoubleEndQueue.c -o $@

testDeque: testDeque.o
	valgrind --quiet --leak-check=yes ./$<

cleanDeque:
	rm testDeque.o