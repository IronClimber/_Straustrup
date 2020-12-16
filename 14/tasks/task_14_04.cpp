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
  void f() {
    cout << "D1::f()" << endl;
  }
};

int main() {

  B1 b1;

  b1.vf();
  b1.f();

  D1 d1;

  d1.vf();
  d1.f();

  //B1 reference on D1 object now has not same behavior as D1 object (is it polymorphism?). In previous task we haven't function f() in D1. So it use B1::f(). Now it has. 
  //Both classes has this functions. But using ref of base class virtual function use function from derived class and ordinary function use function from base class. (This is polumorphism)
  B1& b1_ref{d1};

  b1_ref.vf();
  b1_ref.f();

  return 0;

}
