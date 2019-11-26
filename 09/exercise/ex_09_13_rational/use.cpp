#include <iostream>
#include "Rational.h"

using namespace std;

int main() {

    Rational r1{5,6};
    cout<<r1<<endl;

    Rational r2{3,7};
    cout<<r2<<endl;

    cout<<r1<<"+"<<r2<<"="<<r1+r2<<endl;
    cout<<r1<<"-"<<r2<<"="<<r1-r2<<endl;
    cout<<r1<<"*"<<r2<<"="<<r1*r2<<endl;
    cout<<r1<<"/"<<r2<<"="<<r1/r2<<endl;
    cout<<double(r1)<<endl;
    cout<<(r1!=r2)<<endl;
    cout<<r1<<r2<<endl;
    r1 = r2;
    cout<<r1<<r2<<endl;
    Rational r3{4,9};
    r2 = r3;
    cout<<r1<<r2<<r3<<endl;

    return 0;
}