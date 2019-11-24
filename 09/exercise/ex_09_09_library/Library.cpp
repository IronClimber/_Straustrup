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

/* Use separate private functions to check for a book and patron.
   Which should return reference to an object. */

Book Library::get_book(std::string isbn) {
    for (Book bb : book) {
        if (bb.isbn() == isbn) { return bb; }
    }
    throw Invalid { };
}

Patron Library::get_patron(unsigned int id) {
    /* pp reference or value? */
    for (Patron pp : patron) {
        if (pp.id() == id) { return pp; }
    }
    throw Invalid { };
}

/* Use <isbn> to identify book, <id> to identify patron
   I need reference to object to get the data */
void Library::take_book(string isbn, unsigned int id) {
    cout<<"Transaction: "<<isbn<<"->"<<id<<"..."<<endl;
    //Is book exist?
    Book b;
    try {
        b = get_book(isbn);
    }
    catch (Invalid) {
        cout<<"There are no such book in the library."<<endl;
        return;
    }
    //Is patron exist?
    Patron p;
    try {
        p = get_patron(id);
    }
    catch (Invalid) {
        cout<<"There are no such user in the library."<<endl;
        return;
    }

    if (!p.is_paid()) {
        cout<<"User didn't paid "<<p.amount()<<"$"<<endl;
        return;
    }

    //Methods and constructor for structure?
    Transaction trans{b, p, Chrono::Date()};
    transaction.push_back(trans);
    cout<<"Transaction added: "
        <<transaction[0].book.name()<<"->"
        <<transaction[0].patron.name()<<" at "
        <<transaction[0].date
        <<endl;
}

vector<string> Library::get_debtors() {
    vector<string> debtor;
    for (Patron p : patron) {
        if (!p.is_paid()) { debtor.push_back(p.name()); }
    }
    return debtor;
}