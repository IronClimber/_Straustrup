#include "iostream"
#include "Money.h"

Money::Money(double amount) {
    cent = cents(amount);
}

void Money::set(double amount) {
    cent = cents(amount);
}

long Money::cents(double amount) {
    double value = amount*100;
    if(amount-long(amount)<0.5) { return (long(value)); }
    return (long(value))+1;
}
//std::istream operator