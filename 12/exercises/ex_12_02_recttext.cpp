#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 400, 400, "Excersice 12.02 - RectText"};

    Rectangle rect{Point{200,200},100,30};
    //rect.set_color(Color::blue);
    win.attach(rect);

    Text t{Point{225,220}, "Howdy!"};
    win.attach(t);

    win.wait_for_button();

}
