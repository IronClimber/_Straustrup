#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600, 400, "Exercise 13.18 - Poly"};

  Poly p{
            Point{51,50},
            Point{101,50}, 
            Point{100,102}, 
            Point{50,100},
            Point{34,75},
            Point{324,53},
            Point{123,156},
            Point{34,200}
  };
  
  win.attach(p);

  win.wait_for_button();

  return 0;

}
