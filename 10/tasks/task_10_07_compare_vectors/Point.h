#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    int x;
    int y;
};

std::istream& operator>>(std::istream& is, Point& p);
std::ostream& operator<<(std::ostream& os, const Point& p);

bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);

#endif /* POINT_H */
