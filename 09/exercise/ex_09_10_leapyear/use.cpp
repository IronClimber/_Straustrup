#include <iostream>
#include "Chrono.h"

using namespace std;

int main() {
    Chrono::Date date{1988, Chrono::Month::aug, 17};
    cout<<"Current date: "<<date<<endl;
    string leap = Chrono::leapyear(date.year())?"leap":"not leap";
    cout<<date.year()<<" is "<<leap<<" year"<<endl;
    return 0;
}
