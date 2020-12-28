#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include "Smile.h"

using namespace Graph_lib;

int main() {

  //std::cout << "Hello" << std::endl;

  Simple_window win{Point{100,100}, 600, 400, "Exercise 14.01 - Smiles"};

  Smiley s{Point{300,200},70};
  win.attach(s);

  win.wait_for_button();

  return 0;

}
