#include <iostream>
#include <vector>
#include <sstream>
#include "Punct.h"

using namespace std;

string white = ",./?><|!@#$%^;:&*()_-+=";

bool is_whitespace(char c) {
    for(char w : white) { if (c==w) { return true; } }
    return false;
}

vector<string> split(const string& s) {

    vector<string> vs;
    istringstream ss{s};
    
    for (string substring; ss >> substring;) {
        vs.push_back(substring);
    }
    
    return vs;

}

vector<string> split(string& s, const string& w) {

    cout << "Split with whitespaces" << endl;

    vector<string> vs;

    string str;
    for (char ch : s) {
        if (is_whitespace(ch)) { str += ' '; }
        else { str += ch; }
    }
    
    istringstream ss{str};
   
    for (string substring; ss >> substring;) {
        cout << substring << endl;
        vs.push_back(substring);
    }
    
    return vs;

}


int main() {

    while (cin) {

        //get line
        cout<<"Type some string:"<<endl;
        string line, newline;
        getline(cin, line);
        cout<<endl<<"Result:"<<endl; 
                
        string ws = ";:,.?!()\"{}<>/&$@#%^*|~";

        vector<string> vs = split(line, ws);
        for (string s : vs) {
            cout << s << endl;
        }    

        cout << endl;

    }      

    return 0;

}
