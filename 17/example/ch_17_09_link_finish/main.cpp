#include <iostream>
#include "Link.h"

int main() {

  Link* norse_gods = new Link{"Thor"};
  norse_gods = insert(norse_gods, new Link{"Odin"});
  norse_gods = insert(norse_gods, new Link{"Zeus"});
  norse_gods = insert(norse_gods, new Link{"Freia"});

  Link* greek_gods = new Link("Hera");
  greek_gods = insert(greek_gods, new Link{"Athena"});
  greek_gods = insert(greek_gods, new Link{"Mars"});
  greek_gods = insert(greek_gods, new Link{"Poseidon"});

  Link* p = find(greek_gods, "Mars");
  if (p) p->value = "Ares";

  p = find(norse_gods, "Zeus");
  if (p) {
	if (p==norse_gods) norse_gods = p->succ;
    erase(p);
    greek_gods = insert(greek_gods,p);
  }

  greek_gods->print();
  norse_gods->print();

  return 0;

}
