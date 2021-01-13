#include "Simple_window.h"
#include "Graph.h"
#include "lib_14.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.07 - Stripped Polyline"};

  Stripped_closed_polyline sp {};
  sp.add(Point{100,50});
  sp.add(Point{150,75});
  sp.add(Point{167,25});
  sp.add(Point{258,205});
  sp.add(Point{386,140});
  sp.set_fill_color(Color::red);
  //sp.set_color(Color::invisible);
  win.attach(sp);

  win.wait_for_button();

  return 0;
}
