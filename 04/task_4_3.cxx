#include <iostream>
int getMax(int n1, int n2) {
	if (n1>n2) return n1;
	else return n2;
}

int getMin(int n1, int n2) {
	if (n1<n2) return n1;
	else return n2;
}

bool isEqual(int n1, int n2) {
	if (n1 == n2) return true;
	else return false;
		
}

int main() {
	int num1, num2;
	while (std::cin>>num1>>num2) {
		if (isEqual(num1, num2)) {
			std::cout<<"Numbers are equal.\n";
		}
		else {
			std::cout<<"Max value is: "
							<<getMax(num1, num2)<<".\n";
			std::cout<<"Min value is: "
							<<getMin(num1, num2)<<".\n";
		//std::cout<<num1<<" "<<num2<<"\n";	
		}
	}
}