#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s) {

    vector<string> vs;
    istringstream ss{s};
    
    for (string substring; ss >> substring;) {
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
        
        vector<string> vs = split(line);
        for (string s : vs) {
            cout << s << endl;
        }    

        cout << endl;

    }      

    return 0;

}
