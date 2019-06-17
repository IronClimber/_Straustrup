#include <iostream>

//Do not act on bad input like "- 274". Show 0.

using namespace std;

constexpr double absolute_min = -273.15;
constexpr double absolute_min_k = 0;

double ctok(double c) {
	if (c < absolute_min) {
		throw runtime_error("ERROR. Very low temperature.");
	}
	else {
		double k = c + 273.15;
		return k;
	}	
}

double ktoc(double k) {
	if (k < absolute_min_k) {
		throw runtime_error("ERROR. Very low temperature.");
	}
	else {
		double c= k - 273.15;
		return c;		
	}	
}
	
int main() {
	double c = 0;
	double k = 0;
	cout << "Temperature (K): ";
	cin >> k;
	try {
		c = ktoc(k);
	}
	catch (runtime_error& e) {
		cerr << e.what();
		return 1;
	}
	cout << "Temperature: "<< c << " C\n";
	return 0;
}