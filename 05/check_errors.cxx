#include <iostream>

using namespace std;

void error(string msg) {
	cout<<msg;
	exit(0);
}

int area(int lenght, int width) {
	if (lenght <= 0 || width <= 0) {
		error("Area has invalid arguments\n");	
	}
	return lenght*width;	
}

int framed_area(int lenght, int width) {
	constexpr int frame_size = 2;
	if (lenght <= frame_size || width <= frame_size) {
		error("Frame area has invalid arguments\n");
	}
	return area(lenght-2, width-2);
}

int f(int x, int y, int z) {
	int area1 = area(x, y);
	if (area1 <= 0) error("It isn't positive area1");
	int area2 = framed_area(3, z);
	int area3 = framed_area(y, x);
	double ratio= double(area1)/area3;
	cout<<"area1 = "<<area1
			<<"\narea2 = "<<area2
			<<"\narea3 = "<<area3
			<<"\nratio = "<<ratio
			<<"\n";	
}

int main() {
	int x, y, z;
	cin>>x>>y>>z;
	f(x, y, z);
	return 0;	
}