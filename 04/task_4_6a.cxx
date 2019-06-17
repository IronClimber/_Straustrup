#include <iostream>
#include <vector>

int main() {
	double number;
	double max, min;
	std::vector<double> numbers;
	while (std::cin>>number) {
		numbers.push_back(number);
		if (numbers.size()==1) {
			max = number;
			min = number;	
		}
		else if (numbers.size()>1) {
			if (number < min) {
				min = number;
				std::cout<<"It is min number\n";
			}
			else if (number > max) {
				max = number;
				std::cout<<"It is max number\n";
			}
		}
		/*
		for (int i = 0; i < numbers.size() - 1; ++i) {
			if	
		}
		*/
	}
}