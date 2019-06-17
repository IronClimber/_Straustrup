#include <iostream>

int main() {
	
    std::string previous = " ";
    std::string current;
    while(std::cin>>current) {
    	if (previous == current) {
    		std::cout<<"Repeat word: "<<current<<"\n";
    	}
        previous = current;
    }
    return 0;
}