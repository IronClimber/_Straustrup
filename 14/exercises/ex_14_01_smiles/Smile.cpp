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

void Frowny::draw_lines() const {

  Circle::draw_lines();

  Circle eye_left(Point{center().x-radius()/4, center().y-radius()/4}, radius()/4);

  Circle eye_right(Point{center().x+radius()/4, center().y-radius()/4}, radius()/4);

  eye_left.draw_lines();
  eye_right.draw_lines();

  if (color().visibility()) {
    fl_color(color().as_int());
	int r = int(radius()*2/3);
    fl_arc(center().x-r,center().y+r,r*2,r*2,60,120);
  }		

}

void Smiley_hat::draw_lines() const {

  Smiley::draw_lines();
  Closed_polyline p;
  p.add(Point{center().x+int(radius()*0.9), center().y-int(radius()/2)});
  p.add(Point{center().x-int(radius()*0.9), center().y-int(radius()/2)});
  p.add(Point{center().x, center().y-radius()*2});
  p.set_fill_color(Color::red);
  p.draw_lines();

  //int r = int(radius()*2/3);
  Circle ball(Point{center().x, center().y-radius()*2}, radius()/4);
  ball.set_fill_color(Color::white);

  ball.draw_lines();

}

void Frowny_hat::draw_lines() const {

  Frowny::draw_lines();
  Closed_polyline p;
  
  p.add(Point{center().x+int(radius()*0.9), center().y-int(radius()/2)});
  p.add(Point{center().x-int(radius()*0.9), center().y-int(radius()/2)});
  p.add(Point{center().x-int(radius()*0.9), center().y-int(radius()*2)});
  p.add(Point{center().x+int(radius()*0.9), center().y-int(radius()*2)});
  p.set_fill_color(Color::black);
  p.draw_lines();

  Lines l;
  l.add(Point{center().x+int(radius()*1.5), center().y-int(radius()/2)}, Point{center().x-int(radius()*1.5), center().y-int(radius()/2)});
  l.draw_lines();
}
