#include <iostream>
#include "Chrono.h"

using namespace std;

int main() {

    Chrono::Date date{10001};
    cout<<"Days: "<<date.days()<<" "<<date<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    cout<<"Current month: "<<int(date.month())<<endl;
    cout<<"Current day: "<<date.day()<<endl<<endl;

    //date.add_day(10000);
    date.add_year(10);//98
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    cout<<"Current month: "<<int(date.month())<<endl;
    cout<<"Current day: "<<date.day()<<endl<<endl;

    /*
    date.add_year(1);//99
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//00
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//01
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//02
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//03
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//04
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//05
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//06
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    date.add_year(1);//07
    cout<<"Days: "<<date.days()<<endl;
    cout<<"Current year: "<<date.year()<<endl;
    */

   Chrono::Date new_date{2007, Chrono::Month::may, 19}; 
    //new_date.add_year(10);
    cout<<"Days: "<<new_date.days()<<endl;
    cout<<"Current year: "<<new_date.year()<<endl;
    cout<<"Current month: "<<int(new_date.month())<<endl;
    cout<<"Current day: "<<new_date.day()<<endl;

    return 0;

}
