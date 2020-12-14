#include "lib_13.h"


namespace Graph_lib {

Star::Star(Point p, int nn, int rr_out, int rr_in) {
    if (nn<3) { error("Should be at least 3 points"); }
    n = nn;
    if (!(rr_out>10 && rr_in>5 && rr_out>rr_in)) {
        error("Wrong radius");
    }
    r_out = rr_out;
    r_in = rr_in;

    //add(Point{p.x,p.y-r_out});
    double angle{M_PI/2};
    //cout<<angle<<" "<<n<<" "<<r_out<<" "<<r_in<<endl;
    
    for(int i = 0; i < n; ++i) {
        angle -= M_PI/n;
        Point p1{p.x+int(r_in*cos(angle)), p.y-int(r_in*sin(angle))};
        //cout<<angle<<" "<<p1.x<<" "<<p1.y<< endl;
        add(p1);
        angle -=M_PI/n;
        Point p2{p.x+int(r_out*cos(angle)), p.y-int(r_out*sin(angle))};
        //cout<<angle<<" "<<p2.x<<" "<<p2.y<< endl;
        add(p2);
    }
}

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

//ToDo: process vertical lines
bool intersect(Point m1, Point n1, Point m2, Point n2) {    
    //cout << "Intersect" << endl;
    if (m1.x > n1.x) { swap(m1,n1); }
    if (m2.x > n2.x) { swap(m2,n2); }
    double k1, k2;
    if (m1.y == n1.y) { k1 = 0.0; }
    else { k1 = (n1.y-m1.y)/(n1.x-m1.x); }
    if (m2.y == n2.y) { k2 = 0.0; }
    else { k1 = (n2.y-m2.y)/(n2.x-m2.x); }
    if (k1 == k2) { return false; }
    double b1, b2;
    b1 = m1.y-k1*m1.x;
    b2 = m2.y-k2*m2.x;
    double x,y;
    x=(b2-b1)/(k1-k2);
    y=k1*x+b1;
    if (x>=m1.x && x<=n1.x && x>=m2.x && x<=n1.x) {
        return true;
    }
    return false;    
}

Poly::Poly(initializer_list<Point> lst) {

    for (auto p : lst) { add(p); }
/*
    if (lst.size() < 2) {
        cout << "It isn't poly." << endl;
    }

    vector<Point> pv;
    for (auto& p : lst) {
        pv.push_back(p);
    }

    add(pv[0]);
    add(pv[1]);
    add(pv[2]);

    if(number_of_points() > 2) {
        cout << "It's OK!" << endl;
    }
    else {
        cout << "It isn't poly." << endl;
    }

    for (int i = 3; i < pv.size(); ++i) {
        bool inter{false};
        for (int j = 0; j < i-2; ++j) {
            cout << i << "-" << i-1 << " "
                 << j << "-" << j+1 << ": ";
            if(intersect(pv[i],pv[i-1],pv[j],pv[j+1])) {
               cout << "intersect" << endl;
               inter = true;  
            }
            else {
                cout << "don't intersect" << endl;
            }
        }
        if (!inter) { add(pv[i]); }
        else { 
            cout << "Wrong point: " << i << endl; 
            break;
        }
    }
*/
}

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
