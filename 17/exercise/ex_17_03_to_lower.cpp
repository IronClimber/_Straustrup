#include <iostream>

void to_lower(char* s) {

  while(*s) {
    *s = tolower(*s);
    ++s;
  }

}

int main() {

  char str[]{"Hello, World!"};
  std::cout << str << std::endl;

  //Why not &str?
  to_lower(str);
  std::cout << str << std::endl;

  return 0;

}
