#include <iostream>
#include <sstream>

using namespace std;

string punctuation = ".;,?-'";

bool is_punctuation(char ch) {
    for (char c : punctuation) {
        if (ch == c) { return true; }
    }
    return false;
}


bool is_not(istringstream& ss) {
    return false;
}


//Use vector container

//don't -> do not; can't -> can not;
//as-if -> OK!; as - if -> as   if;

// - don't use the as-if rule. "fklasfd.l;;l" fklasfd.l;;l
int main() {

    while (cin) {

        //get line
        cout<<"Type some string:"<<endl;
        string line, newline;
        getline(cin, line);
        //cout<<"substr(3,2) -> "<<line.substr(3,2)<<endl;
        cout<<endl<<"Result:"<<endl; 
        
        bool shield = false;

        for(int i = 0; i < line.size(); ++i) {
            char ch = line[i];
            if (is_punctuation(ch) && !shield) {
                if (ch == '-' && isalpha(line[i-1]) && isalpha(line[i+1])) {
                    newline += ch; 
                }
                else { newline += ' '; }                
            }
            //else if (line.substr(i, 4) = "n't ")
            else if (ch == 'n' && !shield) {
                if (line[i+1] == '\'' && line[i+2] == 't' && isspace(line[i+3])) { 
                    if (line.substr(i-2, 2) == "do") { newline += " not"; }
                    else if (line.substr(i-2, 2) == "ca") { newline += "nnot"; }
                    else { newline += " not"; }
                    ++i;
                    ++i;
                }
                else { 
                    newline += ch;
                }
            }
            else {
                newline += ch;
                if (ch=='"') { shield = !shield; }
            }      
        }

        cout << newline << endl << endl;
    }


    return 0;

}
