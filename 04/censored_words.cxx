#include <iostream>
#include <vector>
	
int main() {
	std::vector<std::string> words;
	std::string disliked = "Broccoli";
	for (std::string word; std::cin>>word;) {
		words.push_back(word);
	}
	for (int i = 0; i < words.size(); ++i) {
		if (words[i] == disliked) {
			std::cout<<"BEEP ";
		}
		else {
			std::cout<<words[i]<<" ";	
		}
		
	}
}