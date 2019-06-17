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
	bool is_empty = true;
		
	while (is_not_stopped) {
		cout<<"Enter name and score: ";	
		cin>>name>>score;
		//cout<<"\n";
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
	
	cout<<"Enter score: ";
	while (cin>>score) {
		is_empty = true;
		
		for (int i = 0; i < scores.size(); ++i) {
			if (score == scores[i]) {
				cout<<names[i]<<"s score is "<<score<<"\n";
				is_empty = false;
			}
		}
		if (is_empty) {
			cout<<"This score doesn't exist. \n";
		}
		cout<<"Enter score: ";
	}
}