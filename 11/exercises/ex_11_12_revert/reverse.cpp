#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

    string name = "file.txt";
    ifstream ifs{name};
    if (!ifs) { 
        cout << "Something wrong with output file " << name << endl;
        return 0;
    }

    cout << "Reverting " << name << " ..." << endl;
    string str;

    for (char c; ifs.get(c);) {
        str += c;
    }

    reverse(str.begin(), str.end());

    ofstream ofs{name};
    if (!ofs) { 
        cout << "Something wrong with output file " << name << endl;
        return 0;
    }
    
    ofs << str;
    
    cout << "Done!" << endl;
    
    return 0;

}
