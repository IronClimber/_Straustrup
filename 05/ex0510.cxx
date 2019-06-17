#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	double sum = 0;
	vector<double> values;
	vector<double> diff_values;
	cout << "Enter number of sum values:\n";
	cin >> n;
	if (n <= 0) {
		cout << "Wrong number of sum values. It should be more then zero.\n";
		return 1;
	}
	cout << "Enter some values (| to stop input):\n";
	for (double value; cin >> value;) {
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
	cout << ") equal " << sum << ".\n";
	
	if (values.size() > 1) {
		cout << "Difference vector: \n";
		for (int i = 1; i < values.size(); ++i) {
			double diff_value = values[i] - values[i-1];
			diff_values.push_back(diff_value);
			cout << diff_values[i-1] << " ";
		}
	}
	else {
		cout << "It is not enough values to create diff vector.";
		return 1;
	}
	return 0;
}