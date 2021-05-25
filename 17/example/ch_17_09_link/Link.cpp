#include <iostream>
#include "Link.h"

void Link::print() {
	std::cout << value; // << std::endl;
    if (succ == nullptr) { 
		std::cout << std::endl;
		return;
	}
	else {
		std::cout << " -> ";
	}
	this->succ->print();
}

/* insert n before p */
Link* insert(Link* p, Link* n) {

	if (n==nullptr) return p;
	if (p==nullptr) return n;

    //connect new Link with neithbors
	n->succ = p;
	if (p->prev) p->prev->succ = n;

	n->prev = p->prev;
    p->prev = n;

	return n;
}
