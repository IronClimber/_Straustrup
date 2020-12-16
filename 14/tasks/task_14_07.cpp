#include <iostream>

using namespace std;

class B2 {
public:
  virtual void pvf() =0;
};

class D21 : public B2 {
public:
  void pvf() override {
    cout << n << endl;
  }
private:
  string n{"seventeen"};
};

class D22 : public B2 {
public:
  void pvf() override {
    cout << n << endl;
  }
private:
  int n{17};
};

void f(B2& c) {
  c.pvf();
}

int main() {
  D21 d21;
  D22 d22;

  f(d21);
  f(d22);

  return 0;
}
