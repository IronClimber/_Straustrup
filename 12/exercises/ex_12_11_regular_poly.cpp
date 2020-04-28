#include "Simple_window.h"
#include "Graph.h"

//How to inscribe (N-1)polygon in the N-polygon using math?

using namespace Graph_lib;

//xy - down,left point
void create_regular_polygon(Polygon& poly, Point xy, int n, int l) {

    int x = xy.x;
    int y = xy.y;
    double angle = 2*M_PI/n;
    double angle_iterator = 0;
    double r = l*sin((M_PI-angle)/2)/sin(angle);
    //int x0 = int (r*sin(angle/2));
    //int y0 = int (r*cos(angle/2));

    for (int i = 0; i < n; ++i) {

        angle_iterator = i*angle-angle/2-M_PI/2;
        x = xy.x + int(r*cos(angle_iterator));
        y = xy.y - int(r*sin(angle_iterator));
        //x = xy.x + x0 + int(r*cos(angle_iterator));
        //y = xy.y - y0 - int(r*sin(angle_iterator));
        poly.add(Point{x,y});
    }
}

int main() {

    Simple_window win{Point{100,100}, 400, 400, "Excersice 12.11 - Regular Polygon"};

    Polygon regular_poly0;
    create_regular_polygon(regular_poly0, Point{200,150}, 9, 100);
    regular_poly0.set_fill_color(Color::white);
    win.attach(regular_poly0);

    Polygon regular_poly1;
    create_regular_polygon(regular_poly1, Point{200,154}, 8, 107);
    regular_poly1.set_fill_color(Color::yellow);
    win.attach(regular_poly1);

    Polygon regular_poly2;
    create_regular_polygon(regular_poly2, Point{200,159}, 7, 115);
    regular_poly2.set_fill_color(Color::green);
    win.attach(regular_poly2);

    Polygon regular_poly3;
    create_regular_polygon(regular_poly3, Point{200,165}, 6, 124);
    regular_poly3.set_fill_color(Color::red);
    win.attach(regular_poly3);

    Polygon regular_poly4;
    create_regular_polygon(regular_poly4, Point{200,172}, 5, 133);
    regular_poly4.set_fill_color(Color::blue);
    win.attach(regular_poly4);

    Polygon regular_poly5;
    create_regular_polygon(regular_poly5, Point{200,181}, 4, 141);
    regular_poly5.set_fill_color(Color::magenta);
    win.attach(regular_poly5);

    Polygon regular_poly6;
    create_regular_polygon(regular_poly6, Point{200,191}, 3, 141);
    regular_poly6.set_fill_color(Color::black);
    win.attach(regular_poly6);
    win.wait_for_button();

}
