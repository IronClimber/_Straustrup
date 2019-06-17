#include <iostream>

//Do not act on bad input like "- 274". Show 0.

using namespace std;

constexpr double absolute_min_c = -273.15;
constexpr double absolute_min_f = -459.67;

double ctof(double c) {
	if (c < absolute_min_c) {
		throw runtime_error("ERROR. Very low temperature.");
	}
	else {
		double f = 9.0/5.0 * c + 32.0;
		return f;
	}	
}

double ftoc(double f) {
	if (f < absolute_min_f) {
		throw runtime_error("ERROR. Very low temperature.");
	}
	else {
		double c = (f - 32.0)*5.0/9.0;
		return c;		
	}	
}
	
int main() {
	double temp = 0;
	char unit =' ';
	cout << "Temperature: ";
	cin >> temp >> unit;
	try {
		if (unit == 'F') {
			temp = ftoc(temp);
			cout << "Temperature: "<< temp <<"C\n";
		}
		else if (unit == 'C') {
			temp = ctof(temp);
			cout << "Temperature: "<< temp <<"F\n";
		}
		else {
			return 1;	
		}
	}
	catch (runtime_error& e) {
		cerr << e.what();
		return 1;
	}
	
	return 0;
}