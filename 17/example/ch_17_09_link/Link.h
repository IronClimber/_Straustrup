#ifndef LINK_H_
#define LINK_H_

#include <string>

struct Link {

	std::string value;
	Link* prev; // предыдущий, previous
	Link* succ; // следующий, succeeding
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value{v}, prev{p}, succ{s} {}

    void print();

};

Link* insert(Link* p, Link* n);

#endif /* Link.h */
