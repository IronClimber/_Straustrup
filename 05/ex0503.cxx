#include <iostream>

using namespace std;

constexpr double absolute_min = -273.15;

double ctok(double c) {
	double k = c + 273.15;
	return k;	
}

int main() {
	double c = 0;
	cout << "Temperature (C): ";
	cin >> c;
	if (c < absolute_min) {
		cout << "ERROR. Very low temperature.";
		return 1;
	}
	double k = ctok(c);
	cout << "Temperature: "<< k << " K\n";
	return 0;
}