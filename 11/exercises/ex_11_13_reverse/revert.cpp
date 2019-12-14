#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string name = "file.txt";
    ifstream ifs{name};
    if (!ifs) { 
        cout << "Something wrong with output file " << name << endl;
        return 0;
    }

    cout << "Reverting " << name << " ..." << endl;
    vector<string> vs;

    for (string s; ifs >> s;) {
        vs.push_back(s);
    }

    reverse(vs.begin(), vs.end());

    ofstream ofs{name};
    if (!ofs) { 
        cout << "Something wrong with output file " << name << endl;
        return 0;
    }
    
    for (string s : vs) {
        ofs << s << ' ';
    }

    cout << "Done!" << endl;
    
    return 0;

}
