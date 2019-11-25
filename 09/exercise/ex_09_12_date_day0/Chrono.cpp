#include <iostream>
#include "Chrono.h"

namespace Chrono {

Month operator++(Month& m) {
    if (m != Month::dec) {
        m = static_cast<Month>(static_cast<int>(m)+1); 
    }
    else  {m = Month::jan; }
    return m;
}

Date::Date(int yy, Month mm, int dd) {

    if (!is_date(yy,mm,dd) || yy<1970) throw Invalid{};
    d = dd;

    Month m = Month::jan;
    int y = 1970;

    //Add month days
    while(m!=mm) {
        int days_in_month = 31;
        switch (m) {
        case Month::feb:
            days_in_month = leapyear(yy)?29:28;
            break;
        case Month::apr: case Month::jun:
        case Month::sep: case Month::nov:
            days_in_month = 30;
            break;
        }
        d+=days_in_month;
        ++m;
    }
    
    //Add year days
    while(y!=yy) {
        d+=leapyear(y)?366:365;
        ++y;
    }
}

const Date& default_date() {
    static Date dd {1970,Month::jan,1};
    return dd;
}

Date::Date() : d{1} { }

Date::Date(long int dd) : d{dd} { }

int Date::day() const {
    long int days = 0;
    Month month = Month::jan;
    int year = 1970;
    int day = d;
    
    while(days<d) {

        int feb_days = leapyear(year)?29:28;
        //std::cout<<"Feb: "<<feb_days<<std::endl;

        while(days<d) {
            
            //std::cout<<day<<days<<std::endl;
            int days_in_month = 31;
            switch (month) {
            case Month::feb:
                days_in_month = feb_days;
                break;
            case Month::apr: case Month::jun:
            case Month::sep: case Month::nov:
                days_in_month = 30;
                break;
            }
            if(day>days_in_month) {
                day-=days_in_month;
                days+=days_in_month;
                ++month;
            }
            else { return day; }
            if (month==Month::jan) { break; }
        }
        if (days<d) { ++year; }        
    }
}

Month Date::month() const {
    long int days = 0;
    Month month = Month::jan;
    int year = 1970;
    int day = d;
    
    while(days<d) {

        int feb_days = 28;
        if (year%4==0) { feb_days = 29; }
        
        while(days<d) {
            
            //std::cout<<day<<days<<std::endl;
            int days_in_month = 31;
            switch (month) {
            case Month::feb:
                days_in_month = feb_days;
                break;
            case Month::apr: case Month::jun:
            case Month::sep: case Month::nov:
                days_in_month = 30;
                break;
            }
            if(day>days_in_month) {
                day-=days_in_month;
                days+=days_in_month;
                ++month;
            }
            else { return month; }
            if (month==Month::jan) { break; }
        }
        if (days<d) { ++year; }        
    }
}

int Date::year() const {
    int days = 0;
    int year = 1970;
    
    while (days<d) {
        days+=leapyear(year)?366:365;
        if (days<d) { ++year; }
    }
    //std::cout<<"Year debug: "<<year<<std::endl;
    return year;   
}

void Date::add_day(int n) {
    //withot check if date less than zero in result
    d += n;
}

void Date::add_month(int n) {
    //...
}

void Date::add_year(int n) {
    int year = this->year();
    for (int i = 0; i < n; ++i) {
        d+=leapyear(year)?366:365;
        ++year;
    }
    /*if (m==Month::feb && d==29 && !leapyear(y+n)) {
        m = Month::mar;
        d = 1;
    }
    y+=n;*/
}

bool is_date(int y, Month m, int d) {
    //Think about correct year
    if (d<=0) return false;
    if (m<Month::jan || Month::dec<m) return false;

    int days_in_month = 31;
    switch (m) {
    case Month::feb:
        days_in_month = (leapyear(y))?29:28;
        break;
    case Month::apr: case Month::jun:
    case Month::sep: case Month::nov:
        days_in_month = 30;
        break;
    }
    if (days_in_month<d) return false;
    return true;
}

bool leapyear(int y) {
    if(y%4==0) {return true;}
    return false;
    //ex_10
}

bool operator==(const Date& a, const Date& b) {
    return a.days() == b.days();
}

bool operator!=(const Date& a, const Date& b) {
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is; //What is it?
    if (ch1 != '(' || ch2 != ',' ||
        ch3 != ',' || ch4 != ')') {
        is.clear(std::ios_base::failbit); //set error bit
        return is;
    }
    dd = Date(y, Month(m), d);
    return is;
}

enum class Day {
    sunday, monday, tuesday, wednesday,
    thursday, friday, saturday
};

Day day_of_week(const Date& d) {
    // ...
}

Date next_Sunday(const Date& d) {
    // ...
}

Date next_weekday(const Date& d) {
    // ...
}

} // Chrono
