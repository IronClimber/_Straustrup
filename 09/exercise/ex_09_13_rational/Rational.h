#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
    class Invalid { };
    Rational(int n, int d);
    double decimal() const; 
    int num() const { return numerator; }
    int den() const { return denominator; }
    operator double() const;
    Rational& operator=(const Rational& a);

private:
    int numerator;
    int denominator;
    void reduce(void);
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);

bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);

std::ostream& operator<<(std::ostream& os, const Rational& a);

#endif /* RATIONAL_H Rational.h */