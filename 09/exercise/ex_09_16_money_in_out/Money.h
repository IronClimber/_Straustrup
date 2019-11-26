#ifndef MONEY_H
#define MONEY_H

#include <iostream>

enum class Currency {
    USD, UAH, EUR
};

class Money {
public:
    Money(void) : cent{0}, curr{Currency::USD} {}
    Money(Currency c, double amount);
    void set(double amount);
    double get() const { return double(cent)/100; }
    Currency currency() const { return curr; }
    void convert(Currency c);
private:
    long cent;
    Currency curr; 
    long cents(double amount);
};

std::istream& operator>>(std::istream& is, Money& m);
std::ostream& operator<<(std::ostream& os, const Money& m);

#endif /* MONEY_H */