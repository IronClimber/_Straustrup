#include <iostream>
#include "Controller.h"

using namespace Graph_lib;

void Test_controller::show() {
  std::cout << "Controller is ";
  if (state) { std::cout << "ON"; }
  else { std::cout << "OFF"; }
  std::cout << " with level = " << level << std::endl;
}

void Shape_controller::on() {
  state = true;
  Color fc{figure.color()};
  fc.set_visibility(Color::visible);
  figure.set_color(fc);
  Color ffc{figure.fill_color()};
  ffc.set_visibility(Color::visible);
  figure.set_fill_color(ffc);
}

void Shape_controller::off() {
  state = false;
  Color fc{figure.color()};
  fc.set_visibility(Color::invisible);
  figure.set_color(fc);
  Color ffc{figure.fill_color()};
  ffc.set_visibility(Color::invisible);
  figure.set_fill_color(ffc);
  
}

void Shape_controller::set_level(int l) {
  if (l>=0 && l<=255) {
      level = l;
	  figure.set_fill_color(l);
  }
}

void Shape_controller::show() {
  std::cout << "Controller is ";
  if (state) { std::cout << "ON"; }
  else { std::cout << "OFF"; }
  std::cout << " with level = " << level << std::endl;
}

void Binary_tree_controller::show() {
  std::cout << "Controller is ";
  if (state) { std::cout << "ON"; }
  else { std::cout << "OFF"; }
  std::cout << " with level = " << level << std::endl;
}
