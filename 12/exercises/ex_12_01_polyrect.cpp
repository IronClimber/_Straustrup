#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 400, 400, "Excersice 12.01 - PolyRect"};

    Polygon poly;
    poly.add(Point{100,100});
    poly.add(Point{100,200});
    poly.add(Point{200,200});
    poly.add(Point{200,100});
    poly.set_color(Color::red);
    win.attach(poly);

    Rectangle rect{Point{200,200},50,50};
    rect.set_color(Color::blue);
    win.attach(rect);
    win.wait_for_button();

}
