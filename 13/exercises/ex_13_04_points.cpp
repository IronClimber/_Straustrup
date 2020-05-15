#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>


using namespace Graph_lib;

Point center(Rectangle& r) {
    return Point{r.point(0).x+r.width()/2, r.point(0).y+r.height()/2};
}

Point n(Rectangle& r) {
    return Point{r.point(0).x+r.width()/2, r.point(0).y};
}

Point e(Rectangle& r) {
    return Point{r.point(0).x+r.width(), r.point(0).y+r.height()/2};
}

Point s(Rectangle& r) {
    return Point{r.point(0).x+r.width()/2, r.point(0).y+r.height()};
}

Point w(Rectangle& r) {
    return Point{r.point(0).x, r.point(0).y+r.height()/2};
}

Point ne(Rectangle& r) {
    return Point{r.point(0).x+r.width(), r.point(0).y};
}

Point se(Rectangle& r) {
    return Point{r.point(0).x+r.width(), r.point(0).y+r.height()};
}

Point sw(Rectangle& r) {
    return Point{r.point(0).x, r.point(0).y+r.height()};
}

Point nw(Rectangle& r) {
    return Point{r.point(0)};
}


int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.04 - Connection points"};

    Rectangle rect{Point{100,100},300,200};
    win.attach(rect);
    
    Arrow arrow1{center(rect), Point{10,10}};
    win.attach(arrow1);

    Arrow arrow2{n(rect), Point{46,180}};
    win.attach(arrow2);

    Arrow arrow3{e(rect), Point{140,210}};
    win.attach(arrow3);

    Arrow arrow4{s(rect), Point{190,130}};
    win.attach(arrow4);

    Arrow arrow5{w(rect), Point{410,350}};
    win.attach(arrow5);

    Arrow arrow6{sw(rect), Point{110,40}};
    win.attach(arrow6);

    Arrow arrow7{nw(rect), Point{450,390}};
    win.attach(arrow7);

    Arrow arrow8{ne(rect), Point{110,250}};
    win.attach(arrow8);

    Arrow arrow9{se(rect), Point{10,350}};
    win.attach(arrow9);

    win.wait_for_button();

}
