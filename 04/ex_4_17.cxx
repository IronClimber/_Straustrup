#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> temps;
	std::string mode;
	std::string temp_value;
	int counter = 0;
	int max = 0;
	for (std::string temp; std::cin>>temp;) {
		temps.push_back(temp);	
	}
	std::cout<<"\n";
	std::sort(temps.begin(), temps.end());
	for (int i=0; i<temps.size(); ++i) {
		std::cout<<temps[i]<<" ";	
	}
	std::cout<<"\n";
	int n = temps.size();
	for (int i=0; i<n; ++i) {
		++counter;
		if (i == 0) {
			temp_value = temps[i];
			max = 1;
			mode = temp_value;
		}
		else if (temp_value != temps[i]) {
			temp_value = temps[i];
			counter = 1;
		}
		else if (counter>max) {
			max = counter;
			mode = temp_value;			
		}
		std::cout<<"i="<<i
						<<" counter="<<counter
						<<" max="<<max
						<<" temp_value="<<temp_value
						<<" mode="<<mode<<"\n";
	}
	std::cout<<"mode = "<<mode
					<<" min = "<<temps[0]
					<<" max = "<<temps[n-1];
}