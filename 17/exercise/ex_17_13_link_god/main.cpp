#include <iostream>
#include "Link.h"
#include "God.h"

int main() {

  Link* gods = new Link{new God{"Thor", "Norway", "Cariot with two goats", "Mjollnir Hummer"}};
  gods = gods->add_ordered(new Link{new God{"Odin", "Norway", "Eightlegged horse Slaypner", "Spear Gungnir"}});
  gods = gods->add_ordered(new Link{new God{"Zeus", "Greace", "Chariot with eagle", "Sunder"}});
  gods = gods->add_ordered(new Link{new God{"Freia", "Norway", "Legs", "Brissingham necklace"}});
  gods = gods->add_ordered(new Link{new God{"Hera", "Greace", "Legs", "Afrodiata's belt"}});
  gods = gods->add_ordered(new Link{new God{"Athena", "Greace", "Legs", "Spear"}});
  gods = gods->add_ordered(new Link{new God{"Mars", "Rome", "Legs", "Spear"}});
  gods = gods->add_ordered(new Link{new God{"Poseidon", "Greace", "Chariot with horses", "Trident"}});
  gods = gods->add_ordered(new Link{new God{"Venus", "Rome", "Shell", "Belt"}});
  gods = gods->add_ordered(new Link{new God{"Neptune", "Rome", "Chariot with horses", "Trident"}});

  gods->print_all("All gods");

  Link* norse_gods = nullptr;
  Link* greek_gods = nullptr;
  Link* rome_gods = nullptr;

  Link* p = nullptr;
  gods = gods->root();

  while (gods) {
    //gods->print();
	//gods->next()->print();
	p = gods->next();
    if (gods->god->mythology == "Norway") {
		//Don't work proper until swap strings
		//std::cout << "Put " << gods->god->name << " to Norse gods" << std::endl;
		gods->erase();
		norse_gods = norse_gods->add_ordered(gods);
		//norse_gods->print();
    }
	else if (gods->god->mythology == "Greace") {
		//std::cout << "Put " << gods->god->name << " to Greek gods" << std::endl;
		gods->erase();
		greek_gods = greek_gods->add_ordered(gods);
		//greek_gods->print();
    }
	else if (gods->god->mythology == "Rome") {
		//std::cout << "Put " << gods->god->name << " to Rome gods" << std::endl;
		gods->erase();
		rome_gods = rome_gods->add_ordered(gods);		
		//rome_gods->print();
    }
	else {
		std::cout << "!!!!!!!!!!!!!!!!!!!" << std::endl;
	}
	
    gods = p;
	
  }

  gods->print_all();
  norse_gods->print_all("Norse gods");
  greek_gods->print_all("Greek gods");
  rome_gods->print_all("Rome gods");

/*
  Link* p = greek_gods->find("Mars");
  if (p) p->value = "Ares";

  Link* p2 = norse_gods->find("Zeus");
  if (p2) {
	if (p2==norse_gods) norse_gods = p2->next();
    p2->erase();
    greek_gods = greek_gods->add_ordered(p2);
  }
*/

  std::cout << std::endl;
  return 0;

}
