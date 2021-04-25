#include <Simple_window.h>
#include <Graph.h>
#include "Function.h"

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	constexpr int orig_x = 300;
	constexpr int orig_y = 300;
	Point orig{orig_x, orig_y};

	constexpr int x_length = 400;
	constexpr int y_length = 400;

	constexpr int unit_x = 20;
	constexpr int unit_y = 20;


	Simple_window win{Point{100,100}, xmax, ymax, "Exercise 15.02 - Fct()"};

	Axis x {Axis::x, Point{(xmax-x_length)/2, orig_y}, x_length, x_length/unit_x, "1 == 20 pixels"};
	x.set_color(Color::red);
	win.attach(x); 
	Axis y {Axis::y, Point{orig_y,(ymax+y_length)/2}, y_length, y_length/unit_y, "1 == 20 pixels"};
	y.set_color(Color::red);
	win.attach(y); 

	//Funct f{cos,-5,5,Point{300,300},100,40,40};
    //win.attach(f);

	Funct f2 {one, -10, 11, orig, 400, 20, 20};
	win.attach(f2);

	Funct f3 {slope, -10, 11, orig, 400, 20, 20};
	win.attach(f3);

	Funct f4 {square, -10, 11, orig, 400, 20, 20};
	win.attach(f4);

	Funct f5 {cos, -10, 11, orig, 400, 20, 20};
	f5.set_color(Color::blue);
	win.attach(f5);

	Funct f6 {sloping_cos, -10, 11, orig, 400, 20, 20};
	win.attach(f6);

	win.wait_for_button();




	return 0;
}
