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
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("cant open output file ", oname);

    cout<<"Original points to file:"<<oname<<endl;
    for (Point p : original_points) {
        ost << '(' << p.x << ',' << p.y << ")\n";
    }

    ost.close();
    
    string iname = oname;
    ifstream ist{iname};
    if (!ist) error("cant open input file ", iname); 

    vector<Point> processed_points;
    Point p;
    while (ist >> p) {
        processed_points.push_back(p);
    }

    if (original_points.size() == processed_points.size()) {
        cout<<"Original - Processed points:"<<endl;
        for (int i = 0; i < original_points.size(); ++i) {
            cout << original_points[i] << '-' << processed_points[i] << endl;
            if (original_points[i] != processed_points[i]) {
                cout << "Points are different." << endl;
                return 1;
            }
        }
        cout << "Vectors equal" << endl;
    }
    else {
        cout << "Something go wrong..." << endl;
        return 1;
    }
    return 0;
}
