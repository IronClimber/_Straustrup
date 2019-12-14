#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void print_digit(int value, int quantity) {
    cout << value;
    if (quantity != 1) {
        cout << '\t' << quantity;
    }
    cout << endl;
}


int main() {

    string ifile = "digits.txt";
    cout << "Reading digits from " << ifile << endl;

    ifstream ifs{ifile};
    if (!ifs) { 
        cout << "Somthing wrong with input file " << ifile << endl;
        return 1;
    }

    cout << "Ranging..." << endl;

    vector<int> vi;

    for (int d; ifs >> d;) {
        vi.push_back(d);
    }

    sort(vi.begin(), vi.end());

    cout << "Result:" << endl << endl;

    int counter = 1;
    int last = vi[0];

    for (int i = 1; i < vi.size(); ++i) {
        if (vi[i] != last) {
            print_digit(last, counter);
            counter = 1; 
        }
        else {
            ++counter;
        } 
        last = vi[i];
    }
    
    print_digit(last, counter);
    cout << endl << "Done!" << endl;

    return 0;

}
