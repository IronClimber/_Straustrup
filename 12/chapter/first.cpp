#include "Simple_window.h"
//#include "Graph.h"
//#include "Point.h"
//#include "Window.h"
//#include "GUI.h"
#include "Graph.h"

int main() {
    
    
    //cout << "It works!" << endl;
    //Graph_lib::Point t1{100,100};
    //Graph_lib::Window win(600,400,"Canvas");
    //Window win(t1,600,400,"Canvas");
    //win.attach(poly);
    //win.wait_for_button();
    
    using namespace Graph_lib;
    Point t1{100,100};
    Simple_window win(t1,600,400,"Canvas");
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    win.attach(poly);
    win.wait_for_button();

}
