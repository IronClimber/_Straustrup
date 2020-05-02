#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "13.14 Marked Polyline"};

    Marked_polyline mpl {"x"};
    mpl.add(Point{100,100});
    mpl.add(Point{150,200});
    mpl.add(Point{250,250});
    mpl.add(Point{300,200});

    win.attach(mpl);

    win.wait_for_button();
}
