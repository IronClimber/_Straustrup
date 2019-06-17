#include <iostream>

int main() {
	std::cout << "Miles: ";
	double miles = 0;
	double kilometers = 0;
	std::cin >> miles;
	kilometers = miles * 1.609;
	std::cout << "Kilometers: " << kilometers;
	return 0;	
}