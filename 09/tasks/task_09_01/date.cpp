#include <iostream>

using namespace std;

struct Date {
    int y;
    int m;
    int d;
};


void init_day(Date& dd, int y, int m,  int d) {
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n) {
    dd.d += n;
}
    
ostream& operator<<(ostream& os, const Date& d) {
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}


int main() {

    Date today;
    init_day(today, 1963, 05, 19);
    Date tomorrow;
    tomorrow = today;
    add_day(tomorrow, 1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
