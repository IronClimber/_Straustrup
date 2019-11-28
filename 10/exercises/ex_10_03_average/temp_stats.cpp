#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Reading {
    int hour;
    double temperature;
};

bool operator<(const Reading& a, const Reading& b) {
    return a.temperature<b.temperature;
}

int main() {

    ifstream ist{"raw_temps.txt"};

    vector<Reading> temps;
    int hour;
    double temperature;

    while (ist >> hour >> temperature) {
        if (hour >= 0 && hour <= 23) { 
            temps.push_back(Reading{hour, temperature});
            cout << hour << " " << temperature << endl;
        }
    }
    
    ist.close();

    double sum=0;
    for (Reading t : temps) {
        sum+=t.temperature;
    }
    double average = sum/temps.size();
    cout << "Average temperature: " << average << endl;    

    sort(temps.begin(), temps.end());

    for (Reading t : temps) {
        cout << t.hour << " " << t.temperature << endl;
    }    

    double median;
    if (temps.size()>0) {
        if (temps.size()%2 == 0) {
            median = (temps[temps.size()/2].temperature+temps[temps.size()/2-1].temperature)/2;
            cout << "Size %2==0: " << temps.size() << "; Median: " << median << endl;
        }
        else {
            median = temps[temps.size()/2].temperature;
            cout << "Size %2!=0: " << temps.size() << "; Median: " << median << endl;
        }
        cout << "Median of temperature: " << median << endl;
    } 
    else {
        cout << "Something wrong with median.";
    }
    
    

    return 0;
}

