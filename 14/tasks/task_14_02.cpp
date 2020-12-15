#include <iostream>

using namespace std;

class B1 {
public:
  virtual void vf() {
    cout << "B1::vf()" << endl;
  }
  void f() {
    cout << "B1::f()" << endl;
  }
};

class D1 : public B1 {
public:
  void vf() override {
    cout <<  "D1::vf()" << endl;
  }
};

int main() {

  B1 b1;

  b1.vf();
  b1.f();

  D1 d1;

  d1.vf();
  d1.f();

  return 0;

}
