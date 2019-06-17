#include <iostream>
#include <vector>

bool isDisliked(std::string word) {
	std::vector<std::string> disliked = { 									"Broccoli", "popos", "pipis" } ;	
	for (std::string i : disliked) {
		if (word == i) return true;
	}
	return false;
}
	
int main() {
	std::vector<std::string> words;
	for (std::string word; std::cin>>word;) {
		words.push_back(word);
	}
	for (int i = 0; i < words.size(); ++i) {
		if (isDisliked(words[i])) {
			std::cout<<"BEEP ";
		}
		else {
			std::cout<<words[i]<<" ";	
		}
	}
}