#include <iostream>
//#include "Simple_window.h"
//#include "Graph.h"
//#include "Smile.h"
/*
using namespace GraphLib;

struct Smiley : Circle {

  Smiley(Point p, int rr) : Circle{p, rr} { }
  void draw_lines() const;

};

void Smiley::draw_lines() const {

  Circle::draw_lines();

  Circle eye_left(Point{center().x-radius()/4, center().y-radius()/4}, radius()/4);

  Circle eye_right(Point{center().x+radius()/4, center().y-radius()/4}, radius()/4);

  eye_left.draw_lines();
  eye_right.draw_lines();
  if (color().visibility()) {
    fl_color(color().as_int());
    fl_arc(center().x,center().y,radius(),radius(),240,300);
  }		

}
*/
int main() {
  std::cout << "Hello" << std::endl;
 /* Simple_window win{Point{100,100}, 600, 400, "Exercise 14.1 - Smiley&Frowney"};

  Smiley s{Point{300,200}, 150};

  win.attach(s);

  win.wait_for_button();*/

  return 0;

}
