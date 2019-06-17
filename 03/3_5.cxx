#include <iostream>

int main() {
	double val1, val2;
	std::cout << "val1=";
	std::cin >> val1;
	std::cout << "val2=";
	std::cin >> val2; 
	if (val1>val2) {
		std::cout << "max=" << val1 << "\n";
		std::cout << "min=" << val2 << "\n";
	}
	else if (val1<val2) {
		std::cout << "max=" << val2 << "\n";
		std::cout << "min=" << val1 << "\n";				
	}
	else if (val1==val2) {
		std::cout << "max=min=" << val1 <<"\n";
	}
	else {
		std::cout << "Something wrong.";
		return 1;          
	}
	std::cout << "val1*val2=" << val1 * val2 << "\n";
	std::cout << "val1+val2=" << val1 + val2 << "\n";
	std::cout << "val1-val2=" << val1 - val2 << "\n";
	std::cout << "val1/val2=" 
					<< val1/val2 << "\n";
	
	
}