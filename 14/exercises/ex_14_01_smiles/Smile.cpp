#include "Smile.h"

//Smiley::Smiley(Point p, int rr) 

void Smiley::draw_lines() const {

  Circle::draw_lines();

  Circle eye_left(Point{center().x-radius()/4, center().y-radius()/4}, radius()/4);

  Circle eye_right(Point{center().x+radius()/4, center().y-radius()/4}, radius()/4);

  eye_left.draw_lines();
  eye_right.draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
	int r = int(radius()*2/3);
    fl_arc(center().x-r,center().y-r,r*2,r*2,240,300);
  }		

}
