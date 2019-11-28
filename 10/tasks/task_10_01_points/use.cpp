#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

void error(string str) {
	throw runtime_error("Error: " + str);
}

void error(string str1, string str2) {
	throw runtime_error(str1 + str2);
}

int main() {
    /*
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist(iname);
    if (!ist) error("cant open input file ", name); 
    */
    vector<Point> points;
    Point p{5, 6};
    cout << "(" << p.x << "," << p.y << ")\n";
    /*
    for (Point p; ist>>p;) {
        points.push_back(p);
    }
    */

    return 0;
}
