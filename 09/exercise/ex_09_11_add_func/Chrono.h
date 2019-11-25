#ifndef CHRONO_H
#define CHRONO_H

#include <iostream>

namespace Chrono {
enum class Month {
    jan=1, feb, mar, apr, may, jun,
    jul, aug, sep, oct, nov, dec
};

class Date {
public:
    class Invalid { };
    Date(int y, Month m, int d);
    Date(); //Should be current date

    //Nonmodifying operations
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }

    //Modifying operations
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

private:
    int y;
    Month m;
    int d;
};

bool is_date(int y, Month m, int d);
bool leapyear(int y);
Day day_of_week(const Date& d);
Date next_Sunday(const Date& d);
Date next_weekday(const Date& d);
Date next_workday(const Date& d);
unsigned int week_of_year(int y);
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
bool operator>(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& dd);
} // Chrono

#endif /* CHRONO_H */
