#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include "Book.h"
#include "Patron.h"

struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date date;
};

class Library {
private:
    std::vector<Book> book;
    std::vector<Patron> patron;
    std::vector<Transaction> transaction;
public:
    void add_patron(Patron p);
    void add_book(Book b);
    void set_book_status(std::string isbn);
    void take_book(Book b, Patron p);
    void return_book(Book b);
    void get_debtors();
};


#endif /* LIBRARY_H */
