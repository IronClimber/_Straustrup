#include <iostream>

int fac(int x) {
  if (x==1 || x==0) { return 1; }
  int y = x - 1;
  std::cout << &y << std::endl;
  return fac(y);

}


int main() {
	
  fac(7);

  return 0;

}
