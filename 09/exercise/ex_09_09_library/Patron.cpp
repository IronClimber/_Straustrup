#include "Patron.h"

using namespace std;

Patron::Patron(void) : id_{0}, amount_{0}, paid_{false} { }

bool operator==(const Patron& a, const Patron& b) {
    if (a.id() == b.id()) { return true; }
    return false;
}

ostream& operator<<(ostream& os, const Patron& patron) {
    return os<<"("<<patron.id()<<", "
             <<patron.name()<<", "
             <<patron.amount()<<")";
}

Patron get_patron(void) {
    unsigned int id;        
    cout<<"ID: ";
    cin>>id;
    string name;
    cout<<"Name: ";
    cin>>name;
    double amount;
    cout<<"Amount: ";
    cin>>amount;
    return Patron(name, id, amount);
}
