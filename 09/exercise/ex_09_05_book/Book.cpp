#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

Book::Book(string isbn, string name, string author) {
	if (!check_isbn(isbn)) throw Invalid { };
	isbn_ = isbn;
	name_ = name;
	author_ = author;
	exist_ = true;
	reg_ = Chrono::Date();
}

//Now proccess whole string. Process step by step?
bool check_isbn(string isbn) {

    int counter = 0;
    vector<string> arr;
    string delim("-");

    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while((next = isbn.find(delim, prev)) != string::npos){
        string tmp = isbn.substr(prev, next-prev);
        arr.push_back(isbn.substr(prev, next-prev));
        prev = next + delta;
        counter++;
    }

    string tmp = isbn.substr(prev);
    arr.push_back(isbn.substr(prev));
    //cout<<"Counter: "<<counter<<endl;

    if (counter==3) { return true; }
    return false;
    
}
