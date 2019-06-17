#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	constexpr double max_temp = 100;
	constexpr double min_temp = -100;
	
	vector<double> temps;
	
	double sum = 0;
	double high_temp = min_temp;
	double low_temp = max_temp;
	int no_of_temps = 0;
		
	for(double temp; cin>>temp;) {
		++no_of_temps;
		if (temp>high_temp) high_temp=temp;
		if (temp<low_temp) low_temp=temp;
		sum+=temp;
	}
	
	cout<<"\nMax temperature = "
			<<high_temp<<"\n";
	cout<<"Min temperature = "
			<<low_temp<<"\n";
	cout<<"Avarage temperature = "
			<<sum/no_of_temps<<"\n";
						
}