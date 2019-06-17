#include <iostream>

using namespace std;

double ctok(double c) {
	double k = c + 273.15;
	return k;	
}

int main() {
	double c = 0;
	cout << "Temperature (C): ";
	cin >> c;
	double k = ctok(c);
	cout << "Temperature: "<< k << " K\n";
}