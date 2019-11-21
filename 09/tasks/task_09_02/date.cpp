#include <iostream>

using namespace std;

struct Date {
    int y, m, d;
    Date(int y, int m, int d);

    void add_day(int n);
};

Date::Date(int yy, int mm, int dd) {
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
}
    
ostream& operator<<(ostream& os, const Date& d) {
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}


int main() {

    Date today{1963, 05, 19};
    cout << today << endl;
    //init_day(today, 1963, 05, 19);
    Date tomorrow{0,0,0};
    tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
