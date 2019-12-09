#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<char> vowels{'a','e','y','u','i','o'};

bool is_vowel(char c) {
    for (char ch : vowels) {
        if (tolower(c) == ch) { return true; }
    }
    return false;
}

int main() {

    string name = "text.txt";
    ifstream ifs{name};
    if (!ifs) { cout << "Problem with input file " << name << endl; }

    string str;
    char ch;
    while(ifs.get(ch)) {
        if (!is_vowel(ch)) { str.push_back(ch); }
    }

    ifs.close();

    ofstream ofs{name};
    if (!ofs) { cout << "Problem with output file " << name << endl; }
       
    for (char c : str) {
        ofs << c;
        cout << c;
    } 

    cout << "All vowels removed from " << name << endl;

    return 0;
    
}
