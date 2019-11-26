#include <iostream>
#include <vector>
#include "Money.h"

using namespace std;

vector<vector<double>> rate{{ 1,     24.06, 0.91  }, 
                            { 0.042, 1,     0.038 }, 
                            { 1.1,   26.51, 1     }}; 

Money::Money(Currency c, double amount) {
    cent = cents(amount);
    curr = c;
}

void Money::set(double amount) {
    cent = cents(amount);
}

long Money::cents(double amount) {
    double value = amount*100;
    if(amount-long(amount)<0.5) { return (long(value)); }
    return (long(value))+1;
}

void Money::convert(Currency c) {
    cent = cents(double(cent)/100*rate[int(curr)][int(c)]);
    curr = c;
}

istream& operator>>(istream& is, Money& m) {
    string currency;
    char symbol;
    while (is.get(symbol)) {
        if ((isdigit(symbol)) || symbol=='.') {
            is.putback(symbol);
            break;
        }
        currency+=symbol;
    }
    
    double value;
    Currency c;
    is>>value;
    
    if (!is) {return is; }
    if (currency=="USD") {
        c = Currency::USD;
    } 
    else if (currency=="EUR") {
        c = Currency::EUR;
    } 
    else if (currency=="UAH") {
        c = Currency::UAH;
    }
    else {
        is.clear(std::ios_base::failbit);
        return is ;
    }

    m = Money(c, value);

    return is;
}

ostream& operator<<(ostream& os, const Money& m) {
    string c;
    switch(m.currency()) {
    case Currency::USD:
        c = "USD";
        break;
    case Currency::UAH:
        c = "UAH";
        break;
    case Currency::EUR:
        c = "EUR";
        break;
    default:
        c = "Tugriki";
    }
    return os<<c<<m.get();
}
