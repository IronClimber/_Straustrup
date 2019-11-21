#include <iostream>
#include <vector>

using namespace std; 

double get_sum(const vector<double>& p, const vector<double>& w, unsigned int i) {
	if (p.size() >= (i+1)) {
        return p[i]+w[i];
    }
    throw runtime_error("Index out of array");
}

vector<double> price{5.4, 5.2, 7.2, 3.7, 2.1, 2.7};
vector<double> weight{234.6, 151.1, 1451.6, 132.6, 111.1, 56.1};
int number = 4;	

int main() {
	if (price.size() == weight.size()) {
		double sum = get_sum(price, weight, number);
		cout<<"Sum of "<<number<<" elements equal "<<sum<<endl;	
	}
    else {
        cout<<"There are different size of vectors"<<endl;
    }	
}
