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
  //Error. This function should be overriden in derived classes.
  virtual void pvf();
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

  B1& b1_ref{d1};

  b1_ref.vf();
  b1_ref.f();

  return 0;

}
