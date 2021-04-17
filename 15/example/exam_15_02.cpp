#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {

    /* Three functions */
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    Point orig{x_orig, y_orig};

    constexpr int r_min = -10;
    constexpr int r_max = 11;

    constexpr int n_points = 400;

    constexpr int x_scale = 30;
    constexpr int y_scale = 30;

    Simple_window win{Point{100,100},xmax,ymax,"Function graphing"};

	Function s{one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2{slope,r_min,r_max,orig,n_points,x_scale,y_scale};
 	Function s3{square,r_min,r_max,orig,n_points,x_scale,y_scale};

    win.attach(s);   
    win.attach(s2);
    win.attach(s3);
	win.wait_for_button();
 
	/* Add text */
    Text ts {Point{100,y_orig-40},"one"};
	Text ts2 {Point{100,y_orig+y_orig/2-20},"x/2"};
	Text ts3 {Point{x_orig-100,20},"x*x"};
    win.set_label("Function graphing: label functions");
    win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);
	win.wait_for_button();

    /* Add axis */
	constexpr int xlength = xmax-40;
	constexpr int ylength = ymax-40;

	Axis x {Axis::x, Point{20, y_orig},
			xlength, xlength/x_scale, "one notch == 1"};
	Axis y {Axis::y, Point{x_orig,ylength+20},
			ylength, ylength/y_scale, "one notch == 1"}; 
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

    /* Add cos */
	Function s4{cos,r_min,r_max,orig,400,30,30};
	s4.set_color(Color::blue);
	Function s5{sloping_cos,r_min,r_max,orig,400,30,30};
	x.label.move(-160,0);
	x.notches.set_color(Color::dark_red);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();

	/* Add functions */
	win.detach(s4);
	Function f1 {log,0.000001,r_max,orig,200,30,30};
	Function f2 {sin,r_min,r_max,orig,200,30,30};
	f2.set_color(Color::blue);
	Function f3 {cos,r_min,r_max,orig,200,30,30};
	Function f4 {exp,r_min,r_max,orig,200,30,30};
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.wait_for_button();

	/* Lambda - function */
	win.detach(s5);
	Function s6 {[](double x) { return cos(x)+slope(x); },
				 r_min, r_max, orig, 400,30,30};
	s6.set_color(Color::green);
	win.attach(s6);
	win.wait_for_button();

    return 0;

}
