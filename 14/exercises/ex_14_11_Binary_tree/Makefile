CC=g++
CFLAGS=-std=c++11
INCLUDES = -I../../../12/lib -I../../../13/lib -I../lib -L../../../12/lib `fltk-config --cxxflags`
TARGET = a.out
MAKE = make
LIBS = -lgraph `fltk-config --ldflags --use-images`
SOURCES = main.cpp
OBJECTS = Binary_tree.o ../../../13/lib/lib_13.o ../lib/lib_14.o

all:$(TARGET)

$(TARGET):$(SOURCES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(OBJECTS) $(LIBS)

Binary_tree.o: Binary_tree.h Binary_tree.cpp
	$(CC) $(CFLAGS) -c $(INCLUDES) Binary_tree.cpp

../lib/lib_14.o:
	$(MAKE) -C ../lib lib_14.o

../../../13/lib/lib_13.o:
	$(MAKE) -C ../../../13/lib lib_13.o

.PHONY: clean

clean:
	rm a.out
	rm Binary_tree.o
