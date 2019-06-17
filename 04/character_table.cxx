#include <iostream>

int main() {
	int i = 97;
	while (i <= 122) {
		char c = i;
		std::cout<<c<<" "<<i<<"\n";
		++i;
	}
}