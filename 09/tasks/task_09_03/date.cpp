#include <iostream>

using namespace std;

class Date {
    int y, m, d;
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month() const { return m; }
    int day() const  { return d; }
    int year() const { return y; }
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
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}


int main() {

    Date today{1963, 05, 19};
    //today.d = 3;
    cout << today << endl;
    //init_day(today, 1963, 05, 19);
    Date tomorrow{0,0,0};
    tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
