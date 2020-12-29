CC=g++
CFLAGS=-std=c++11
INCLUDES = -I../../../12/lib -I../lib -L../../../12/lib `fltk-config --cxxflags`
TARGET = a.out
MAKE = make
LIBS = -lgraph `fltk-config --ldflags --use-images`
SOURCES = main.cpp
OBJECTS = ../lib/lib_14.o

all:$(TARGET)

$(TARGET):$(SOURCES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(OBJECTS) $(LIBS)

$(OBJECTS):
	$(MAKE) -C ../lib lib_14.o

.PHONY: clean

clean:
	rm a.out
	$(MAKE) -C ../lib clean_lib_14
