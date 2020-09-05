//Need to improve
//Look for dec hex conversion

#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"

using namespace Graph_lib;

int main() {

    int width = 65;
    int height = 20;

    Simple_window win{Point{100,100}, width*7, height*36, "Exercise 13.07 - RGB Chart"};

    Vector_ref<RectBox> chart;
    char step = 0x33;
    char r = 0x00;
    char g = 0x00;
    char b = 0x00;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                chart.push_back(new RectBox{Point{k*width,(j+i*6)*height}, width, height});
                //chart[chart.size()-1].rect.set_fill_color((i*7*6+j*7 +k));
                chart[chart.size()-1].set_fill_color(r,g,b);
                chart[chart.size()-1].lab.set_label(to_string((i*6*6+j*6 +k)));
                b+=step;
            }
            g+=step;
        }
        r+=step;
    }

    for (int i = 0; i < chart.size(); ++i) {
        win.attach(chart[i]);
    }
    

    win.wait_for_button();

}
