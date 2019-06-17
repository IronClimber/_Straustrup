#include <iostream>

//Do not act on bad input like "- 274". Show 0.

using namespace std;

constexpr double absolute_min = -273.15;

double ctok(double c) {
	if (c < absolute_min) {
		throw runtime_error("ERROR. Very low temperature.");
	}
	else {
		double k = c + 273.15;
		return k;
	}	
}
	
int main() {
	double c = 0;
	double k = 0;
	cout << "Temperature (C): ";
	cin >> c;
	try {
		k = ctok(c);
	}
	catch (runtime_error& e) {
		cerr << e.what();
		return 1;
	}
	cout << "Temperature: "<< k << " K\n";
	return 0;
}