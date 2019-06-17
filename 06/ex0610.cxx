#include <iostream>

using namespace std;

int f(int val) {
	int factorial = 1;
	if (val < 1) {
		throw runtime_error("Invalid factorial value.");	
	}
	for (int i = 1; i <= val; ++i) {
		factorial *= i;
	}
	return factorial;	
}

int permutations(int n, int m) {
	return f(n)/f(n-m);
}

int combinations(int n, int m) {
	return permutations(n, m)/f(m);
}

int main() {
	int n = 0;
	int m = 0;
	char type = '0';
	int answer = 0;
	try {
	cout << "Enter n: ";
	cin >> n;
	if (n < 1) {
		cout << "n should be integer >= 1";
		return 1;
	}
	cout << "Enter m: ";
	cin >> m;
	if (m < 1) {
		cout << "m should be integer >= 1";
		return 1;
	}
	cout << "Combinations (c) or  permutations (p)?: ";
	cin >> type;
	if (type == 'c') {
		answer = combinations(n, m);
	}
	else if (type == 'p') {
		answer = permutations(n, m);
	}
	else {
		cout << "You can use only 'c' or 'p'";
		return 1; 
	}
	cout << "Answer: " << answer;
	}
	catch (exception& е) {
		cerr << "error: " << е. what () << '\n' ; 
		return 1; 
	}
	catch ( ... ) { 
		cerr <<"Do not identify type of error. \n";
		return 2; 
	}	
}