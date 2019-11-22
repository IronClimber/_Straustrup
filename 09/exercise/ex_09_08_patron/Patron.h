#include <iostream>

class Patron {
private:
    std::string name_;
    unsigned int id_;
    double amount_;
    bool paid_;
public:
    Patron(std::string n, unsigned int i, double a) 
        : name_{n}, id_{i}, amount_{a}, paid_{true} { }
    std::string name() const { return name_; }
    unsigned int id() const { return id_; }
    double amount() const { return amount_; }
    bool is_paid() const { return paid_; }
    void set_amount(double a) { amount_ = a; }
};
