#include <iostream>
#include "Punct.h"
#include <algorithm>
#include <vector>

/*

There are only two kinds of languages: languages that people complain about, and languages that people don't use.

*/

using namespace std;

int main() {

    Punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    ps.case_sensitive(false);

    cout << "Please, type words." << endl;
    
    vector<string> vs;
    for(string word; ps>>word;) { vs.push_back(word); }
    //cout << "End of get words" << endl;
    sort(vs.begin(), vs.end());
    
    for(int i=0; i<vs.size(); ++i) {
        //cout << vs[i] << endl;
        if (i==0 || vs[i]!=vs[i-1]) { cout << vs[i] << endl; }
    }

    return 0;

}
