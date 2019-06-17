#include <iostream>

int main() {
	
	constexpr double grn_in_dollar = 27.3;
	constexpr double rub_in_dollar = 64.4;
	constexpr double uan_in_dollar = 6.72;
	constexpr double euro_in_dollar = 0.9;
	
	double value = 0.0;
	double converted_value = 0.0;
	char type = ' ';
	
	std::cout<<"Please, enter the sum and type of currency: ";
	std::cin>>value>>type;
	
	switch (type) {
	case 'g':
		converted_value = value/grn_in_dollar;
		break;
	case 'r':
		converted_value = value/rub_in_dollar;
		break;
	case 'u':
		converted_value = value/uan_in_dollar;
		break;
	case 'e':
		converted_value = value/euro_in_dollar;
		break;
	default:
		std::cout<<"Something wrong.\n";
		break;
	}	
	
	if (converted_value != 0.0) {
		std::cout<<value<<" "<<type<<" is equal "
	       	         <<converted_value<<" dollars.";
	}
	                  
}