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

/*
    vector<shared_ptr<Rectangle>> rects;
    //Rectangle rect{Point{start_x+column*size, start_y+row*size}, size, size};
    shared_ptr<Rectangle> p = make_shared<Rectangle> (Point{start_x+column*size, start_y+row*size}, size, size);
    rects.push_back(p);
    win.attach(rects[0]);*/
    /*for (int i = 0; i < rows*columns; i++) {
        if (column >= columns) {
            column = 0;
            ++row;
        }
        Rectangle rect{Point{start_x+column*size, start_y+row*size}, size, size};
        
        if (i%2==0) { 
            rect.set_fill_color(Color::white);
        }
        else rect.set_fill_color(Color::red);
        rects.push_back(rect);
        win.attach(rects[i]);
        ++column;
    }
*/

    win.wait_for_button();

}
