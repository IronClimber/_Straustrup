#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void error(string str1, string str2) {
    throw runtime_error(str1+str2);
}

int main() {

    vector<string> words;
    string word;

    string file1 = "text1.txt";
    ifstream ifs1{file1};
    if (!ifs1) { error("Not possible to open file ", file1); }

    while (ifs1 >> word) {
        words.push_back(word);
    }

    string file2 = "text2.txt";
    ifstream ifs2{file2};
    if (!ifs2) { error("Not possible to open file ", file2); }

    while (ifs2 >> word) {
        words.push_back(word);
    }

    sort(words.begin(), words.end());
    
    string file = "text.txt";
    ofstream ofs{file};
    if (!ofs) { error("Not possible to open file ", file); }

    for (string w : words) {
        ofs << w << " ";
    }   

    return 0;
}
