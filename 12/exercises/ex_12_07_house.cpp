#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 600, "Excersice 12.07 - House"};

    Rectangle wall{Point{100,250}, 400, 250};
    win.attach(wall);

    Polygon roof;
    roof.add(Point{50,250});
    roof.add(Point{550,250});
    roof.add(Point{300,100});
    win.attach(roof);

    Rectangle door{Point{250,300}, 100, 200};
    win.attach(door);

    Rectangle lwin{Point{125,300}, 100, 100};
    win.attach(lwin);

    Rectangle rwin{Point{375,300}, 100, 100};
    win.attach(rwin);

    Polygon tube;
    tube.add(Point{140,100});
    tube.add(Point{160,100});
    tube.add(Point{160,184});
    tube.add(Point{140,196});
    win.attach(tube);

    win.wait_for_button();

}
