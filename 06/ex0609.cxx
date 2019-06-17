#include <iostream>
#include <vector>

using namespace std;

constexpr int digits = 4;
constexpr int max_value = 9999;
constexpr int min_value = 1;

vector<string> numbers_name = {
	"unit",
	"ten",
	"hundred",
	"thousand"	
};

vector<int> quantity;

int main() {
	int number = 0;
	while (number != -1) {
		cout << "Enter number: ";
		cin >> number;
		int order = 1000;
		int last_number = 0;
		int temp_number = number;
		if (number >= min_value &&
		    number <= max_value) {
		    for (int i = 0; i < digits; ++i) { 
				int value = temp_number/order;
				quantity.push_back(value);
				//cout << quantity[i] << endl;	
				temp_number -= value*order;
				order /= 10;
				if (value != 0) {
					last_number = i;
				}
			}
			cout << number << " - is ";
			for (int i = 0; i < digits; ++i) { 
				if (quantity[i] != 0) {
					if (quantity[i] == 1) {
						cout << quantity[i] << " " 
						 << numbers_name[digits-1-i];
					}
					else {
						cout << quantity[i] << " " 
						<< numbers_name[digits-1-i] 
						<<"s";
					}
					if (i < last_number) {
						cout << ", ";
					}
					else if (i == last_number) {
						cout << "\n";	
					}
				}	
				 
			}
			quantity.clear();								
		}
		else {
			cout << "Wrong number. It should be from 1 to 9999.\n";	
		}			
	}	
}