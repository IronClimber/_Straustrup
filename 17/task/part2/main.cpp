#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n) {
  for(int i = 0; i < n; ++i) {
    os << a[i] << " ";
  }
  os << std::endl;
}

void print_vector(std::ostream& os, std::vector<int>& vv) {
  for(int e : vv) {
    os << e << " ";
  }
  os << std::endl;
}

int main() {

  int* p1 = new int{7};
  std::cout << p1 << " point to " << *p1 << std::endl;

  int* p2 = new int[7] {1,2,4,8,16,32,64};
  std::cout << p2 << " point to ";
  print_array(std::cout, p2, 7);

  int* p3 = p2;
  p2 = p1;
  print_array(std::cout, p2, 7);
  p2 = p3;

  std::cout << p1 << " point to " << *p1 << std::endl;
  std::cout << p2 << " point to " << *p2 << std::endl;
  print_array(std::cout, p2, 7);
  delete[] p2;
  delete p1;

  //Операция delete[] p2 удалила только первых 2 элемента массива, точнее освободила память всю, но приравняла к 0 только первые 2 элемента
  std::cout << p1 << " point to " << *p1 << std::endl;
  std::cout << p2+2 << " point to " << p2[2] << std::endl;
  print_array(std::cout, p2, 7);

  p1 = new int[10] {1,2,4,8,16,32,64,128,256,512};
  p2 = new int[10];
  print_array(std::cout, p1, 10);
  print_array(std::cout, p2, 10);
  //first allocate memmory
  
  for (int i = 0; i < 10; ++i) {
    p2[i] = p1[i];
  }

  print_array(std::cout, p2, 10);
  std::cout << std::endl;
  std::cout << "Vector:" << std::endl;
  std::vector<int> v1{1,2,4,8,16,32,64,128,256,512};
  /* v2(10) - create vector with 10 elements, v2{10} - create vector with 1 element, value 10 */
  std::vector<int> v2(10);

  print_vector(std::cout, v1);
  print_vector(std::cout, v2);

  v2 = v1;

  print_vector(std::cout, v1);
  print_vector(std::cout, v2);
  

  //std::cout << "Vectror size: " << v2.size() << std::endl;
  return 0;

}
