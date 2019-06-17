#include <iostream>

int main() {
	std::string answer;
	int number = 1;
	int ask = 64;
	
	for (int i = 64; i > 0; i = i/2) {
		
		std::cout<<"Is number <= "<< ask << "?\n";
		std::cin>>answer;
		
		
		if (answer=="n") {
			number += i;
			ask += i/2;
		}
		else ask -= i/2;
	}
	std::cout<<number;
}