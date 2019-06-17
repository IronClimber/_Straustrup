#include <iostream>
#include <vector>

int main() {
	double number;
	
	std::vector<double> numbers;
	while (std::cin>>number) {
		numbers.push_back(number);
		//std::sort(numbers);
		if (number == numbers[0]) {
			std::cout<<"It is min number\n";
		}
		else if (number == numbers[numbers.size()-1]) {
			std::cout<<"It is max number\n";
		}
		/*
		for (int i = 0; i < numbers.size() - 1; ++i) {
			if	
		}
		*/
	}
}