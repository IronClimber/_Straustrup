#include "Simple_window.h"
#include "Graph.h"

/* If window size more than monitor resolution, then library draw part of window, its right down corner in right down corner of monitor. Maybe not visible part of window exist out of monitor. with {-x, -y} */
using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 1900, 1400, "Excersice 12.06b - Big window"};

    Rectangle rect{Point{200,200},1000,530};
    rect.set_fill_color(Color::blue);
    win.attach(rect);

    win.wait_for_button();

}
