#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    
    Point t1{100,100};
    Simple_window win{t1,600,400,"Canvas"};

    win.wait_for_button();

    Axis xa{Axis::x, Point(20,300), 280, 10, "x axis"};
    win.attach(xa);
    win.set_label("Canvas #2");

    win.wait_for_button();

    Axis ya{Axis::y, Point{20,300}, 280, 10, "y_axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    win.wait_for_button();

    Function sine{sin,0,100,Point(20,150),1000,50,50};
    win.attach(sine);
    win.set_label("Canvas #4");

    win.wait_for_button();
}
