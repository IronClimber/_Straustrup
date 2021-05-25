#ifndef LINK_H_
#define LINK_H_

#include <string>
#include "God.h"

struct Link {
public:
	God* god;
	Link() : prev{nullptr}, succ{nullptr} {}
	Link(God* g, Link* p = nullptr, Link* s = nullptr)
		: god{g}, prev{p}, succ{s} {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* add_ordered(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const;
	Link* advance(int n);

	Link* root();
	Link* next() const { return succ; }
	Link* previous() const { return prev; }

    Link* print();
	void print_all();
	void print_all(const std::string& str);
private:

	Link* prev; // предыдущий, previous
	Link* succ; // следующий, succeeding
    
};



#endif /* Link.h */
