#include <iostream>
#include <vector>

using namespace std;

class Name_value {
	public:
		string name;
		int value;
};

int main() {
	vector<Name_value> nvs;
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
			for (int i = 0; i < nvs.size(); ++i) {
				if (name == nvs[i].name) 
					is_equal = true;
			}
			if (is_equal) {
				cout<<"This name exist in database.\n";
			}
			else {
				Name_value nv{name, score};
				nvs.push_back(nv);
			}
		}
	}
	for (int i = 0; i < nvs.size(); ++i) {
		cout<<nvs[i].name<<" "<<nvs[i].value<<"\n";	
	}
}