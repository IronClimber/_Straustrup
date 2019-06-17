#include <iostream>

int main() {
	double num1, num2;
	char operation;
	std::cout<<"Enter two values and operation:";
	std::cin>>num1>>num2>>operation;
	switch (operation) {
	case '+':
		std::cout<<num1<<" + "<<num2
						<<" = "<<num1+num2;
		break;
	case '-':
		std::cout<<num1<<" - "<<num2
						<<" = "<<num1-num2;
		break;	
	case '*':
		std::cout<<num1<<" * "<<num2
						<<" = "<<num1*num2;
		break;
	case '/':
		std::cout<<num1<<" / "<<num2
						<<" = "<<num1/num2;
		break;
	default:
		break;
	}
	
}