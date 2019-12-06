#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    string iname = "text.txt";
    ifstream ifs{iname};
    if (!ifs) { cout << "Problem with input file " << iname << endl; }

    string word = "languages";
    int counter = 1;

    string str;
    while(ifs) {
        getline(ifs, str);
        istringstream ss;
        ss.str(str);
        for (string s; ss>>s;)  {
            if (s == word) { cout << counter << "\t" << str << endl; break; }  
        }
        ++counter;
    }
       
    return 0;

}
