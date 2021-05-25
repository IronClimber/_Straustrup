#include <iostream>

int main() {

  char* ar = new char[10]; 

  int i = 0;

  std::cout << "Enter symbols: " << std::endl;
  while (std::cin>>ar[i]) {
	
  	if (ar[i]=='!') {
		break;
	}
    ++i;
	
  }

  std::cout << ar << std::endl;

  return 0;

}
