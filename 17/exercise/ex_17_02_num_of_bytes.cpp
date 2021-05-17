#include <iostream>

int main() {

  //In some reason I should specify number of elements
  int* pi = new int[2]{8,9};
  long int a0 = reinterpret_cast<long int>(pi);
  long int a1 = reinterpret_cast<long int>(pi+1);
  std::cout << "Integer size: " << a1-a0 << std::endl;

  double* pd = new double[2]{8.0,9.0};
  a0 = reinterpret_cast<long int>(pd);
  a1 = reinterpret_cast<long int>(pd+1);
  std::cout << "Double size:  " << a1-a0 << std::endl;

  char* pc = new char[2]{'8','9'};
  a0 = reinterpret_cast<long int>(pc);
  a1 = reinterpret_cast<long int>(pc+1);
  std::cout << "Char size:    " << a1-a0 << std::endl;

  return 0;
}
