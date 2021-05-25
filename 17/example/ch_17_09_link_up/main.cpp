#include <iostream>
#include "Link.h"

int main() {

  std::string str{"fasdf"};

  Link* norse_gods = new Link{"Thor"};
  norse_gods = insert(norse_gods, new Link{"Odin"});
  norse_gods = insert(norse_gods, new Link{"Freia"});
  Link* temp = norse_gods;
  norse_gods = add(norse_gods, new Link{"Orion"});

  temp->print();
  norse_gods = erase(norse_gods);
  temp->print();
  
  Link* fl = find(norse_gods, "Odin");
  std::cout << fl->value << std::endl;
  Link* al = advance(fl, -1);
  std::cout << al->value << std::endl;

  return 0;

}
