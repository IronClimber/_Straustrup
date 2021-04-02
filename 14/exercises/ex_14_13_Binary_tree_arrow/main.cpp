#include "Simple_window.h"
#include "Binary_tree.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 800, 600, "Exercise 14.13 - Binary tree"};

  Binary_tree bt{Point{400,50}, 6, Color::red, true};
  win.attach(bt);
  win.wait_for_button();
  bt.move(100,100);
  win.wait_for_button();
  return 0;

}
