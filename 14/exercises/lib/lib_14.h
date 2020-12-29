#ifndef LIB_14_H
#define LIB_14_H

#include "Graph.h"

namespace Graph_lib {

struct Stripped_rectangle : Rectangle {

  using Rectangle::Rectangle;
  void draw_lines() const;  

};

struct Stripped_circle : Circle {

  using Circle::Circle;
  void draw_lines() const;  

};

}

#endif /* lib_14.h */
