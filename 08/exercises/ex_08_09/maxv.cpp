#include <iostream>
#include <vector>

using namespace std; 

//What if v is empty?
double maxv(const vector<double>& v) {
    double max_value = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i]>max_value) {
            max_value = v[i];
        }
    }
    return max_value;
}

vector<double> price{5.4, 5.2, 7.2, 3.7, 2.1, 2.7, 10.912};

int main() {
    double max_price = maxv(price);
	cout<<"Max price is "<<max_price<<endl;	
    return 0;
}
