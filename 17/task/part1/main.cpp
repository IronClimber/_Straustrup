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

  int* a = new int[20];
  //*a = 5;
  //a[7] = 4;
  //*(a+3) = 2;
  *a = 100;
  for(int i = 0; i < 20; ++i) {
    *(a+i)=100+i;
  }

  print_array(std::cout, a, 20);

  delete[] a;


  std::vector<int> v;
  for (int i = 0; i < 20; ++i) {
    v.push_back(100+i);
  }

  print_vector(std::cout, v);

  return 0;

}
