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
  virtual void pvf() =0;
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

class D2 : public D1 {
public:
  void pvf() override {
    cout << "D2::pvf()" << endl;
  }
};

int main() {

  D2 d2;
  d2.vf();
  d2.f();
  d2.pvf(); 

  return 0;

}
