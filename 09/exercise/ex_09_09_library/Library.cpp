#include <iostream>
#include "Library.h"

using namespace std;

void Library::add_book(Book b) {
    for (Book bb : book) {
        if (b == bb) {
            cout<<"Error: This book is already in the library!"<<endl;
            return;
        }
    }
    book.push_back(b);
    cout<<b<<endl
        <<"Book successfully added to the library."<<endl;
}

void Library::add_patron(Patron p) {
    for (Patron pp : patron) {
        if (p == pp) {
            cout<<"Error: This patron is already added!"<<endl;
            return;
        } 
    }
    patron.push_back(p);
    cout<<p<<endl
        <<"Patron succesfully added to data base."<<endl;
}
