#include <iostream>
#include "God.h"


std::ostream& operator<<(std::ostream& os, const God& g) {

	return os << g.name;/*
				 << " "
			  << g.mythology << " "
			  << g.vechicle << " "
			  << g.weapon;*/

}
