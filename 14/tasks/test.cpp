#include <iostream>

using namespace std;

class B {
public:
  B(int n, int m) : x{n}, y{m} {};
  void print_xy() {
    cout << x << " " << y << endl;
  }
int z{3};

protected:
int x{1};

private:
int y{2};

};

class D : public B { 
  public:
  //Конструктор не наследуется, no matching function
  // y - is private, no field
  // x - no field
  D(int n, int m) : x{n} { };
};

int main() {

  B b{3,4};
  D d{5,6};

  b.print_xy();
  //d.print_xy();


}
