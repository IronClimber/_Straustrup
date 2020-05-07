#include "Simple_window.h"
#include "Graph.h"
#include <iostream>


using namespace Graph_lib;

struct Box : Shape {

    Box(Point p, int ww, int hh, int rr) 
        : w{ww}, h{hh}, r{rr} {

        if (h<(r+r) || w<(r+r)) error("length or width less then double radius");

        add(p);
        add(Point{p.x,     p.y+r  });
        add(Point{p.x,     p.y+h-r});
        add(Point{p.x+r,   p.y+h  });
        add(Point{p.x+w-r, p.y+h  });
        add(Point{p.x+w,   p.y+h-r});
        add(Point{p.x+w,   p.y+r  });
        add(Point{p.x+w-r, p.y    });
        add(Point{p.x+r,   p.y    });
        add(Point{p.x+r,   p.y+r  });
        add(Point{p.x+r,   p.y+h-r});
        add(Point{p.x+w-r, p.y+h-r});
        add(Point{p.x+w-r, p.y+r  });
    }

    void draw_lines() const;

private:
    int w;
    int h;
    int r;

};

void Box::draw_lines() const {
    if (color().visibility()) {
        for (int i = 1; i < 9; i+=2) {
            fl_line(point(i).x,point(i).y,point(i+1).x,point(i+1).y);            
        }
        for (int i = 0; i < 4; ++i) {
            fl_arc(point(9+i).x-r,point(9+i).y-r,r+r,r+r,90+i*90,180+i*90);
        }
    }
}



int main() {

    Simple_window win{Point{100,100}, 600, 400, "Exercise 13.02 - Box"};

    Box box{Point{100,100},400,200,30};
    box.set_color(Color::red);
    
    win.attach(box);

    win.wait_for_button();

}
