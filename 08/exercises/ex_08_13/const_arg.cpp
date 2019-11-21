#include <iostream>

using namespace std;

void f(const int p) {
    cout<<p<<endl;
    //++p;
    //cout<<++p<<endl;
    //p++;    
    int a = p;
    cout<<a<<endl;
}

int main() {
    f(1);
}
