#include <iostream>
#include <vector>
#include <sstream>
#include "Punct.h"

using namespace std;

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
    istringstream ss{s};
    
    //Something wrong with input stream like string stream
    Punct_stream ps(ss);
    ps.whitespace(w);
    //ps.case_sensitive(false);

    for (string substring; ps >> substring;) {
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
