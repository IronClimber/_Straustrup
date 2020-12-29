#include <iostream>

struct Temp {
  Temp(int t) : counter{t} { };
  virtual void print_hello();
private:
  int counter{0};
};

int main() {

  Temp temp{5};

  return 0;

}
