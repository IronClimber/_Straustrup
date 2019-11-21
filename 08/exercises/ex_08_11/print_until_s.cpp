#include <iostream>
#include <vector>

using namespace std;

vector<string> sentence{"Hello", ",", "how", ".", "are", "you", "?", ".", "Rocket", "same", "."};

void print_until_s(vector<string>& v, string quit) {
    for(string s : v) {
        if (s == quit) return;
        cout << s << endl;
    }
}

void print_until_ss(vector<string>& v, string quit) {
    int counter = 0;
    for(string s : v) {
        if (s == quit) {
            if (counter >= 1) return;
            ++counter;
        }
        cout << s << endl;
        
    }
}

int main() {
    print_until_ss(sentence, ".");


}
