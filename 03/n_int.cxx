#include <iostream>
#include <math.h>
int main() {
	
    std::cout << "Please enter int:";
    int n;
    std::cin >> n;
    std::cout << "n == " << n
                    << "\nn+1 == " << n + 1
                    << "\nn*3 == " << n*3
                    << "\nn+n == " << n + n
                    << "\nn*n == " << n*n
                    << "\nroot of n == " << sqrt((double)n)
                    << "\nn/2 == " << n/2
                    << "\nn%3 == " << n%3
                    << "\n";
    
    return 0;
}