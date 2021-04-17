#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int fac(int n) {
	int r = 1;
	while (n>1) {
		r*=n;
		--n;
	}
	return r;
}

double term(double x, int n) {
	return pow(x,n)/fac(n);
}

double expe(double x, int n) {
	double sum = 0;
	for (int i=0; i<n; ++i) sum+=term(x,i);
	return sum;
}

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

	/* real exp */
	Function real_exp {&exp, r_min, r_max-5, orig, 200, x_scale, y_scale};
	real_exp.set_color(Color::blue);
	win.attach(real_exp);
	win.wait_for_button();

	/* our exp */
	for (int n = 0; n<50; ++n) {
		ostringstream ss;
		ss << "exp approximation; n==" << n;
		win.set_label(ss.str());
		//ToDo: lambda not type double (*)double. id use capture list
		Function e {[n](double x) { return expe(x,n); }, r_min,r_max,orig,200,x_scale,y_scale};
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	
	}

    return 0;

}
