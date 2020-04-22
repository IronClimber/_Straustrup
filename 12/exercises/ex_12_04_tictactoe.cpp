/* Not posible to use vector to store rectangles. In Shape class "=" operator is deleted */

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;



int main() {

    Simple_window win{Point{100,100}, 400, 400, "Excersice 12.04 - TicTacToe"};

    int start_x{100};
    int start_y{100};
    int size{30};
    //Point p{100,100}
    int rows{3};
    int columns{3};
    int row{0};
    int column{0};

    /* --- HARDCODED --- */
    /*
    Rectangle rect0{Point{start_x+column*size, start_y+row*size}, size, size};
    rect0.set_fill_color(Color::white);
    win.attach(rect0);

    ++column;

    Rectangle rect1{Point{start_x+column*size, start_y+row*size}, size, size};
    rect1.set_fill_color(Color::red);
    win.attach(rect1);

    ++column;

    Rectangle rect2{Point{start_x+column*size, start_y+row*size}, size, size};
    rect2.set_fill_color(Color::white);
    win.attach(rect2);

    column=0;
    ++row;

    Rectangle rect3{Point{start_x+column*size, start_y+row*size}, size, size};
    rect3.set_fill_color(Color::red);
    win.attach(rect3);

    ++column;

    Rectangle rect4{Point{start_x+column*size, start_y+row*size}, size, size};
    rect4.set_fill_color(Color::white);
    win.attach(rect4);

    ++column;

    Rectangle rect5{Point{start_x+column*size, start_y+row*size}, size, size};
    rect5.set_fill_color(Color::red);
    win.attach(rect5);

    column=0;
    ++row;

    Rectangle rect6{Point{start_x+column*size, start_y+row*size}, size, size};
    rect6.set_fill_color(Color::white);
    win.attach(rect6);

    ++column;

    Rectangle rect7{Point{start_x+column*size, start_y+row*size}, size, size};
    rect7.set_fill_color(Color::red);
    win.attach(rect7);

    ++column;

    Rectangle rect8{Point{start_x+column*size, start_y+row*size}, size, size};
    rect8.set_fill_color(Color::white);
    win.attach(rect8);

    column=0;
    ++row;
    */

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < rows*columns; i++) {
        if (column >= columns) {
            column = 0;
            ++row;
        }
        rects.push_back(new Rectangle{Point{start_x+column*size, start_y+row*size}, size, size});
        
        if (i%2!=0) { 
            rects[i].set_fill_color(Color::white);
        }
        else rects[i].set_fill_color(Color::red);
        
        win.attach(rects[i]);
        ++column;
    }


    win.wait_for_button();

}
