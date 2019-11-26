#include <iostream>
#include "Money.h"

using namespace std;

int main() {
    
    Money money{Currency::USD, 34.567};
    cout<<money<<endl;
    money.set(56.234);
    cout<<money<<endl;
    money.convert(Currency::UAH);
    cout<<money<<endl;
    money.convert(Currency::EUR);
    cout<<money<<endl;
    money.convert(Currency::USD);
    cout<<money<<endl;

    cout<<"Get money: ";
    Money my;
    //Not error when wrong Money type
    cin>>my;
    cout<<"My money: "<<my<<endl;

    return 0;
}