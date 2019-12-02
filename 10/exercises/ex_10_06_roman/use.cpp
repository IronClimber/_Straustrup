#include <iostream>
#include "Roman.h"

//#define TEST
//#define ROMAN_TO_INT
//#define INT_TO_ROMAN
using namespace std;

int main() {

/*
Result of this program:
Type roman number: LXLIX
XCIX equal 99
LXLIX - not throw error (but wrong according rules)
*/

    Roman_int r {86};
    cout << r << " equal " << r.as_int() << endl;
    cout << "Type roman number: ";
    cin >> r;
    cout << r << " equal " << r.as_int() << endl;


#ifdef TEST
    for (int i = 1; i < 4000; ++i) {
        string roman_number = int_to_roman(i);
        int arabic_number = roman_to_int(roman_number);
        cout << i << "\t" << roman_number << "\t" << arabic_number << endl;
        if (i != arabic_number) {
            cout << "Error!" << endl;
            return 1;    
        }
    }
#endif

#ifdef INT_TO_ROMAN  
    int req = 0;
    while (cin>>req) {
        Roman_int r{req};
        cout << r << endl;
    }
#endif    

#ifdef ROMAN_TO_INT
    string digits;
    while (cin>>digits) {
        cout << digits << " equal " << roman_to_int(digits) << endl;
    }
#endif
    return 0;
}
