//ToDo: Set color and set fill color for TextBox

#include "Simple_window.h"
#include "Graph.h"
#include "lib_13.h"
#include <iostream>


using namespace Graph_lib;


int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.06 - Class Shape Diagram"};

    //Box boxy{Point{40,40},50,50,5};
    //boxy.set_color(Color::red);
    //boxy.set_fill_color(Color::white);
    //win.attach(boxy);

    TextBox shapes{Point{300,150}, 75, 30, "Shapes"};
    //shapes.set_fill_color(Color::white);
    //shapes.set_color(Color::white);
    win.attach(shapes);

    TextBox window{Point{100,50}, 75, 30, "Window"};
    //window.set_fill_color(Color::white);
    win.attach(window);

    TextBox linestyle{Point{250,50}, 100, 30, "Line_style"};
    //linestyle.set_fill_color(Color::white);
    win.attach(linestyle);

    TextBox color{Point{400,50}, 75, 30, "Color"};
    //color.set_fill_color(Color::white);
    win.attach(color);

    TextBox simple_window{Point{72,170}, 130, 30, "Simple_window"};
    win.attach(simple_window);

    TextBox point{Point{430,170}, 75, 30, "Point"};
    win.attach(point);

    TextBox line{Point{20,300}, 50, 30, "Line"};
    win.attach(line);

    TextBox lines{Point{80,300}, 50,30, "Lines"};
    win.attach(lines);

    TextBox polygon{Point{150,300}, 80, 30, "Polygon"};
    win.attach(polygon);

    TextBox axis{Point{270,300}, 50, 30, "Axis"};
    win.attach(axis);

    TextBox rectangle{Point{350,300}, 100, 30, "Rectangle"};
    win.attach(rectangle);

    TextBox text{Point{470,300}, 50, 30, "Text"};
    win.attach(text);

    TextBox image{Point{530,300}, 60, 30, "Image"};
    win.attach(image);

    Arrow image_shapes{image.n(),shapes.s()};
    win.attach(image_shapes);

    Arrow text_shapes{text.n(),shapes.s()};
    win.attach(text_shapes);

    Arrow rectangle_shapes{rectangle.n(),shapes.s()+7};
    win.attach(rectangle_shapes);

    Arrow axis_shapes{axis.n(),shapes.s()};
    win.attach(axis_shapes);

    Arrow polygon_shapes{polygon.n()-7,shapes.s()};
    win.attach(polygon_shapes);

    Arrow lines_shapes{lines.n(),shapes.s()};
    win.attach(lines_shapes);

    Arrow line_shapes{line.n(),shapes.s()};
    win.attach(line_shapes);

    Arrow simple_window_window{simple_window.n(),window.s()};
    win.attach(simple_window_window);

    win.wait_for_button();

}
