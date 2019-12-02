#include <iostream>
#include "params.h"
#include <string>
#include "helper.h"

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

void print_help(void) {
    cout << "------------HELP------------" << endl;
    cout << prompt << " - is prompt to write expression" << endl;
    cout << quitkey << " - quit program" << endl;
    cout << print << " - finish expression" << endl;
    cout << print << " or Enter - print result" << endl;
	cout << "You may use standart math operations: +, -, *, /, %." << endl;
    cout << "There are some function pow(x, n) and sqrt(x)" << endl;
	cout << "To create variable use " << let << " (" << let << " x = 3" << print << ")" << endl;
    cout << "To create const use " << constkey << " (" << constkey <<" x = 3" << print << ")" << endl;
    cout << "-----------------------------" << endl;
}

