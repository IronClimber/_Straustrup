#include <iostream>
#include "swap.h"

using namespace std;

void swap_v(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"Insight swap_v: A = "<<a<<" B = "<<b<<endl;
}

void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"Insight swap_r: A = "<<a<<" B = "<<b<<endl;
}

void swap_cr(const int& a, const int& b) {
    int temp;
    temp = a;
    //a = b;
    //b = temp;
    cout<<"A = "<<a<<" B = "<<b<<endl;
}


