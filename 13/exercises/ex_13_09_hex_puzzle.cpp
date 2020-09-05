#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.09 - Hexagon puzzle"};

    Vector_ref<Regular_hexagon> puzzle;
    Point start_point{50,50};
    int radius{40};
    int row{3};
    int column{5};
    for (int i = 0; i < row; ++i) {
        int shift_x{0};
        if (i%2!=0) {shift_x = 1.5*radius;}
        for (int j = 0; j < column; ++j) {
            puzzle.push_back(new Regular_hexagon{Point{start_point.x+j*3*radius+shift_x,start_point.y+int(i*0.866*radius)}, radius});
        }
    }

    for (int i = 0; i < puzzle.size(); ++i) {
        win.attach(puzzle[i]);
    }

    win.wait_for_button();

}
