#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {


    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.11 - Ellipse"};

    int el_x{150};
    int el_y{100};

    int center_x{int(win.x_max()/2)};
    int center_y{int(win.y_max()/2)};

    Ellipse ellipse{Point{center_x, center_y}, el_x, el_y};
    win.attach(ellipse);

    int dev = 50;

    Axis xa{Axis::x, 
            Point{center_x - el_x - dev, center_y},
            2*(el_x+dev),
            0,
            "X"};
    win.attach(xa);

    Axis ya{Axis::y, 
            Point{center_x, center_y + el_y + dev},
            2*(el_y+dev),
            0,
            "Y"};
    win.attach(ya);

    double a{-M_PI/6};

    Marked_polyline m{"x"};
    m.add(Point{center_x+el_x, center_y});
    m.add(Point{center_x+int(el_x*cos(a)),
                center_y-int(el_y*sin(a))});
    m.add(Point{center_x, center_y+el_y});
    win.attach(m);

    win.wait_for_button();

}
