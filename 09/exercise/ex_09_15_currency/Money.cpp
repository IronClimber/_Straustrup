#include <iostream>
#include <vector>
#include "Money.h"

std::vector<std::vector<double>> rate{{ 1,     24.06, 0.91  }, 
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