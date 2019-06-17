#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double a, b, c;
	double d;
	double x1, x2;
	cout<<"Enter quadratic equation coefs (a, b, c): ";
	cin>>a>>b>>c;
	if (a == 0) {
		cout<<"This is not quadratic equation.";
	}
	d = b*b - 4*a*c;
	if (d < 0) {
		cout<<"This equation has no roots";
	}
	else if (d == 0) {
		x1 = -b/(2*a);
		cout<<"This equation has one root x = "<<x1;
	}
	else if (d > 0) {
		x1 = (-b + sqrt(d))/(2*a);
		x2 = (-b - sqrt(d))/(2*a);
		cout<<"This equation has two roots x1="<<x1<<" x2="<<x2;
	}
}