#include <iostream>
#include "Money.h"

using namespace std;

int main() {
    
    Money money{34.567};
    cout<<money.get()<<endl;
    money.set(56.234);
    cout<<money.get()<<endl;

    return 0;
}