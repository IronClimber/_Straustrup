#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c;
    float x1, x2;
    cout << "Enter square equation coefficients a, b, c: ";
    cin >> a >> b >> c;
    /*cout << a << "*x^2+(" << b << ")*x+(" << c << ") = 0" << endl;*/
    //Beautiful output
    if (a!=0) {
        if (a==-1) { cout << "-"; }
        if (a!=1 && a!=-1) { cout << a << "*";}
        cout << "x^2";
    }
    if (b!= 0) {
        if (b>0 && a!=0) { cout << "+"; }
        if (b==-1) { cout << "-"; }        
        if (b!=1 and b!=-1) { cout << b <<"*"; } 
        cout << "x";
    }
    if (c!=0) {
        if (c>0 && !(a==0 && b==0)) { cout << "+"; }
        cout << c;
    }
    if (!(a==0 && b==0 && c==0)) {
        cout << "=0";
        cout << endl;
    }
    else {
        cout << "0 = 0" << endl;
        cout << "There are infinity number of roots" << endl;
        return 0;
    }
    
    if (a==0 && b ==0) {
        cout << "There are no roots." << endl;
        return 0;
    }
    else if ((a==0 && c==0) || (b==0 && c==0)) {
        cout << "There is one root: 0" << endl;
        return 0;
    }
    
    float d = b*b - 4*a*c;
    if (d>0) {
        
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        cout << "There are two roots: " << x1 << ", " << x2 << endl;
    }
    else if (d==0) {
        x1 = -b/(2*a);
        cout << "There is one root: " << x1 << endl;
    }
    else {
        cout << "There are no roots." << endl;
    }

    return 0;

}
