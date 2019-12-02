#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Reading {
    int hour;
    double temperature;
};

int main() {

    ofstream ost{"raw_temps.txt"};

    vector<string> temps{"c45", "f23", "c23", "f2", "c12", "c-32", "f22", "c23",
                         "c-34.3", "c33.3", "f32", "c29", "c12", "f34.2", "f12",
                         "c45.2", "f-3", "f14", "c23.6" , "c13", "f45.4", "c10",
                         "c-32.3", "f33.3", "f12", "c9", "c-12", "f-4.2", "f14"};

    for (int i = 0; i < temps.size(); ++i) {
        ost << i << " " << temps[i] << endl;
    }

    cout << "File created" << endl;    

    ost.close();

    return 0;
}

