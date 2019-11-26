#include "Rational.h"

Rational::Rational(int n=0, int d=1) {
    if (d == 0) { throw Invalid { }; }
    numerator = n;
    denominator = d;
}

double Rational::decimal() const{ 
    return double(numerator)/denominator; 
}

Rational operator+(const Rational& a, const Rational& b) {
    int n = a.num()*b.den() + b.num()*a.den();
    int d = a.den()*b.den();
    return Rational(n,d);
}

Rational operator-(const Rational& a, const Rational& b) {
    int n = a.num()*b.den() - b.num()*a.den();
    int d = a.den()*b.den();
    return Rational(n,d);
}

Rational operator/(const Rational& a, const Rational& b) {
    int n = a.num()*b.den();
    int d = a.den()*b.num();
    return Rational(n,d);
}

Rational operator*(const Rational& a, const Rational& b) {
    int n = a.num()*b.num();
    int d = a.den()*b.den();
    return Rational(n,d);
}

Rational::operator double() const{
    return this->decimal();
}

//Why I need this? All works without it.
Rational& Rational::operator=(const Rational& a) {
    numerator = a.num();
    denominator = a.den();
    return *this;
}


bool operator==(const Rational& a, const Rational& b) {
    if (double(a) == double(b)) { return true; }
    return false;
}

bool operator!=(const Rational& a, const Rational& b) {
    if (double(a) != double(b)) { return true; }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Rational& a) {
    return os<<"("<<a.num()<<"/"<< a.den()<<")";
}
