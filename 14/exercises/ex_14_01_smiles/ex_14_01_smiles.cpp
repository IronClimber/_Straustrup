#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include "Smile.h"

using namespace Graph_lib;

int main() {

  //std::cout << "Hello" << std::endl;

  Simple_window win{Point{100,100}, 600, 400, "Exercise 14.01 - Smiles"};

  Smiley_hat s{Point{150,200},70};
  win.attach(s);

  Frowny_hat f{Point{450,200},70};
  win.attach(f);

  win.wait_for_button();

  return 0;

}
