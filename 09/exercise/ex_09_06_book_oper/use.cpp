#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    cout<<"Create book:"<<endl;
    Book book{"323-234-234-J", "Martin Eden", "Jack London"};
    cout<<book<<endl;
}
