#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 1100, 800, "Excersice 12.09 - My friend Dima"};

    Image dima{Point{30,30},"dimon_small.jpg"};
    Text t{Point{400,25}, "Пулемётчик Дмитрий Шапкин"};
    t.set_font_size(20);
    win.attach(t);
    win.attach(dima);
    win.wait_for_button();

}
