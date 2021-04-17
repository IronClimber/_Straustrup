CC = g++
CFLAGS = -std=c++11

a.out: main.cpp Person.o
	$(CC) $(CFLAGS) main.cpp Person.o -o a.out

Person.o: Person.h Person.cpp
	$(CC) $(CFLAGS) -c Person.cpp

.PHONY: clean

clean:
	rm a.out
	rm Person.o





