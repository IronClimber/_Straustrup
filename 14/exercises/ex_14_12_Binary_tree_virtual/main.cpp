#include "Simple_window.h"
#include "Binary_tree.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 800, 600, "Exercise 14.12 - Binary tree"};

  Binary_tree_triangle bt{Point{400,50}, 6};
  win.attach(bt);
  win.wait_for_button();

  return 0;

}
