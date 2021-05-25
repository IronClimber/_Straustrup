#ifndef GOD_H_
#define GOD_H_

#include <iostream>

struct God {

	std::string name;
	std::string mythology;
	std::string vechicle;
	std::string weapon;

};

std::ostream& operator<<(std::ostream& os, const God& g);



#endif /* GOD_H_ */
