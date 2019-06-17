#include <iostream>
#include <vector>
#include <stdlib.h>

int main() {
	
	constexpr double cm_in_m = 100.0;
	constexpr double cm_in_in = 2.54;
	constexpr double in_in_ft = 12.0;
	
	constexpr double in_in_m = cm_in_m/cm_in_in;
	constexpr double ft_in_m = in_in_m/in_in_ft;
	
	std::string unit;
	double number;
	double max, min;
	double sum = 0;
	int n = 0;
	
	std::vector<double> numbers;
	
	while (std::cin>>number>>unit) {
		
		if (unit == "m" || unit =="cm"
		     					|| unit == "ft" || unit == "in") {
		     						
			if (unit == "cm") {
				number = number/cm_in_m;
			}
			else if (unit == "ft") {
				number = number/ft_in_m;	
			}
			else if (unit == "in") {
				number = number/in_in_m;
			}
			
			std::cout<<number<<" m\n";
			
			numbers.push_back(number);
			n = numbers.size();
			
			if (n == 1) {
				min = number;
				max = number;
			}
			else if (n > 1) {
				if (number > max) max = number;
				else if (number < min) min = number;
			}
			
			sum += number;
		     				
		}
		
		else {
			std::cout<<"Value declined!\n";		
		}
		
	}
	std::sort(numbers.begin(), numbers.end());
	
	for (int i = 0; i < n; ++i) {
		std::cout<<numbers[i]<<" ";
	}
	
	std::cout<<"\nmin = "<<min
					<<" max = "<<max
					<<" n = "<<n
					<<" sum = "<<sum;
}