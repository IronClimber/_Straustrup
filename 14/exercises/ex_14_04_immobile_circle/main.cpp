#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

struct Immobile_Circle : Circle {
  using Circle::Circle;
  void move(int dx, int dy) = delete;
};

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.04 - Immobile Circle"};

  Immobile_Circle ic{Point{100,100}, 50};
  win.attach(ic);

  Circle c{Point{300,100}, 50};
  win.attach(c);

  win.wait_for_button();
  ic.move(50,50);
  c.move(50,50);

  win.wait_for_button();
  ic.move(50,50);
  c.move(50,50);

  win.wait_for_button();
  return 0;

}
