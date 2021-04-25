#include "Function.h"

namespace Graph_lib {

Funct::Funct(Fct f, double r1, double r2, Point orig, int count, double xscale, double yscale) : func_{f}, orig_{orig}, xscale_{xscale}, yscale_{yscale} {
	set_points(count);
	set_range(r1, r2);
	reset();
}

void Funct::set_points(int n) {
	if (n<=0) error("non-positive graphing count");
	count_ = n;
}

void Funct::set_range(double r1, double r2) {
	if (r2-r1<=0) error("bad graphing range");
	range1_ = r1;
	range2_ = r2;
}

void Funct::reset() {
	double dist = (range2_-range1_)/count_;
	double r = range1_;
	for (int i = 0; i<count_; ++i) {
		add(Point(orig_.x+int(r*xscale_),orig_.y-int(func_(r)*yscale_)));
		r += dist;
	}
}
}
