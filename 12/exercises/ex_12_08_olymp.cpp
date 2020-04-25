#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Excersice 12.08 - Olimpic"};

    Circle blue{Point{150,150}, 50};
    blue.set_color(Color::blue);
    blue.set_style(Line_style(Line_style::solid, 5));
    win.attach(blue);

    Circle black{Point{270,150}, 50};
    black.set_color(Color::black);
    black.set_style(Line_style(Line_style::solid, 5));
    win.attach(black);

    Circle red{Point{390,150}, 50};
    red.set_color(Color::red);
    red.set_style(Line_style(Line_style::solid, 5));
    win.attach(red);

    Circle yellow{Point{210,210}, 50};
    yellow.set_color(Color::yellow);
    yellow.set_style(Line_style(Line_style::solid, 5));
    win.attach(yellow);

    Circle green{Point{330,210}, 50};
    green.set_color(Color::green);
    green.set_style(Line_style(Line_style::solid, 5));
    win.attach(green);

    win.wait_for_button();

}
