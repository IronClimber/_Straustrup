#include <iostream>
#include <vector>

using namespace std;

bool get_noun() {
	string str;
	cin >> str;
	if (str == "fish" || str == "bird" || str == "dog") {
		return true;
	}
	else {
		//cin.putback(str);
		return false;
	}
}

bool get_verb() {
	string str;
	cin >> str;
	if (str == "fly" || str == "swim" || str == "run") {
		return true;
	}
	else {
		//cin.putback(str);
		return false;
	}		
}

bool get_union() {
	string str;
	cin >> str;
	if (str == "but" || str == "and" || str == "or") {
		return true;
	}
	else {
		//cin.putback(str);
		return false;
	}		
}

bool get_article() {
	string str;
	cin >> str;
	if (str == "A" || str == "a" ||
		 str == "An" || str == "an" ||
		 str == "The" || str == "the") {
		return true;
	}
	else {
		//cin.putback(str);
		return false;
	}	
}

bool get_point() {
	string str;
	cin >> str;
	if (str == ".") {
		return true;
	}
	else {
		//cin.putback(str);
		return false;
	}	
}

bool get_sentence() {
	string str;
	bool is_not_finished = true;
	while (is_not_finished) {
		//cin.putback(str);
		if (get_article()) { 
			if (get_noun()) {
				if (get_verb()) {	
					cin >> str;
					
					if (str == "but" || str == "and"
					         				|| str == "or") {
						if (get_sentence()) {
							return true;
						}
						else {
							return false;
						}
					}
					
					else if (str == ".") {
						return true;	
					}
					else {
						return false;	
					}	
						
				}
			}	
		}
		
		return false;
		
	}
	return false;
}

int main() {
	bool is_not_finished = true;
	
	
	while (is_not_finished) {
		
		cout << "Write sentence: \n";
		string str;		
				
		if (get_sentence()) {
			cout << "Yes. \n";
						
		}
		else {
			cout << "No. \n";
				
		}
		getline(cin, str);
		/*
		int i = 0;
		while(cin) {
			cin >> str;
			cout << i << ": "<< str;
			++i;
		}
		*/
	}
}
