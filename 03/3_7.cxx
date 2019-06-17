#include <iostream>

int main() {
	std::string x,y,z;
	
	std::cout << "Enter 3 names: ";
	std::cin>>x>>y>>z;
	if (x >= y) {
		if (z >=x) {
			std::cout<<z<<" "<<x<<" "<<y;	
		}
		else {
			if (y >= z) {
				std::cout<<x<<" "<<y<<" "<<z;
			}
			else {
				std::cout<<x<<" "<<z<<" "<<y;
			}
		}
	}
	else {
		if (z >= y) {
			std::cout<<z<<" "<<y<<" "<<x;	
		}
		else {
			if (x>=z) {
				std::cout<<y<<" "<<x<<" "<<z;	
			}
			else {
				std::cout<<y<<" "<<z<<" "<<x;	
			}	
		}	
	}
	
	
	
}