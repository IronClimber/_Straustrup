#include <iostream>

using namespace std;

void error(string str) {
	throw runtime_error("Error: " + str);
}

void error(string str1, string str2) {
	throw runtime_error(str1 + str2);
}

void error(string str1, char ch) {
	throw runtime_error(str1 + ch);
}

void keep_window_open(char sign) {
		cout << "Enter symbol '" << sign 
		        << "' to close program.\n";
		for (char ch; cin>>ch;) {
			if (ch == sign) return;	
		}	
}
