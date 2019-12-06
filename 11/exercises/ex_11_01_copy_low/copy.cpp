#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string iname = "text.txt";
    ifstream ifs{iname};
    if (!ifs) { cout << "Problem with input file " << iname << endl; }

    string oname = "lower_text.txt";
    ofstream ofs{oname};
    if (!ofs) { cout << "Problem with output file " << oname << endl; }
    
    cout << "Converting... (" << iname << " --> " << oname << ")" << endl;

    //New line in start and end of the new file. Why?
    char ch;
    while(ifs) {
        ifs.get(ch);
        if (isalpha(ch) && isupper(ch)) { ch = tolower(ch); }
        ofs<<ch;
    }
 
    cout << "File converted." << endl;
       
    return 0;

}
