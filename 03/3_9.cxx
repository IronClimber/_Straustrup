#include <iostream>
int main() {
	std::cout<<"type something: ";
	std::string str;
	while (std::cin>>str) {	
		if (str == "zero") {
			str = "0";
		}
		else if (str == "one") {
			str = "1";
		}
		else if (str == "two") {
			str = "2";
		}
		else if (str == "three") {
			str = "3";
		}
		std::cout<<str<<" ";
	}
}