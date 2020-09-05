#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.08 - Regular_hexagon"};

    Regular_hexagon hex{Point{100,100}, 50};

    win.attach(hex);
    win.wait_for_button();

}
