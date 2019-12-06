#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs("test.txt");
 //   streambut *ifbuf;
    istream& is = cin;
    is.rdbuf(ifs.rdbuf());

    //istream isr;

    string str;

    //cin >> str;
    while (is) {
        is >> str;
    //isr << "isr";
    
        cout << str << endl;
    }

    return 0;
}
