#include "lib_13.h"


namespace Graph_lib {


/*void Regular_hexagon::draw_lines() const {
    Closed_polyline::draw_lines();
}*/

void Arc::draw_lines() const {
    if (color().visibility()) {
        /* cout << point(0).x << " " << point(0).y<< " "
             << w+w<< " " << h+h<< " " 
            << a1<< " " << a2 << endl; */
        fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,w+w,h+h,a1,a2);
    }
}

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

Arrow::Arrow(Point p1, Point p2) { 

    add(p1);
    add(p2); 

    int length{15};
    double gamma{0.25};

    double alpha{atan2(p1.y-p2.y,p2.x-p1.x)};

    double betta_left{alpha-gamma};
    double betta_right{alpha+gamma};

    int dxl{int(length*cos(betta_left))};
    int dyl{int(length*sin(betta_left))};
    int dxr{int(length*cos(betta_right))};
    int dyr{int(length*sin(betta_right))};

    add(Point{p2.x-dxl, p2.y+dyl});
    add(Point{p2.x-dxr, p2.y+dyr});

}

void Arrow::draw_lines() const {
    if (color().visibility()) {
        fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
        fl_line(point(1).x, point(1).y, point(2).x, point(2).y);
        fl_line(point(1).x, point(1).y, point(3).x, point(3).y);
    }
}

/*
void TextBox::draw_lines() const {
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x, point(0).y, w, h);
        fl_color(color().as_int());
    }
    if (color().visibility()) {
        fl_color(color().as_int());
        fl_rect(point(0).x, point(0).y, w, h);
    }
    fl_draw(lab.c_str(), point(0).x+10, point(0).y+20);
}
*/

TextBox::TextBox(Point p, int ww, int hh, const string& s) :
    box{p, ww, hh, 5}, lab{Point{p.x+10, p.y+20}, s} { 
    add(Point{p.x+ww/2, p.y+hh/2});
}

void TextBox::set_color(Color c)
{   
    Shape::set_color(c);
	box.set_color(c);
	lab.set_color(c);
}

void TextBox::move(int dx, int dy)
{
	box.move(dx,dy);
	lab.move(dx,dy);
}

void TextBox::draw_lines() const {
    box.draw_lines();
    lab.draw_lines();   
}

RectBox::RectBox(Point p, int ww, int hh) : 
    rect{p,ww,hh}, lab{Point{p.x+5,p.y+15}, ""} {
        rect.set_fill_color(Color::white);
        lab.set_label("EEEEEE");
        add(p);
}

void RectBox::draw_lines() const {
    rect.draw_lines();
    lab.draw_lines();   
}

void RectBox::set_color(Color c)
{   
    rect.set_color(c);
	//lab.set_color(c);
}

void RectBox::set_fill_color(uchar rr, uchar gg, uchar bb)
{   
    
    rect.set_fill_color(fl_rgb_color(rr,gg,bb));
	//lab.set_color(c);
}

}
