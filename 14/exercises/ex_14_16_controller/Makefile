CC=g++
CFLAGS=-std=c++11
INCLUDES = -I../ex_14_14_Binary_tree_text -I../../../13/lib -I../lib/ -I../../../12/lib -L../../../12/lib -L../ex_14_14_Binary_tree_text  `fltk-config --cxxflags`
TARGET = a.out
MAKE = make
SOURCES = main.cpp
LIBS = -lgraph `fltk-config --ldflags --use-images`
OBJECTS = Controller.o ../ex_14_14_Binary_tree_text/Binary_tree.o ../../../13/lib/lib_13.o

all:$(TARGET)

$(TARGET):$(SOURCES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(OBJECTS) $(LIBS)

Controller.o: Controller.h Controller.cpp
	$(CC) $(CFLAGS) -c $(INCLUDES) Controller.cpp

../ex_14_14_Binary_tree_text/Binary_tree.o:
	$(MAKE) -C ../ex_14_14_Binary_tree_text Binary_tree.o

../../../13/lib/lib_13.o:
	$(MAKE) -C ../../../13/lib lib_13.o

.PHONY: clean

clean:
	rm a.out
	rm Controller.o
	rm ../../../13/lib/lib_13.o
	rm ../ex_14_14_Binary_tree_text/Binary_tree.o
