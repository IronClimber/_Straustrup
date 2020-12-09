#ifndef LIB_13_H
#define LIB_13_H

#include "Graph.h"
#include <iostream>
#include <math.h>

namespace Graph_lib {

struct Regular_polygon : Polygon {

    Regular_polygon(Point p, int nn, int rr) 
                        : r{rr}, n{nn} {
        double a = 0;
        if (n >= 3) {
            for (int i = 0; i < n; ++i) {
              add(Point{p.x+int(r*cos(a)), p.y-int(r*sin(a))});
              a += 2*M_PI/n;
            }
        }
    }

private:
    int r;
    int n;

};

struct Regular_hexagon : Polygon {
    
    Regular_hexagon(Point p, int rr) : r{rr} {
        add(Point{p.x-rr, p.y});
        add(Point{p.x-int(rr/2),p.y+int(rr*0.866)});
        add(Point{p.x+int(rr/2),p.y+int(rr*0.866)});
        add(Point{p.x+rr, p.y});
        add(Point{p.x+int(rr/2),p.y-int(rr*0.866)});
        add(Point{p.x-int(rr/2),p.y-int(rr*0.866)});
    }

    //void draw_lines() const;

private:
    int r;    

};


struct Arc : Shape {

    Arc(Point p, int ww, int hh, double s, double f) 
        : w{ww}, h{hh}, a1{s}, a2{f}  {

        add(Point{p.x-ww, p.y-hh});

    }

    void draw_lines() const;

private:
    int w;
    int h;
    double a1;
    double a2;

};

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

	int height() const { return h; }
	int width() const { return w; }

private:
    int w;
    int h;
    int r;

};

struct Arrow : Shape {
    Arrow(Point p1, Point p2);

    void draw_lines() const;

};

//Or better use existing classes?
/*
struct TextBox : Shape {
    TextBox(Point p, int ww, int hh, const string& s)
            : w{ww}, h{hh}, lab{s} { add(p); }

    void draw_lines() const;


private:
    string lab;
    int w;
    int h;

};
*/

struct RectBox : Shape {
    RectBox(Point p, int ww, int hh);
    void draw_lines() const;
    void set_color(Color c);
    void set_fill_color(uchar rr, uchar gg, uchar bb);

    Text lab;
    Rectangle rect;
};

struct TextBox : Shape {
    TextBox(Point p, int ww, int hh, const string& s);
    
    void draw_lines() const;

    Point center() const { 
        return Point{ point(0).x + int(box.width()/2), point(0).y + int(box.height()/2) }; 
    }

    void set_color(Color c);
    void move(int dx, int dy);

    Point n() const {
        return Point{ point(0).x, point(0).y - int(box.height()/2)};
    }

    Point e() const;
    Point s() const {
        return Point{ point(0).x, point(0).y + int(box.height()/2) };
    }
    Point w() const;
    Point ne() const;
    Point nw() const;
    Point se() const;
    Point sw() const;

    Text lab;
    Box box;

};

}

#endif // LIB_13_H
