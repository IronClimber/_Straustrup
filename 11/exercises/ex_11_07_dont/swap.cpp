#include <iostream>

using namespace std;

string punctuation = ".;,?-'";

bool is_punctuation(char ch) {
    for (char c : punctuation) {
        if (ch == c) { return true; }
    }
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

        for (char ch : line) {
            if (is_punctuation(ch) && !shield) { newline += ' '; }
            else {
                newline += ch;
                if (ch=='"') { shield = !shield; }
            }      
        }

        cout << newline << endl << endl;
    }


    return 0;

}
