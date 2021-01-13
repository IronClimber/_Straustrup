#ifndef LIB_14_H
#define LIB_14_H

#include "Graph.h"

namespace Graph_lib {

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection);

struct Stripped_rectangle : Rectangle {

  using Rectangle::Rectangle;
  void draw_lines() const;  

};

struct Stripped_circle : Circle {

  using Circle::Circle;
  void draw_lines() const;  

};

struct Stripped_closed_polyline : Closed_polyline {

  using Closed_polyline::Closed_polyline;
  void draw_lines() const;  

};

}

#endif /* lib_14.h */
