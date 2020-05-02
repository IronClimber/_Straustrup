#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,50}, 800, 800, "Task 13"};
    
    Vector_ref<Rectangle> rect;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            rect.push_back(new Rectangle{Point{i*100,j*100}, 100, 100});
            if (i==j) rect[rect.size()-1].set_fill_color(Color::red);
            win.attach(rect[rect.size()-1]);
        }
    }

    Image barbarian_big0{Point{200,0},"barbarian.jpg"};
    Image barbarian_big1{Point{600,400},"barbarian.jpg"};
    Image barbarian_big2{Point{0,600},"barbarian.jpg"};

    win.attach(barbarian_big0);
    win.attach(barbarian_big1);
    win.attach(barbarian_big2);

    Image barbarian_small{Point{0,0},"barbarian_small.jpg"};
    win.attach(barbarian_small);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            win.wait_for_button();
            barbarian_small.move(100,0);
            if (j==7) barbarian_small.move(-800,100);
        }
    }
    win.wait_for_button();

}
