#include "Simple_window.h"
#include "Graph.h"
#include "lib_14.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.06 - Stripped Circle"};

  Stripped_circle sc{Point{300,200},100};
  sc.set_fill_color(Color::red);
  //sc.set_color(Color::invisible);
  win.attach(sc);

  win.wait_for_button();

  return 0;
}
