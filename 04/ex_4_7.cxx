#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> numbers_str = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	vector<string> numbers_int = {
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
	};
	vector<string> num(2);
	vector<double> numbers(2);
	char operation;
	
	std::cout<<"Enter two values and operation:";
	std::cin>>num[0]>>num[1]>>operation;
	
	for (int j = 0; j < num.size(); ++j) {
		for (int i = 0; i < numbers_str.size(); ++i) {
			if (num[j] == numbers_str[i]) {
				numbers[j]=i;	
			}
		}
		for (int i = 0; i < numbers_int.size(); ++i) {
			if (num[j] == numbers_int[i]) {
				numbers[j]=i;	
			}
		}
	}
	
	switch (operation) {
	case '+':
		std::cout<<numbers[0]<<" + "<<numbers[1]
						<<" = "<<numbers[0]+numbers[1];
		break;
	case '-':
		std::cout<<numbers[0]<<" - "<<numbers[1]
						<<" = "<<numbers[0]-numbers[1];
		break;	
	case '*':
		std::cout<<numbers[0]<<" * "<<numbers[1]
						<<" = "<<numbers[0]*numbers[1];
		break;
	case '/':
		std::cout<<numbers[0]<<" / "<<numbers[1]
						<<" = "<<numbers[0]/numbers[1];
		break;
	default:
		break;
	}

	
}

