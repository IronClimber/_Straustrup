#include <iostream>

using namespace std;

void error(string s) {
	throw runtime_error(s);
}

int main() {
	error("Qu!");
}