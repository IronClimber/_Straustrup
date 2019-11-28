#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void error(string str) {
    throw runtime_error(str);
}

struct Reading {
    int hour;
    double temperature;
};

int main() {

    ofstream ost{"raw_temps.txt"};

    vector<Reading> temps;
    temps.push_back(Reading{0, -5.4});
    temps.push_back(Reading{1, -5.6});
    temps.push_back(Reading{2, -5.7});
    temps.push_back(Reading{3, -7.0});
    temps.push_back(Reading{4, -8.1});
    temps.push_back(Reading{5, -8.3});
    temps.push_back(Reading{6, -7.5});
    temps.push_back(Reading{7, -5.2});
    temps.push_back(Reading{8, -4.0});
    temps.push_back(Reading{9, -3.2});
    temps.push_back(Reading{10, -2.1});
    temps.push_back(Reading{11, -0.2});
    temps.push_back(Reading{12, 1.2});
    temps.push_back(Reading{13, 3.2});
    temps.push_back(Reading{14, 3.7});
    temps.push_back(Reading{15, 3.8});
    temps.push_back(Reading{16, 3.4});
    temps.push_back(Reading{17, 2.1});
    temps.push_back(Reading{18, 1.4});
    temps.push_back(Reading{19, 0.1});
    temps.push_back(Reading{20, -0.8});
    temps.push_back(Reading{21, -2.2});
    temps.push_back(Reading{22, -3.1});
    temps.push_back(Reading{23, -4.5});
    temps.push_back(Reading{24, -5.1});
    temps.push_back(Reading{25, -6.0});
    temps.push_back(Reading{26, 3.3});
    temps.push_back(Reading{27, 3.5});
    temps.push_back(Reading{28, 3.82});
    temps.push_back(Reading{29, 2.5});
    temps.push_back(Reading{30, 6.4});
    temps.push_back(Reading{31, 2.3});
    temps.push_back(Reading{32, 4.2});
    temps.push_back(Reading{33, 6.5});
    temps.push_back(Reading{34, 7.6});
    temps.push_back(Reading{35, 6.5});
    temps.push_back(Reading{36, 4.5});
    temps.push_back(Reading{37, 3.2});
    temps.push_back(Reading{38, 2.3});
    temps.push_back(Reading{39, 1.2});

    for (Reading t : temps) {
        ost << t.hour << " " << t.temperature << endl;
    }

    cout << "File created" << endl;    

    ost.close();

    return 0;
}

