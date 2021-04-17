CC = g++
CFLAGS = -std=c++11
INCLUDES = -I../../../12/lib -L../../../12/lib `fltk-config --cxxflags`
LIBS = -lgraph `fltk-config --ldflags --use-images`

a.out: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) main.cpp $(LIBS) -o a.out

.PHONY: clean

clean:
	rm a.out





