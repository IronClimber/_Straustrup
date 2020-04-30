#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace Graph_lib;

Simple_window win{Point{100,100}, 400, 400, "Excersice 12.13 - SuperEllipse Color"};
Vector_ref<Line> line;

int sgn(double x) {
    if (x>0) return 1;
    else if (x<0) return -1;
    else return 0;
}

void draw_star(double a, double b, double m, double n, int N) {

    Point center{200,200};
    int scale = 150;
    Point current_point, last_point;
    vector<Point> point;

    for (int i = 0; i < N; ++i) {
        double theta = 2*i*M_PI/N;
        double x = pow(abs(cos(theta)),2/m)*a*sgn(cos(theta));
        double y = pow(abs(sin(theta)),2/n)*b*sgn(sin(theta));
        point.push_back(Point{int(x*scale)+center.x,int(y*scale)+center.y});
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i!=j) {
                
                line.push_back(new Line {point[i], point[j]});
                unsigned int clr = narrow_cast<unsigned int>(randint(1,14));
                line[line.size()-1].set_color(Color{clr});
                win.attach(line[line.size()-1]);

            }
        }
    }

}

int main() {

    draw_star(1,1.3,2,2,24);
    win.wait_for_button();

}
