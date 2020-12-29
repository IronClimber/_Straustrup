#include "Graph.h"

using namespace Graph_lib;
struct Smiley : Circle {

  Smiley(Point p, int rr) : Circle{p, rr} { }
  void draw_lines() const;

};

struct Frowny : Circle {
 
  Frowny(Point p, int rr) : Circle{p, rr} { }
  void draw_lines() const;

};

struct Smiley_hat : Smiley {

  using Smiley::Smiley;
  void draw_lines() const;

};

struct Frowny_hat : Frowny {
  using Frowny::Frowny;
  void draw_lines() const;

};
