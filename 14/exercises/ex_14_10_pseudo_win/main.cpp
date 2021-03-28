#include "Simple_window.h"
#include "Pseudo.h"

/*
Определите класс Pseudo_window, напоминающий класс Window.
Он должен иметь закруглённые углы, метку и управляющие пиктограммы.
Добавить содержание.
Окно должно располагаться в окне Simple_window.

*/

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 800, 600, "Exercise 14.10 - Pseudo window"};

  Pseudo_window p_win{Point{100,100}, 400, 400, "Pseudo window"};

  Image img{Point{110,110}, "../../../12/exercises/dimon_small.jpg", Suffix::jpg};
  img.set_mask(Point{200,150},380,360);
  p_win.add_content(img);

  win.attach(p_win);
  win.wait_for_button();

  p_win.move(100,0);
  win.wait_for_button();

  return 0;

}
