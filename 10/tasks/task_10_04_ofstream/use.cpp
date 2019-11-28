#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"

using namespace std;

constexpr int number_of_points = 7;

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
    vector<Point> original_points;
    //Point p{5, 6};
    //cout << "(" << p.x << "," << p.y << ")\n";
    
    for (Point p; cin>>p;) {
        original_points.push_back(p);
        cout << "(" << p.x << "," << p.y << ") ADDED.\n";
        if (original_points.size()>=number_of_points) { break; }        
    }
    
    cout << "Please enter output file name: ";
    string oname;
    cin >> oname;my
    ofstream ost {oname};
    if (!ost) error("cant open output file ", oname);

    cout<<"Original points to file:"<<oname<<endl;
    for (Point p : original_points) {
        ost << '(' << p.x << ',' << p.y << ")\n";
    }

    return 0;
}
