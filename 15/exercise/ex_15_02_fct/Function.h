#ifndef FUNCTION_HH_
#define FUNCTION_HH_

#include "Graph.h"

namespace Graph_lib {

struct Funct : Function {
	Funct(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	void set_range(double r1, double r2);
	void set_origin(Point p) { orig_ = p; }
	void set_points(int n);
	void set_scale(double x, double y) { xscale_ = x; yscale_ = y; }
	void set_function(Fct f) { func_ = f; }

	void reset();

private:
	double range1_;
	double range2_;
	Point orig_;
	int count_;
	double xscale_;
	double yscale_;
	//Fct func_
	double (*func_) (double);


};

}
#endif /* FUNCTION_HH_ */
