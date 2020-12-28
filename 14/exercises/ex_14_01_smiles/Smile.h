#include "Graph.h"

using namespace Graph_lib;
struct Smiley : Circle {

  Smiley(Point p, int rr) : Circle{p, rr} { }
  void draw_lines() const;

};

/*struct Frowny : Circle {
 
  void draw_lines() const override;

};*/
