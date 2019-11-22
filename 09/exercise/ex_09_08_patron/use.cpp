#include <iostream>
#include "Book.h"
#include "Patron.h"

using namespace std;

int main() {
    cout<<"Create book:"<<endl;
    Patron patron{"Stepan", 27, 57.5};
    cout<<patron.id()<<" "<<patron.name()<<endl;
    Book book{"323-234-234-J", "Martin Eden", "Jack London", Genre::Biography};
    cout<<book<<endl;
    cout<<int(book.genre())<<endl;
}
