#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.10 - Regular_polygon"};

    Regular_polygon hex{Point{100,100}, 6, 50};
    win.attach(hex);

    Regular_polygon penta{Point{200,200}, 5, 50};
    win.attach(penta);

    Regular_polygon tri{Point{100,200}, 3, 50};
    win.attach(tri);

    Regular_polygon quad{Point{200,100}, 4, 50};
    win.attach(quad);

    win.wait_for_button();

}
