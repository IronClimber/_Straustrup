#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {


    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.12 - Marked circle"};

    int r{100};

    int center_x{int(win.x_max()/2)};
    int center_y{int(win.y_max()/2)};

    Circle c{Point{center_x, center_y}, r};
    win.attach(c);

    double a{0};

    Mark m{Point{center_x + r, center_y}, 'x'};
    win.attach(m);

    Point last_point{m.point(0)};

    win.wait_for_button();

    for (int i = 0; i < 30; ++i) {
        a += M_PI/20;
        m.move(center_x+int(r*cos(a))-last_point.x, center_y-int(r*sin(a))-last_point.y);

        last_point = m.point(0);
        win.wait_for_button();
    }

    

}
