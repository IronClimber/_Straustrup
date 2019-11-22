#include <iostream>
#include "Book.h"
#include "Patron.h"
#include "Library.h"

using namespace std;

Library lib;

int main() {

    cout<<"<<<LIBRARY>>>"<<endl;

    Patron patron{"Stepan", 27, 57.5};
    Book book{"323-234-234-J", "Martin Eden", "Jack London", Genre::Biography};

    lib.add_book(book);
    lib.add_patron(patron);
    
    Book b = get_book();
    lib.add_book(b);

    Patron p = get_patron();
    lib.add_patron(p);
}
