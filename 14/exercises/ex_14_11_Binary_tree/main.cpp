#include "Simple_window.h"
#include "Binary_tree.h"

/*
Определите класс Pseudo_window, напоминающий класс Window.
Он должен иметь закруглённые углы, метку и управляющие пиктограммы.
Добавить содержание.
Окно должно располагаться в окне Simple_window.

*/

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 800, 600, "Exercise 14.11 - Binary tree"};

  Binary_tree bt{Point{400,50}, 6};
  win.attach(bt);
  win.wait_for_button();

  return 0;

}
