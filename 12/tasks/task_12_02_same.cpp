#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    
    Point t1{300,300};
    Simple_window win{t1,600,400,"Canvas"};

    win.wait_for_button();

    Axis xa{Axis::x, Point(20,300), 280, 10, "x axis"};
    win.attach(xa);
    win.set_label("Canvas #2");

    win.wait_for_button();

    Axis ya{Axis::y, Point{20,300}, 280, 10, "y_axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    win.wait_for_button();

    Function sine{sin,0,100,Point(20,150),1000,50,50};
    win.attach(sine);
    win.set_label("Canvas #4");

    win.wait_for_button();

    sine.set_color(Color::blue);
        
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,120});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");

    win.wait_for_button();

    Rectangle r{Point{200,200},100,50};
    win.attach(r);
    win.set_label("Canvas #6");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    win.set_label("Canvas #6.2");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);
    
    win.set_label("Canvas #7");
    win.wait_for_button();
    
    Text t(Point{150,150}, "Hello, graphical world!");
    win.attach(t);
 
    win.set_label("Canvas #8");
    win.wait_for_button();     

    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);

    win.set_label("Canvas #9");
    win.wait_for_button();        

    Image ii{Point{100,50}, "image.jpg"};
    win.attach(ii);
    win.set_label("Canvas 10");
    win.wait_for_button();

    ii.move(100,200);
    win.set_label("Canvas 11");
    win.wait_for_button();

    Circle c{Point{100,200},50};
    Ellipse e{Point{100,200},75,25};
    e.set_color(Color::dark_red);
    Mark m{Point{100,200},'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; windows size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100,20},oss.str()};

    Image cal{Point{255,255},"snow_cpp.gif"};
    cal.set_mask(Point{40,40},200,150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.wait_for_button();

}
