#include <iostream>
#include <vector>

using namespace std; 

double get_sum(const vector<double>& p, const vector<double>& w, int i) {
	if (p.size()  i)
}

vector<double> price;
vector<double> weight;
int number = 4;	

int main() {
	if (price.size() == weight.size()) {
		double sum = get_sum(price, weight, number);
		cout<<"Sum of "<<number<<" elements equal "<<sum<<endl;	
	}	
}