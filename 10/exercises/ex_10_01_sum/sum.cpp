#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream ist("sum.txt");
    int value = 0;
    int sum = 0;
    while (ist >> value) {
        sum += value;
    }
    cout << "Sum of values from file: " << sum << endl;
    return 0;

}
