#include <iostream>

int main() {

  std::string str;

  char ch;

  std::cout << "Enter symbols: " << std::endl;
  while (std::cin>>ch) {
	str.push_back(ch);
  	if (ch=='!') {
		break;
	}
	
  }

  std::cout << str << std::endl;

  return 0;

}
