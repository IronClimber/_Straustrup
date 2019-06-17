#include <iostream>
#include <vector>

int main() {
	std::vector<double> distances;
	double sum = 0.0;
	for (double distance; std::cin>>distance;) {
		distances.push_back(distance);
		sum += distance;	
	}
	std::sort(distances.begin(), distances.end());
	int n = distances.size();
	double min = distances[0];
	double max = distances[n-1];
	double average = sum/n;
	std::cout<<"All distance: "<<sum
					<<" km\nMin distance: "<<min
					<<" km\nMax distance: "<<max
					<<" km\nAverage distance: "
					<<average<<" km/n";
}