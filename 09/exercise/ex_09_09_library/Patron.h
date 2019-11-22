#ifndef PATRON_H
#define PATRON_H

#include <iostream>

class Patron {
private:
    std::string name_;
    unsigned int id_;
    double amount_;
    bool paid_;
public:
    Patron(void);
    Patron(std::string n, unsigned int i, double a) 
        : name_{n}, id_{i}, amount_{a}, paid_{false} { }
    std::string name() const { return name_; }
    unsigned int id() const { return id_; }
    double amount() const { return amount_; }
    bool is_paid() const { return paid_; }
    void set_amount(double a) { amount_ = a; }
};

bool operator==(const Patron& a, const Patron& b);
std::ostream& operator<<(std::ostream& os, const Patron& patron);

Patron get_patron(void);

#endif /* PATRON_H */
