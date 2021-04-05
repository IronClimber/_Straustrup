#include "Iterator.h"
#include <iostream>

double* Vector_iterator::next() {
  if (vd.size() == 0) { return 0; }
  ++pos;
  return pos-1;  
}

double* List_iterator::next() {
  if (ld.size() == 0) { return 0; }
  pos+=4;
  return pos-4; 
}

void List_iterator::print() {
  for(double p : ld) {
    std::cout << p << " ";
  }

}
