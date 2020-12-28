CC=g++
CFLAGS=-std=c++11
INCLUDES = -I../../../12/lib -L../../../12/lib `fltk-config --cxxflags`
TARGET = a.out
MAKE = make
LIBS = -lgraph `fltk-config --ldflags --use-images`

all:$(TARGET)

$(TARGET):ex_14_01_smiles.cpp Smile.cpp
	$(CC) $(CFLAGS) $(INCLUDES) Smile.cpp ex_14_01_smiles.cpp $(LIBS)

.PHONY: clean

clean:
	rm a.out 

#\
#	Smile.o
