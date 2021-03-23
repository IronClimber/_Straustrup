#include "Simple_window.h"
#include "Graph.h"
#include "lib_14.h"

using namespace Graph_lib;

constexpr int cell_size = 20;

int main() {

  Simple_window win{Point{100,100}, 600,400,"Exercise 14.08 - Group (Chessboard)"};
  
/*
  Group chessboard;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      chessboard.add(new Rectangle{Point{i*cell_size,j*cell_size},cell_size,cell_size});
      int counter{i+j};
	  //cout << counter << "-" << counter%2;
      if (counter%2) {
		chessboard[chessboard.size()-1].set_fill_color(Color::black);
      //cout << " BLACK" << endl;
	  }
	  else {
		chessboard[chessboard.size()-1].set_fill_color(Color::white);
		//cout << " WHITE" << endl;
	  }
	  //win.attach(chessboard[chessboard.size()-1]);
	  //win.wait_for_button();
    }
  }
  win.attach(chessboard);

  win.wait_for_button();

  chessboard.move(160,80);
*/
/*
  Cell c1{Point{100,100}, 30, true};
  Cell c2{Point{200,200}, 40, false};

  win.attach(c1);
  win.attach(c2);

  win.wait_for_button();

  c1.set_side(false);
  c2.set_side(true);

  win.wait_for_button();

  c1.set_checker(Checker::none);
  c2.set_checker(Checker::none);

  win.wait_for_button();

  c1.set_checker(Checker::light);
  c2.set_checker(Checker::light);

  win.wait_for_button();

  c1.set_checker(Checker::dark);
  c2.set_checker(Checker::dark);

  win.wait_for_button();

  c1.set_checker(Checker::light);
  c2.set_checker(Checker::dark);

  win.wait_for_button();

  c1.set_checker(Checker::dark);
  c2.set_checker(Checker::light);

  win.wait_for_button();

  c1.set_checker(Checker::none);
  c2.set_checker(Checker::light);

  win.wait_for_button();

  c1.set_checker(Checker::light);
  c2.set_checker(Checker::none);

  win.wait_for_button();

  c1.set_checker(Checker::dark);
  c2.set_checker(Checker::none);

  win.wait_for_button();

  c1.set_checker(Checker::none);
  c2.set_checker(Checker::dark);

  win.wait_for_button();

  c1.set_checker(Checker::none);
  c2.set_checker(Checker::none);

  win.wait_for_button();
*/
  Chessboard cb{Point{50,50},200};
  win.attach(cb);
  win.wait_for_button();
  cb.start();
  win.wait_for_button();
  cb.reset();
  cb.move(100,200);
  win.wait_for_button();
  cb.start();
  win.wait_for_button();


  return 0;
}
