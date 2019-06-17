#include <iostream>

int main () {
	std::cout<<"Type integer: ";
	int value;
	std::cin>>value;
	int indicator = value%2;
	if (indicator == 0)
		std::cout<<"The number "<<value<<" is even.";
	else if (indicator == 1)
		std::cout<<"The number "<<value<<" is odd.";
	
	
	
	
}