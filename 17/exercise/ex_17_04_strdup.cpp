#include <iostream>
#include <string.h>

char* strdup(const char* s) {

  int counter = 0;

  while(s[counter]) {
    ++counter;
  }
  //std::cout << counter << std::endl;
  //each call allocate new memory
  char* strp = new char[counter+1];

  for (int i = 0; i <= counter; ++i) {
	//*(strp+i) = *(s+i); - another variant
    strp[i] = s[i];
  }

  return strp;

}

int main() {


  char str[] {"Hello, Robot!"};
  std::cout << str << std::endl;

  //implicit conversion str to &str[0]
  char* strp1 = strdup(str);
  char* strp2 = strdup("asfdafd\0");

  std::cout << strp1 << std::endl;
  std::cout << strp2 << std::endl;
  return 0;

}
