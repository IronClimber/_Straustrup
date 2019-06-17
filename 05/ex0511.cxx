#include <iostream>

using namespace std;

int main() {
	int current_value = 1;
	int last_value = 0;
	int temp_value;
	
	for (int i = 0; i < 45; ++i) {
		temp_value = current_value;
		current_value = current_value + last_value;
		last_value = temp_value;
		cout << i + 2 << " " << current_value << "\n";
	}
}