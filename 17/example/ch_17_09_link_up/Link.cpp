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

/* insert n after p */
Link* add(Link* p, Link* n) {

	if (n==nullptr) return p;
	if (p==nullptr) return n;

    //connect new Link with neithbors
	n->prev = p;
	if (p->succ) p->succ->prev = n;

	n->succ = p->succ;
    p->succ = n;

	return n;
}

Link* erase(Link* p) {

    if (p==nullptr) return nullptr;
	if (p->succ) p->succ->prev = p->prev;
	if (p->prev) p->prev->succ = p->succ;
	return p->succ;

}

Link* find(Link* p, const std::string& s) {

	while(p) {
		if (p->value == s) return p;
		p = p->succ;
	}

	return nullptr;

}

Link* advance(Link* p, int n) {

	if (p==nullptr) return nullptr;
	if (n>0) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n<0) {
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;

}
