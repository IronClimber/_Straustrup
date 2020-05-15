#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>


using namespace Graph_lib;

Point center(Circle& c) {
    return Point{c.center()};
}

Point n(Circle& c) {
    return Point{c.center().x, c.center().y-c.radius()};
}

Point e(Circle& c) {
    return Point{c.center().x+c.radius(), c.center().y};
}

Point s(Circle& c) {
    return Point{c.center().x, c.center().y+c.radius()};
}

Point w(Circle& c) {
    return Point{c.center().x-c.radius(), c.center().y};
}

Point ne(Circle& c) {
    return Point{c.center().x+int(c.radius()*0.7), c.center().y-int(c.radius()*0.7)};
}

Point se(Circle& c) {
    return Point{c.center().x+int(c.radius()*0.7), c.center().y+int(c.radius()*0.7)};
}

Point sw(Circle& c) {
    return Point{c.center().x-int(c.radius()*0.7), c.center().y+int(c.radius()*0.7)};
}

Point nw(Circle& c) {
    return Point{c.center().x-int(c.radius()*0.7), c.center().y-int(c.radius()*0.7)};
}


Point center(Ellipse& e) {
    return Point{e.center()};
}

Point n(Ellipse& e) {
    return Point{e.center().x, e.center().y-e.minor()};
}

Point e(Ellipse& e) {
    return Point{e.center().x+e.major(), e.center().y};
}

Point s(Ellipse& e) {
    return Point{e.center().x, e.center().y+e.minor()};
}

Point w(Ellipse& e) {
    return Point{e.center().x-e.major(), e.center().y};
}

Point ne(Ellipse& e) {
    return Point{e.center().x+int(e.major()*0.7), e.center().y-int(e.minor()*0.7)};
}

Point se(Ellipse& e) {
    return Point{e.center().x+int(e.major()*0.7), e.center().y+int(e.minor()*0.7)};
}

Point sw(Ellipse& e) {
    return Point{e.center().x-int(e.major()*0.7), e.center().y+int(e.minor()*0.7)};
}

Point nw(Ellipse& e) {
    return Point{e.center().x-int(e.major()*0.7), e.center().y-int(e.minor()*0.7)};
}


int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.05 - Connection points for circle and ellipse"};

    /* 
    Circle circle{Point{300,200},100};
    win.attach(circle);
    
    Arrow arrow1{center(circle), Point{10,10}};
    win.attach(arrow1);

    Arrow arrow2{n(circle), Point{46,180}};
    win.attach(arrow2);

    Arrow arrow3{e(circle), Point{140,210}};
    win.attach(arrow3);

    Arrow arrow4{s(circle), Point{190,130}};
    win.attach(arrow4);

    Arrow arrow5{w(circle), Point{410,350}};
    win.attach(arrow5);

    Arrow arrow6{sw(circle), Point{110,40}};
    win.attach(arrow6);

    Arrow arrow7{nw(circle), Point{450,390}};
    win.attach(arrow7);

    Arrow arrow8{ne(circle), Point{110,250}};
    win.attach(arrow8);

    Arrow arrow9{se(circle), Point{10,350}};
    win.attach(arrow9);
    */

    Ellipse ellipse{Point{300,200},200,100};
    win.attach(ellipse);
    
    Arrow arrow1{center(ellipse), Point{10,10}};
    win.attach(arrow1);

    Arrow arrow2{n(ellipse), Point{46,180}};
    win.attach(arrow2);

    Arrow arrow3{e(ellipse), Point{140,210}};
    win.attach(arrow3);

    Arrow arrow4{s(ellipse), Point{190,130}};
    win.attach(arrow4);

    Arrow arrow5{w(ellipse), Point{410,350}};
    win.attach(arrow5);

    Arrow arrow6{sw(ellipse), Point{110,40}};
    win.attach(arrow6);

    Arrow arrow7{nw(ellipse), Point{450,390}};
    win.attach(arrow7);

    Arrow arrow8{ne(ellipse), Point{110,250}};
    win.attach(arrow8);

    Arrow arrow9{se(ellipse), Point{10,350}};
    win.attach(arrow9);
    win.wait_for_button();

}
