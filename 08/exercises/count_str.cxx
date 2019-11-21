#include <iostream>
#include <vector>

using namespace std; 

//return vector   by reference or vector value?
void count_str(const vector<string>& vs, vector<int>&  vi) {
	vi.clear();
	for (string s : vs) {
		vi.push_back(s.size());
	}	
}

//Check size of vector, and index
string get_str(const vector<string>& vs, int index) {
	return vs[index];
}

//Empty vector?
int get_max(const vector<int>& vi) {
	int max_index = 0;
	int max_value = vi[0];
	for (int i =1; i<vi.size(); ++i) {
		if (vi[i] > max_value) {
			max_value = vi[i];
			max_index = i;	
		}
	}
	return max_index;
}

int get_min(const vector<int>& vi) {
	int min_index = 0;
	int min_value = vi[0];
	for (int i =1; i<vi.size(); ++i) {
		if (vi[i] < min_value) {
			min_value = vi[i];
			min_index = i;	
		}
	}
	return min_index;
}

//"String1" "String2" equal "String1String2"
vector<string> text {
	"Hello!",
	"Hello! How are you?",
	"I am fine. Thank you. And you?",
	"Ok",
	"When you go home?",
	"After New Year"
};

int main() {
	
	cout << "<<<COUNTER>>>"<< endl;
	vector<int> counter;
	
	count_str(text, counter);
	cout << "Number of symbols in each string: ";
	for(int i : counter) {
		cout << i <<" ";
	}
	cout << endl;
	
	cout << "Shortest string is '"
	 		<< text[get_min(counter)] << "'" << endl;
	cout << "Longest string is '"
	 		<< text[get_max(counter)] << "'" << endl;

	cout << "First string is '"
	 		<< text[0] << "'" << endl;	
	cout << "Last string is '"
	 		<< text[text.size()-1] << "'" << endl;

	return 0;
}