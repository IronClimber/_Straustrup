#include <iostream>

int main() {
	
	constexpr double grn_in_dollar = 27.3;
	constexpr double rub_in_dollar = 64.4;
	constexpr double uan_in_dollar = 6.72;
	
	double value = 0.0;
	double converted_value = 0.0;
	std::string type = " ";
	
	std::cout<<"Please, enter the sum and type of currency: ";
	std::cin>>value>>type;
	
	if (type == "grn") {
		converted_value = value/grn_in_dollar;
	}
	else if (type == "rub") {
		converted_value = value/rub_in_dollar;
	}
	else if (type == "uan") {
		converted_value = value/uan_in_dollar;
	}
	
	if (converted_value != 0.0) {
		std::cout<<value<<" "<<type<<" is equal "
	       	         <<converted_value<<" dollars.";
	}
	                  
}