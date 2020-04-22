#include "Simple_window.h"
#include "Graph.h"

/* If figures size more than windows size, then library draw part of figure */
using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 400, 400, "Excersice 12.06a - Big figure"};

    Rectangle rect{Point{200,200},1000,530};
    rect.set_fill_color(Color::blue);
    win.attach(rect);

    win.wait_for_button();

}
