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
	for (string number; cin>>number;) {
		for (int i = 0; i < numbers_str.size(); ++i) {
			if (number == numbers_str[i]) {
				cout<<numbers_int[i]<<" ";	
			}
		}
		for (int i = 0; i < numbers_int.size(); ++i) {
			if (number == numbers_int[i]) {
				cout<<numbers_str[i]<<" ";	
			}
		}
	}
}




