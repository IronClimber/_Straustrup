CC = g++
CFLAGS = -std=c++17
INCLUDES = -I../../12/lib -L../../12/lib `fltk-config --cxxflags`
LIBS = -lgraph `fltk-config --ldflags --use-images`

exam_15_02: exam_15_02.cpp
	$(CC) $(CFLAGS) $(INCLUDES) exam_15_02.cpp $(LIBS) -o exam_15_02

exam_15_05: exam_15_05.cpp
	$(CC) $(CFLAGS) $(INCLUDES) exam_15_05.cpp $(LIBS) -o exam_15_05

.PHONY: clean

clean:
	rm exam_15_02
	rm exam_15_05




