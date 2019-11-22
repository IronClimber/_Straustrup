#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    cout<<"Create book:"<<endl;
    Book book{"323-234-234-J", "Martin Eden", "Jack London", Genre::Biography};
    cout<<book<<endl;
    cout<<int(book.genre())<<endl;
}
