#include <iostream>
#include "Link.h"


void Link::print_all(const std::string& str) {
  	std::cout << std::endl << "-----------------------------" << std::endl;
  	std::cout << str << ":" << std::endl;
	if (this == nullptr) {
		std::cout << "Empty" << std::endl;
	}
	else {
		Link* p = root();
		while (p) {
			p->print();
			std::cout << std::endl;
			p = p->next();
		}
	}
	std::cout << "-----------------------------" << std::endl;
	return;
}

void Link::print_all() {
  	std::cout << std::endl << "-----------------------------" << std::endl;
  	std::cout << "Print all:" << std::endl;
	if (this == nullptr) {
		std::cout << "Empty" << std::endl;
	}
	else {
		Link* p = root();
		while (p) {
			p->print();
			std::cout << std::endl;
			p = p->next();
		}
	}
	std::cout << "-----------------------------" << std::endl;
	return;
}


Link* Link::print() {
	//Program work wrong until this block -> Segmentation error
	//Compiler make some optimization
	if (this == nullptr) {
		std::cout << "Empty";
		return this;
	}
	std::cout << *god 
			  << " (p:" << ((prev != nullptr) ? *(prev->god) : *(new God{"Empty"})) 
			  << ", s:" << ((succ != nullptr) ? *(succ->god) : *(new God{"Empty"}))
			  << ")";
	return succ;

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
Link* Link::root() {
	if (this == nullptr) return nullptr;
	Link* p = this;
	while(p->prev) { p=p->prev; }
	return p;
}

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

Link* Link::add_ordered(Link* n) {
//	std::cout << "Add ordered god ";
//    n->print();
//	std::cout << std::endl;
	if (n==nullptr) return this;
	if (this==nullptr) return n;

	Link* p = this;

	while (n->god->name>p->god->name) {
		if (p->next() == nullptr) {return p->add(n);}
		p = p->next();
	}
	while (n->god->name<p->god->name) {
		if (p->previous() == nullptr) {return p->insert(n);}
		p = p->previous();
	}
    return p->add(n);

}

Link* Link::erase() {

    if (this==nullptr) return nullptr;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;

	//Dont work without it
	Link* t = succ;
	prev = nullptr;
	succ = nullptr;
	return t;

}

Link* Link::find(const std::string& s) {
	Link* p = this;
	while(p) {
		if (p->god->name == s) return p;
		p = p->next();
	}

	return nullptr;

}

const Link* Link::find(const std::string& s) const {
	const Link* p = this;
	while (p) {
		if (p->god->name == s) return p;
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
