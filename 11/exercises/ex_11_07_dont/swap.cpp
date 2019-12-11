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

//don't -> do not; can't -> can not;
//as-if -> OK!; as - if -> as   if;

int main() {

    while (cin) {

        //get line
        cout<<"Type some string:"<<endl;
        string line, newline;
        getline(cin, line);
        cout<<endl<<"Result:"<<endl; 
        
        bool shield = false;
        
        istringstream ss{line};

        for(char ch; ss.get(ch);) {
            if (is_punctuation(ch) && !shield) {
                if (ch == '-') {
                    ss.unget();
                    ss.unget();
                    char ch1, ch2, ch3;
                    ss.get(ch1);
                    ss.get(ch2);
                    ss.get(ch3);
                    if (isalpha(ch1) && ch2 == '-' && isalpha(ch3)) { 
                        newline += ch;                         
                    }
                    else { newline += ' '; }
                    ss.unget();
                }
                else {newline += ' '; }
            }
            else if (ch == 'n') {
                char ch2, ch3, ch4;
                ss.get(ch2);
                ss.get(ch3);
                ss.get(ch4);
                if (ch2 == '\'' && ch3 == 't' && isspace(ch4)) { 
                    newline += " not";
                }
                else { 
                    newline += ch;
                    ss.unget();
                    ss.unget();
                }
                ss.unget();
            }
            else {
                newline += ch;
                if (ch=='"') { shield = !shield; }
            }      
        }

        /*
        for (char ch : line) {
            if (is_punctuation(ch) && !shield) {
                if (is_not(
                newline += ' '; 
            }
            else {
                newline += ch;
                if (ch=='"') { shield = !shield; }
            }      
        }
        */
        cout << newline << endl << endl;
    }


    return 0;

}
