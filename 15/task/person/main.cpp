#include <iostream>
#include "Person.h"
#include <vector>
#include <sstream>

using namespace std;

int main() {
  vector<Person> vp;
  Person man;
  while (man.name() != "XXX") {
    try {
		string line;
		getline(cin, line);
		stringstream ss;
		ss << line;
		if (ss >> man) {
		  if (man.name() != "XXX") {
		  	vp.push_back(man);
			cout << "Person accepted." << endl;
		  }
	  	}
		else {
			cout << "Wrong input. Format [<first_name> <second_name> <age>]" << endl;
        }
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
	catch (...) { cout << "Something go wrong." << endl; }	

	cin.clear();
  }
  for (Person p : vp) {
	cout << "Person: " << p << endl;
  }
  cout << "Goodbuy!" << endl;
  return 0;

}
