#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600, 400, "Exercise 13.19 - Star"};
  
  Star s1{Point{300,200}, 5, 150, 50};
  s1.set_color(Color::green);
  s1.set_fill_color(Color::yellow);

  win.attach(s1);

  Star s2{Point{500,300},8, 100, 70};
  s2.set_color(Color::red);
  s2.set_fill_color(Color::white);

  win.attach(s2);

  Star s3{Point{100,100}, 3, 150, 20};
  s3.set_color(Color::blue);
  s3.set_fill_color(Color::red);

  win.attach(s3);

  Star s4{Point{500,150}, 12, 150, 20};
  s4.set_color(Color::black);
  s4.set_fill_color(Color::white);

  win.attach(s4);

  win.wait_for_button();

  return 0;

}
