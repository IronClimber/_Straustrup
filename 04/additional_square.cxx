#include <iostream>

int square(int x) {
	int sum = 0;
	for (int i = 0; i < x; ++i) {
		sum += x;
	}
	return sum;
}

int main() {
	for (int i = 0; i < 100; ++i) {
		std::cout<<i<<" "<<square(i)<<"\n";		
	}
}