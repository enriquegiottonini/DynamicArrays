CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

testDynarr.o: testDynamicArrays.c include/DynamicArrays.h
	$(CC) $(CFLAGS) -o $@ $<

testDynarr: testDynarr.o
	valgrind --quiet --leak-check=yes ./$<

cleanDynarr:
	rm testDynarr.o

build/Deque.o: src/DoubleEndQueue.c include/DynamicArrays.h include/DoubleEndQueue.h
	$(CC) $(CFLAGS) -c $< -o $@

testDeque.o: testDoubleEndQueue.c include/DoubleEndQueue.h
	$(CC) $(CFLAGS) $< src/DoubleEndQueue.c -o $@

testDeque: testDeque.o
	valgrind --quiet --leak-check=yes ./$<

clean2:
	rm testDeque.o