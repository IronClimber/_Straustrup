#include "lib_14.h"

namespace Graph_lib {

void Stripped_rectangle::draw_lines() const {
  
  if (fill_color().visibility()) {	// fill
	fl_color(fill_color().as_int());
	for (int i = 0; i < height(); ++i) {
	  if (i%2) {
 		fl_line(point(0).x,point(0).y+i,point(0).x+width()-1,point(0).y+i);
	  }
	}
	fl_color(color().as_int());	// reset color
  }

  if (color().visibility()) {	// edge on top of fill
	fl_color(color().as_int());
	fl_rect(point(0).x,point(0).y,width(),height());
  }

}

void Stripped_circle::draw_lines() const {
  
  if (fill_color().visibility()) {	// fill
	fl_color(fill_color().as_int());
	for (int i = 0; i < radius()*2; ++i) {
	  if (i%2) {
		int h = -(i-radius());
        int a = sqrt(radius()*radius()-h*h);
 		fl_line(point(0).x + radius() - a,
				point(0).y+i,
				point(0).x + radius() + a - 1,
				point(0).y+i);
	  }
	}
	fl_color(color().as_int());	// reset color
  }

  if (color().visibility()) {	// edge on top of fill
	fl_color(color().as_int());
	fl_arc(point(0).x,point(0).y,radius()*2,radius()*2,0,360);
  }

}

}
