#include <iostream>

using namespace std;

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
}; 

class Date {
private:
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    Month month() const { return m; }
    int day() const  { return d; }
    int year() const { return y; }
};

Date::Date(int yy, Month mm, int dd) {
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
}
    
ostream& operator<<(ostream& os, const Date& d) {
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}


int main() {

    Date today{1963, Month::may, 19};
    //today.d = 3;
    cout << today << endl;
    //init_day(today, 1963, 05, 19);
    Date tomorrow{0,Month::jan,0};
    tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
