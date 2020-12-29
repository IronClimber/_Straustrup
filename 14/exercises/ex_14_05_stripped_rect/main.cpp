#include "Simple_window.h"
#include "Graph.h"
#include "lib_14.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.05 - Stripped Rectangle"};

  Stripped_rectangle sr{Point{200,200},200,100};
  sr.set_fill_color(Color::red);
  sr.set_color(Color::invisible);
  win.attach(sr);

  win.wait_for_button();

  return 0;
}
