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
	next()->print();
}


/* insert n before p */
Link* Link::insert(Link* n) {

	if (n==nullptr) return this;
	if (this==nullptr) return n;

    //connect new Link with neithbors
	n->succ = this;
	if (prev) prev->succ = n;

	n->prev = prev;
    prev = n;

	return n;
}

/* insert n after p */
Link* Link::add(Link* n) {

	if (n==nullptr) return this;
	if (this==nullptr) return n;

    //connect new Link with neithbors
	n->prev = this;
	if (succ) succ->prev = n;

	n->succ = succ;
    succ = n;

	return n;
}

Link* Link::erase() {

    if (this==nullptr) return nullptr;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;

}

Link* Link::find(const std::string& s) {
	Link* p = this;
	while(p) {
		if (p->value == s) return p;
		p = p->next();
	}

	return nullptr;

}

Link* Link::advance(int n) {

	Link* p;
	if (p==nullptr) return nullptr;
	if (n>0) {
		while (n--) {
			if (p->next() == nullptr) return nullptr;
			p = p->next();
		}
	}
	else if (n<0) {
		while (n++) {
			if (p->previous() == nullptr) return nullptr;
			p = p->previous();
		}
	}
	return p;

}
