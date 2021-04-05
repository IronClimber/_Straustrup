CC=g++
CFLAGS=-std=c++11
TARGET = a.out
MAKE = make
SOURCES = main.cpp
OBJECTS = Iterator.o

all:$(TARGET)

$(TARGET):$(SOURCES) $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) $(OBJECTS)

$(OBJECTS): Iterator.h Iterator.cpp
	$(CC) $(CFLAGS) -c Iterator.cpp

.PHONY: clean

clean:
	rm a.out
	rm Iterator.o
