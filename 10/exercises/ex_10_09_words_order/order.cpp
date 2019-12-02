#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void error(string str1, string str2) {
    throw runtime_error(str1+str2);
}

int main() {
    
    cout << "Type filename to order: ";
    string file;
    cin >> file;
    ifstream ifs{file};
    if (!ifs) { error("Not possible to open file ", file); }

    vector<string> words;
    string word;
    while (ifs >> word) {
        words.push_back(word);
    }
    sort(words.begin(), words.end());

    ifs.close();

    ofstream ofs{file};
    if (!ofs) { error("Not possible to open file ", file); }

    for (string w : words) {
        ofs << w << " ";
    }   

    cout << "File '" << file << "' ordered." << endl;

    return 0;
}
