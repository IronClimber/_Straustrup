#include<iostream>
#include<vector>

using namespace std;

bool isSimple(int n) {
	for (int i=2; i<n; ++i) {
		if (n == 1) return true;
		else if (n % i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> simple_numbers;
	
	cout<<"Give limit: ";
	int n;
	cin>>n;
	for (int i=1; i<=n; ++i) {
		if (isSimple(i)) {
			simple_numbers.push_back(i);
		}
	}	
	cout<<"Simple numbers:\n";
	for (int i=0; i<simple_numbers.size(); ++i) {
		cout<<simple_numbers[i]<<"\n";
	}
}