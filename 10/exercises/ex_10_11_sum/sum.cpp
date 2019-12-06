#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Also need to check range of int
bool is_int(string s) {
    for (char c : s) {
        if (!isdigit(c)) { return false; }
    }
    return true;
}

int main() {
    string ifile = "text.txt";
    ifstream ifs(ifile);
    if (!ifs) { cout << "Something wrong with " << ifile 
                     << ". Can't open file." << endl; }

    //Check range of sum
    int sum = 0;
    string word;
    while (ifs >> word) {
        if (!word.empty() && is_int(word)) {
            sum += stoi(word);
        }
    }

    cout << "SUM: " << sum << endl;
    return 0;
}
