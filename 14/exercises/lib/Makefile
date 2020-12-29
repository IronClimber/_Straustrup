CC=g++
CFLAGS=-std=c++11 -c
INCLUDES=-I../../../12/lib 

all: lib_14.o

lib_14.o: lib_14.h lib_14.cpp
	$(CC) $(CFLAGS) $(INCLUDES) lib_14.cpp

.PHONY: clean clean_lib_14

clean_lib_14:
	rm -rf lib_14.o

clean:
	rm -rf lib_14.o
