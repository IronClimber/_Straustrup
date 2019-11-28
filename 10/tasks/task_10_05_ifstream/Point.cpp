#include <iostream>
#include "Point.h"

using namespace std;

istream& operator>>(istream& is, Point& p) {
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) { return is; }
    if (ch1!='(' || ch2!=',' || ch3!=')') {
        is.clear(ios_base::failbit);
        return is;
    }

    p = Point{x,y};
    return is;
}

ostream& operator<<(ostream& os, const Point& p);
