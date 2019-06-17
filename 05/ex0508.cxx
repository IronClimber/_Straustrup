#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int sum = 0;
	vector<int> values;
	cout << "Enter number of sum values:\n";
	cin >> n;
	if (n <= 0) {
		cout << "Wrong number of sum values. It should be more then zero.\n";
		return 1;
	}
	cout << "Enter some values (| to stop input):\n";
	for (int value; cin >> value;) {
		values.push_back(value);
	}
	if (values.size() == 0) {
		cout << "There aren't values.\n";
		return 1;
	}
	if (n > values.size()) {
		cout << "You want to sum more numbers that we have.\n";
		cout << "Sum of all numbers ( ";
		for (int i = 0; i < values.size(); ++i) {
			cout << values[i] << " ";
			sum += values[i];
		}
	}
	else {
		cout << "Sum of " << n << " first numbers ( ";
		for (int i = 0; i < n; ++i) {
			cout << values[i] << " ";
			sum += values[i];
		}
	}
	cout << ") equal " << sum;
}