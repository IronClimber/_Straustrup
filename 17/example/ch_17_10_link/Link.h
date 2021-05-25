#ifndef LINK_H_
#define LINK_H_

#include <string>

struct Link {
public:
	std::string value;
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	//const Link* find(const std::string& s) const;
	Link* advance(int n);

	Link* next() const { return succ; }
	Link* previous() const { return prev; }

    void print();
private:

	Link* prev; // предыдущий, previous
	Link* succ; // следующий, succeeding
    
};

#endif /* Link.h */
