#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.15 - Triangle puzzle"};

    Vector_ref<Right_triangle> rtv;

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 20; ++j) {
            rtv.push_back(new Right_triangle{Point{i*20,j*20},20,-20});
            win.attach(rtv[rtv.size()-1]);
            rtv.push_back(new Right_triangle{Point{i*20+20,j*20+20},-20,20});
            win.attach(rtv[rtv.size()-1]);
        }
    }

    win.wait_for_button();

}
