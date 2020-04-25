#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main() {

    Simple_window win{Point{100,100}, 600, 800, "Excersice 12.10 - File diagram"};
    
    /*FLTK headers*/
    Rectangle fltk_h1{Point{240,40},120,50};
    fltk_h1.set_fill_color(Color::white);
    win.attach(fltk_h1);

    Rectangle fltk_h2{Point{245,45},120,50};
    fltk_h2.set_fill_color(Color::white);
    win.attach(fltk_h2);

    Rectangle fltk_h{Point{250,50},120,50};
    fltk_h.set_fill_color(Color::white);
    win.attach(fltk_h);

    Text fltk_h_text{Point{260,70}, "FLTK headers"};
    win.attach(fltk_h_text);

    /*FLTK code*/
    Rectangle fltk_code1{Point{440,90},100,50};
    fltk_code1.set_fill_color(Color::white);
    win.attach(fltk_code1);

    Rectangle fltk_code2{Point{445,95},100,50};
    fltk_code2.set_fill_color(Color::white);
    win.attach(fltk_code2);

    Rectangle fltk_code{Point{450,100},100,50};
    fltk_code.set_fill_color(Color::white);
    win.attach(fltk_code);

    Text fltk_code_text{Point{460,120}, "FLTK code"};
    win.attach(fltk_code_text);

    /*Arrow fromk FLTK code to FLTK headers*/
    Line fltk_code_fltk_h{Point{440,115},Point{370,75}};
    win.attach(fltk_code_fltk_h);

    Circle fltk_code_fltk_h_arrow{Point{370,75},2};
    fltk_code_fltk_h_arrow.set_fill_color(Color::black);
    win.attach(fltk_code_fltk_h_arrow);

    /*Point header*/
    Rectangle point_h{Point{50,100},150,30};
    point_h.set_fill_color(Color::white);
    win.attach(point_h);

    Text point_h_up_text{Point{50,90}, "Point.h:"};
    win.attach(point_h_up_text);

    Text point_h_in_text{Point{60,120}, "struct Point { ... };"};
    win.attach(point_h_in_text);

    /*Window header*/
    Rectangle window_h{Point{250,170},150, 60};
    window_h.set_fill_color(Color::white);
    win.attach(window_h);

    /*Graph header*/
    Rectangle graph_h{Point{50,200},150, 60};
    graph_h.set_fill_color(Color::white);
    win.attach(graph_h);
    

    win.wait_for_button();

}
