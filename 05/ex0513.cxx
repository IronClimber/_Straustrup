#include <iostream>
#include <vector>

using namespace std;

constexpr int digits = 4;

int main() {
	int bulls = 0;
	int cows = 0;
	vector<int> answer = {-1, -1, -1, -1};
	vector<int> number = {1, 6, 4, 9};
	while (bulls != digits) {
		int value;
		bulls = 0;
		cows = 0;
		//int temp_value;
		cout << "Enter " << digits << " digits value: \n";
		cin >> value;
		// ещё проверку на одинаковые цифры
		if (value >= 0 && value <= 9999) {
			cout << "Correct value " << value << "\n";
			int devider = 1;
			for (int i = 0; i < digits - 1; ++i) {
				devider *= 10;
			}
			
			for (int i = 0; i < digits; ++i) {
				answer[i] = value/devider;
				value %= devider;
				devider /= 10;
			}
			
			for (int i = 0; i < digits; ++i) {
				
				//cout << number[i] << " " << answer[i];
				if (number[i] == answer[i]) {
					++bulls;
					//cout << " bull";
				}
				for (int j = 0; j < digits; ++j) {
					if (number[j] == answer[i]) {
						++cows;
						//cout << " cow";
					}
				}	
				//cout << "\n";				
			}	
			cout << "Total " << cows << " cows and " 					<< bulls << " bulls. \n";			
		}
		else {
			cout << "Wrong value! \n";
		}
	}
	
}