//Need to improve
//Look for dec hex conversion

#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"

using namespace Graph_lib;

int main() {

    int width = 20;
    int height = 20;

    Simple_window win{Point{100,100}, width*16, height*16, "Exercise 13.13 - RGB Matrix"};

    Vector_ref<Rectangle> chart;

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {

            chart.push_back(new Rectangle{Point{i*width,j*height}, width, height});
            chart[chart.size()-1].set_fill_color((i+1)*(j+1)-1);
            chart[chart.size()-1].set_color(Color::invisible);

        }
    }

    for (int i = 0; i < chart.size(); ++i) {
        win.attach(chart[i]);
    }
    

    win.wait_for_button();

}
