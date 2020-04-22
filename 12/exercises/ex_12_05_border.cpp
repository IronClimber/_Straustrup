#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{0,0}, x_max(), y_max(), "Excersice 12.05 - Red border"};

    int width_px = x_max()*3/4;
    int height_px = y_max()*2/3;

    int start_x = (x_max()-width_px)/2;
    int start_y = (y_max()-height_px)/2;

    int win_width_mm = 310;
    int win_height_mm = 175;

    int size_mm = 5;
    int size_x_px = size_mm*x_max()/win_width_mm;
    int size_y_px = size_mm*y_max()/win_height_mm;

    Rectangle outer{Point{start_x-size_x_px, start_y-size_y_px}, 
                    width_px+2*size_x_px, height_px+2*size_y_px};
    outer.set_fill_color(Color::red);
    win.attach(outer);

    Rectangle inner{Point{start_x, start_y}, width_px, height_px};
    inner.set_fill_color(Color::white);
    win.attach(inner);

    win.wait_for_button();

}
