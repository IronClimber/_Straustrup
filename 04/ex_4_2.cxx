#include <iostream>
#include <vector>

int main() {
	std::vector<double> temps;
	double median;
	for (double temp; std::cin>>temp;) {
		temps.push_back(temp);	
	}
	std::sort(temps.begin(), temps.end());
	int n = temps.size();
	if (n%2 == 1) {
		median = temps[n/2];
	}
	else if (n%2 == 0) {
		median = (temps[n/2]+temps[n/2-1])/2;
	}
	std::cout<<"median = "<<median;
}