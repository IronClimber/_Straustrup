#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> names;
	vector<int> scores;
	string name;
	int score;
	bool is_not_stopped = true;
	bool is_equal = false;
		
	while (is_not_stopped) {
		cout<<"Enter name and score: ";	
		cin>>name>>score;
		cout<<"\n";
		if (name=="NoName" && score==0)
			is_not_stopped = false;
		else {
			is_equal = false;
			for (int i = 0; i < names.size(); ++i) {
				if (name == names[i]) 
					is_equal = true;
			}
			if (is_equal) {
				cout<<"This name exist in database.\n";
			}
			else {
				names.push_back(name);
				scores.push_back(score);
			}
		}
	}
	for (int i = 0; i < names.size(); ++i) {
		cout<<names[i]<<" "<<scores[i]<<"\n";	
	}
}