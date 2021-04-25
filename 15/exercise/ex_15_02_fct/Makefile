CC = g++
CFLAGS = -std=c++11
INCLUDES = -I../../../12/lib -L../../../12/lib `fltk-config --cxxflags`
LIBS = -lgraph `fltk-config --ldflags --use-images`
SOURCES = main.cpp
OBJECTS = Function.o
TARGET = a.out

all: $(TARGET)

$(TARGET): $(SOURCES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(OBJECTS) $(LIBS)

$(OBJECTS): Function.cpp Function.h
	$(CC) $(CFLAGS) -c $(INCLUDES) Function.cpp

.PHONY: clean

clean:
	rm $(OBJECTS)
	rm $(TARGET)
