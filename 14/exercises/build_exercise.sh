g++ -I ../../12/lib -I ../lib `fltk-config --cxxflags` ../../12/lib/Graph.o ../../12/lib/GUI.o ../../12/lib/Window.o -lfltk -lfltk_images `fltk-config --ldflags` -std=c++11 $1
