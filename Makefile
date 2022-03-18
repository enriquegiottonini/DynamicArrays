CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

build/main.o: src/main.c include/DynamicArrays.h
	$(CC) $(CFLAGS) -o $@ $< -Iinclude
run: build/main.o
	./$<

test: build/main.o
	valgrind --quiet --leak-check=yes ./$<

clean:
	rm build/main.o
