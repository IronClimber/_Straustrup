#include "Simple_window.h"
#include "Graph.h"


using namespace Graph_lib;


int main() {

    Simple_window win{Point{100,100}, 400, 400, "collor pallete"};

    Vector_ref<Rectangle> vr;

    for (int i=0; i<16; ++i) 
        for (int j=0; j<16; ++j) {
            vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
            vr[vr.size()-1].set_fill_color(Color{narrow_cast<unsigned int>(i*16+j)});
            win.attach(vr[vr.size()-1]);
        }

    win.wait_for_button();

}
