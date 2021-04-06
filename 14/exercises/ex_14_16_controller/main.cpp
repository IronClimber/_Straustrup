#include "Controller.h"
#include <iostream>
#include "Simple_window.h"
#include "Binary_tree.h"

using namespace Graph_lib;

int main() {

/*** Test_controller ****/

  /*Test_controller tc;
  tc.show();
  tc.on();
  tc.show();
  tc.off();
  tc.show();
  tc.on();
  tc.set_level(5);
  tc.show();
*/

	Simple_window win{Point{100,100}, 600, 400, "Ex 14.16 - Controller"};
	Binary_tree bt{Point{300,50}, 4};
	win.attach(bt);
	win.wait_for_button();

    Binary_tree_controller btc{bt};
    btc.show();
    win.wait_for_button();

    btc.off();
    btc.show();
    win.wait_for_button();

    btc.on();
    btc.show();
    win.wait_for_button();

    btc.set_level(5);
    btc.show();
    win.wait_for_button();

    btc.set_level(3);
    btc.show();
    win.wait_for_button();

/***Binary tree controller **/


/*** Shape_controller ****/
/*

  Circle c{Point{300,200},100};
  Shape_controller sc{c};
  win.attach(c);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.on();
  sc.set_level(67);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.set_level(139);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.set_level(220);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.set_level(0);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.off();
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();

  sc.on();
  sc.set_level(3);
  std::cout << c.color().as_int() << " "
            << int(c.color().visibility()) << " "
            << c.fill_color().as_int() << " "
            << int(c.fill_color().visibility()) << " " << std::endl;
  sc.show();
  win.wait_for_button();
*/


  return 0;

}
