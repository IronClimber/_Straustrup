#include <iostream>
#include "Chrono.h"

enum class Genre {
    Fiction, Prose, Periodical, Biography, Children
};

class Book {
private:
	class Invalid { };
	std::string isbn_;
	std::string name_;
	std::string author_;
	Chrono::Date reg_;
	bool exist_;
    Genre genre_;
public:
	Book(std::string isbn, std::string name, std::string author, Genre genre);	
	std::string isbn(void) const { return isbn_; }
	std::string name(void) const { return name_; }
	std::string author(void) const { return author_; }
	Chrono::Date reg(void) const { return reg_; }
	bool is_here() const { return exist_; }
    Genre genre(void) const { return genre_; }
    void set_genre(Genre g);
};

bool check_isbn(std::string);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
std::ostream& operator<<(std::ostream& os, const Book& book);
