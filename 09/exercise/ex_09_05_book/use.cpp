#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    cout<<"Create book:"<<endl;
    Book book{"323-234-234-J", "Martin Eden", "Jack London"};
    cout<<"ISBN: "<<book.isbn()<<endl;
    cout<<"Book: "<<book.name()<<endl;
    cout<<"Author: "<<book.author()<<endl;
    string here;
    if (!book.is_here()) {
        here = " not";
    }
    cout<<"The book are"<<here<<" here"<<endl;
    cout<<"Date of regestration: "<<book.reg()<<endl;
}
