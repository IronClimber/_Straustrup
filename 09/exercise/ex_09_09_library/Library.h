#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include "Book.h"
#include "Patron.h"

//Maybe should use reference to the book? or patron?
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
    class Invalid { };
    void add_patron(Patron p);
    void add_book(Book b);
    Book get_book(std::string isbn);
    Patron get_patron(unsigned int id);
    void set_book_status(std::string isbn);
    void take_book(std::string isbn, unsigned int id);
    void return_book(Book b);
    std::vector<std::string> get_debtors();
};


#endif /* LIBRARY_H */
