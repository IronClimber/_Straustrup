#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 500, 350, "Excersice 12.03 - Initials"};

    Lines k;
    k.add(Point{50,100},Point{50,250});
    k.add(Point{50,175},Point{150,100});
    k.add(Point{50,175},Point{150,250});
    k.set_style(Line_style(Line_style::solid, 4));
    k.set_color(Color::green);
    win.attach(k);


    Open_polyline s;
    s.add(Point{300,100});
    s.add(Point{200,100});
    s.add(Point{200,175});
    s.add(Point{300,175});
    s.add(Point{300,250});
    s.add(Point{200,250});
    s.set_style(Line_style(Line_style::solid, 4));
    s.set_color(Color::red);
    win.attach(s);

    Open_polyline v;
    v.add(Point{350,100});
    v.add(Point{400,250});
    v.add(Point{450,100});
    v.set_style(Line_style(Line_style::solid, 4));
    v.set_color(Color::blue);
    win.attach(v);
    

    win.wait_for_button();

}
