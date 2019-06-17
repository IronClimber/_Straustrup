#include <iostream>
#include <math.h>
double getMax(double n1, double n2) {
	if (n1>n2) return n1;
	else return n2;
}

double getMin(double n1, double n2) {
	if (n1<n2) return n1;
	else return n2;
}

bool isEqual(double n1, double n2) {
	if (n1 == n2) return true;
	else return false;	
}

bool isAlmostEqual(double n1, double  n2) {
	if (abs(n1-n2)<=0.01) return true;
	else return false;
}

int main() {
	double num1, num2;
	while (std::cin>>num1>>num2) {
		if (isEqual(num1, num2)) {
			std::cout<<"Numbers are equal\n";
		}
		else if (isAlmostEqual(num1, num2)) {
			std::cout<<"Numbers are almost equal\n";
		}
		else {
			std::cout<<"Max value is: "
							<<getMax(num1, num2)<<"\n";
			std::cout<<"Min value is: "
							<<getMin(num1, num2)<<"\n";	
		}
	}
}