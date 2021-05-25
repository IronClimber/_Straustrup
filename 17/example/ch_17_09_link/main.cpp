#include <iostream>
#include "Link.h"

int main() {

  std::string str{"fasdf"};

  Link* norse_gods = new Link{"Thor"};
  norse_gods = insert(norse_gods, new Link{"Odin"});
  norse_gods = insert(norse_gods, new Link{"Freia"});

  norse_gods->print();
  
  return 0;

}
