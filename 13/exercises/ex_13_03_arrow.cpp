#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>


using namespace Graph_lib;


int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.03 - Arrow"};

    Vector_ref<Arrow> arrow;
    double alpha{0.0};
    Point p0{300,200};
    int length{200};
    
    for (int i = 0; i < 12; ++i) {
        alpha = M_PI*i/6;
        Point p{p0.x+int(length*cos(alpha)),p0.y-int(length*sin(alpha))};    
        arrow.push_back(new Arrow{p0, p});
        win.attach(arrow[arrow.size()-1]);
    }

    win.wait_for_button();

}
