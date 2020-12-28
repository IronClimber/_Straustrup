CC=g++
CFLAGS=-std=c++11 -c
OBJECTS = Graph.o GUI.o Window.o
SOURCES = Graph.cpp GUI.cpp Window.cpp

lib: $(OBJECTS)
	ar rvs libgraph.a Graph.o GUI.o Window.o

all: fltk.h Graph.cpp Graph.h GUI.cpp GUI.h Point.h Simple_window.h std_lib_facilities.h Window.cpp Window.h
	$(CC) $(CFLAGS) $(SOURCES)

Graph.o: Graph.cpp Graph.h Point.h std_lib_facilities.h fltk.h
	$(CC) $(CFLAGS) Graph.cpp

GUI.o: GUI.cpp GUI.h Graph.h Window.h std_lib_facilities.h
	$(CC) $(CFLAGS) GUI.cpp

Window.o: Window.cpp Window.h Graph.h GUI.h Point.h std_lib_facilities.h fltk.h
	$(CC) $(CFLAGS) Window.cpp

clean:
	rm -rf $(OBJECTS) \
	libgraph.a
	
