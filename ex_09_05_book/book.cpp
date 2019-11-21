#include <iostream>
#include "book.h"
#include "Date.h"

using namespace std;

Book::Book(string isbn, string name, 				   	  			   string author) {
	if (!check_isbn(isbn)) throw Invalid { };
	isbn_ = isbn;
	name_ = name;
	author_ = author;
	exist_ = true;
	reg_ = Date();
}

bool check_isbn(string) {
	
}