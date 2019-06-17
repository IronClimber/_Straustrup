#include <iostream>
#include <vector>

using namespace std;

constexpr int letters = 4;
vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',  'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
	bool correct = true;
	int bulls = 0;
	int cows = 0;
	vector<char> answer = {'0','0','0','0'};
	vector<char> number = {'c','o','r','n'};
	while (bulls != letters) {
		string value;
		bulls = 0;
		cows = 0;
		//int temp_value;
		cout << "Enter " << letters << " letters string: \n";
		for (int i = 0; i < letters; ++i) {
			cin.get(answer[i]);
			cout << i << "=" << answer[i] << "\n";	
		}
		string str;
		getline(cin, str);
		// check same lettets
		if (correct) {
			for (int i = 0; i < letters; ++i) {
				
				//cout << number[i] << " " << answer[i];
				if (number[i] == answer[i]) {
					++bulls;
					//cout << " bull";
				} else {
					for (int j = 0; j < letters; ++j) {
						if (number[j] == answer[i]) {
							++cows;
							//cout << " cow";
						}
					}
				}	
				//cout << "\n";				
			}	
			cout << "Total " << cows << " cows and " 					<< bulls << " bulls. \n";		
		}	
		else {
			cout << "Wrong value! \n";
		}
		
		
	}
	
}