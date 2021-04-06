#include "Iterator.h"
#include <iostream>

void print(Iterator& it) {
  std::cout << "Iterator: ";
  double* e;
  if (e != 0) {
    do {
	  e = it.next();
	  std::cout << *e << " ";
    }
    while (e < it.end());
  }
  std::cout << std::endl;
}

int main() {

  std::vector<double> vd{1.2,2.3,3.4,4.5,5.6,6.7};
  Vector_iterator vi{vd};
  print(vi);

  std::list<double> ld {7.6,6.5,5.4,4.3,3.2,2.1,1.0};
  List_iterator li{ld};
  print(li);

  return 0;

}
