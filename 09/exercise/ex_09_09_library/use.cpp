#include <iostream>
#include "Book.h"
#include "Patron.h"
#include "Library.h"

using namespace std;

Library lib;

int main() {

    cout<<"<<<LIBRARY>>>"<<endl;

    Patron patron_st{"Stepan", 27, 57.5};
    Patron patron_mr{"Maria", 37, 37.5};
    Patron patron_vo{"Volodymyr", 25, 54.5};
    Patron patron_el{"Elena", 273, 57.7};

    patron_vo.pay();

    Book book{"323-234-234-J", "Martin Eden", "Jack London", Genre::Biography};

    lib.add_book(book);
    lib.add_patron(patron_st);
    lib.add_patron(patron_mr);
    lib.add_patron(patron_vo);
    lib.add_patron(patron_el);

    /*
    Book b = create_book();
    lib.add_book(b);

    Patron p = create_patron();
    lib.add_patron(p);
    */

    lib.take_book("323-234-234-J", 27);

    cout<<"Debtors:"<<endl;
    vector<string> debtors = lib.get_debtors();
    for (string n : debtors) {
        cout<<"\t- "<<n<<endl;
    }
}
