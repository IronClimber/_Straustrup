#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.14 - Right_triangle"};

    Right_triangle tri1{Point{150,250}, 300, 100};
    tri1.set_fill_color(Color::red);
    win.attach(tri1);

    Right_triangle tri2{Point{450,150}, -300, -100};
    tri2.set_fill_color(Color::red);
    win.attach(tri2);

    Right_triangle tri3{Point{250,350}, 100, 300};
    tri3.set_fill_color(Color::red);
    win.attach(tri3);

    Right_triangle tri4{Point{350,50}, -100, -300};
    tri4.set_fill_color(Color::red);
    win.attach(tri4);

    Right_triangle tri5{Point{250,150}, -100, 100};
    tri5.set_fill_color(Color::red);
    win.attach(tri5);

    Right_triangle tri6{Point{350,150}, 100, 100};
    tri6.set_fill_color(Color::red);
    win.attach(tri6);

    Right_triangle tri7{Point{250,250}, -100, -100};
    tri7.set_fill_color(Color::red);
    win.attach(tri7);

    Right_triangle tri8{Point{350,250}, 100, -100};
    tri8.set_fill_color(Color::red);
    win.attach(tri8);

    win.wait_for_button();

}
