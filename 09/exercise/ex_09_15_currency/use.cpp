#include <iostream>
#include "Money.h"

using namespace std;

int main() {
    
    Money money{Currency::USD, 34.567};
    cout<<money.get()<<" "<<int(money.currency())<<endl;
    money.set(56.234);
    cout<<money.get()<<" "<<int(money.currency())<<endl;
    money.convert(Currency::UAH);
    cout<<money.get()<<" "<<int(money.currency())<<endl;
    money.convert(Currency::EUR);
    cout<<money.get()<<" "<<int(money.currency())<<endl;
    money.convert(Currency::USD);
    cout<<money.get()<<" "<<int(money.currency())<<endl;

    return 0;
}