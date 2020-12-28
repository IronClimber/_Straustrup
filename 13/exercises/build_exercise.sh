g++ -std=c++11 -I ../../12/lib -I ../lib -L ../../12/lib  ../lib/lib_13.o ~/Desktop/_Straustrup/13/exercises/$1 -lfltk -lfltk_images -lgraph `fltk-config --cxxflags --ldflags --use-images` 
