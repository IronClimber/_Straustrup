#include "Simple_window.h"
#include "Graph.h"
#include <iostream>


using namespace Graph_lib;

struct Arc : Shape {

    Arc(Point p, int ww, int hh, double s, double f) 
        : w{ww}, h{hh}, a1{s}, a2{f}  {

        add(Point{p.x-ww, p.y-hh});

    }

    void draw_lines() const;

private:
    int w;
    int h;
    double a1;
    double a2;

};

void Arc::draw_lines() const {
    if (color().visibility()) {
        cout << point(0).x << " " << point(0).y<< " "
             << w+w<< " " << h+h<< " " 
            << a1<< " " << a2 << endl;
        fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,w+w,h+h,a1,a2);
    }
}

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.01 - Arc"};

    Arc a{Point{300,200},200,100,90,180};
    a.set_color(Color::black);
    
    win.attach(a);

    win.wait_for_button();

}
