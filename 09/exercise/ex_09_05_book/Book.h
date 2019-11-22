#include <iostream>
#include "Chrono.h"

/*
struct ISBN {
	unsigned int first;
	unsigned int second;
	unsigned int third;
	char forth;
};
*/

class Book {
private:
	class Invalid { };
	std::string isbn_;
	std::string name_;
	std::string author_;
	Chrono::Date reg_;
	bool exist_;
public:
	Book(std::string isbn, std::string name, std::string author);	
	std::string isbn(void) const { return isbn_; }
	std::string name(void) const { return name_; }
	std::string author(void) const { return author_; }
	Chrono::Date reg(void) const { return reg_; }
	bool is_here() { return exist_; }
};

bool check_isbn(std::string);

