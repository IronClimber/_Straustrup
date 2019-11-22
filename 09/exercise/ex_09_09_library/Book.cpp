#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

/* Genre */
ostream& operator<<(ostream& os, const Genre& g) {   
    string output;
    switch (g) {
    case Genre::Fiction:
        output = "Fiction";
        break;
    case Genre::Prose:
        output = "Prose";
        break;
    case Genre::Periodical:
        output = "Periodical";
        break;
    case Genre::Biography:
        output = "Biography";
        break;
    case Genre::Children:
        output = "Children";
        break;
    default:
        output = "Undefine";
    }
    return os << output;
}

istream& operator>>(istream& is, Genre& g) {
    string input;
    cin>>input;
    if (input=="Fiction") {
        g=Genre::Fiction;
    }
    else if (input=="Prose") {
        g=Genre::Prose;
    }
    else if (input=="Periodical") {
        g=Genre::Periodical;
    }
    else if (input=="Biography") {
        g=Genre::Biography;
    }
    else if (input=="Children") {
        g=Genre::Children;
    }
    else {
        is.clear(std::ios_base::failbit); //set error bit
        return is;        
    }
    return is;    
}

/* Book */
Book::Book(void)
    : genre_{Genre::Undefine}, exist_{true} {
    reg_ = Chrono::Date();
}

Book::Book(string isbn, string name, string author, Genre genre) {
	if (!check_isbn(isbn)) throw Invalid { };
	isbn_ = isbn;
	name_ = name;
	author_ = author;
	exist_ = true;
	reg_ = Chrono::Date();
    genre_ = genre;
}

void Book::set_genre(Genre g) {
    genre_ = g;
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

bool operator==(const Book& a, const Book& b) {
    if (a.isbn() == b.isbn()) { return true; }
    return false;
}

bool operator!=(const Book& a, const Book& b) {
    if (a.isbn() != b.isbn()) { return true; }
    return false;
}

ostream& operator<<(ostream& os, const Book& book) {

    //string here;
    //if (!book.is_here()) { here = " not"; }

    /*
    return os<<"ISBN: "<<book.isbn()<<endl
             <<"Book: "<<book.name()<<endl
             <<"Author: "<<book.author()<<endl
             <<"The book are"<<here<<" here"<<endl
             <<"Date of regestration: "<<book.reg()<<endl;
    */

    return os<<"("<<book.isbn()<<", "
             <<book.name()<<", "
             <<book.author()<<", "
             <<book.genre()<<")";

}

Book get_book(void) {
    string isbn;        
    cout<<"ISBN: ";
    cin>>isbn;
    string author;
    cout<<"Author: ";
    cin>>author;
    string name;
    cout<<"Name: ";
    cin>>name;
    Genre genre;
    cout<<"Genre: ";
    cin>>genre;
    return Book(isbn, name, author, genre);
}
