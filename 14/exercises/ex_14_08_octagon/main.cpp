#include "Simple_window.h"
#include "Graph.h"
#include "lib_14.h"

using namespace Graph_lib;

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.08 - Octagon"};
  
  Octagon octa{Point{300,200}, 50};
  octa.set_fill_color(Color::white);
  octa.set_color(Color::blue);
  octa.set_style(Line_style::dot);
  octa.move(-200,-100);
  win.attach(octa);

  cout << " Color: " << octa.color().as_int() << endl;
  cout << " Fill color: " << octa.fill_color().as_int() << endl;
  cout << " Line style: " << octa.style().width() << " "
						  << octa.style().style() << endl;
  cout << " Point[7]: " << octa.point(7).x << " "
						<< octa.point(7).y << endl;
  cout << " Number of points: " << octa.number_of_points() << endl;

  win.wait_for_button();

  return 0;
}
