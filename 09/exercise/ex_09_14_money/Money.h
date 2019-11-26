#ifndef MONEY_H
#define MONEY_H

class Money {
public:
    Money(void) : cent{0} {}
    Money(double amount);
    void set(double amount);
    double get() { return double(cent)/100; }
private:
    long cent;
    long cents(double amount);
};

#endif /* MONEY_H */