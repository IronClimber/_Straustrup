#include <iostream>

int main() {
	char operation;
	double value1, value2;
	
	std::cout<<"Enter operation and two numbers: ";
	std::cin>>operation>>value1>>value2;
	if (operation == '+') {
		std::cout<<value1<<"+"<<value2<<"="
						<<value1+value2;                   
	}
	if (operation == '-') {
		std::cout<<value1<<"-"<<value2<<"="
						<<value1-value2;                   
	}
	if (operation == '*') {
		std::cout<<value1<<"*"<<value2<<"="
						<<value1*value2;                   
	}
	if (operation == '/') {
		std::cout<<value1<<"/"<<value2<<"="
						<<value1/value2;                   
	}
}