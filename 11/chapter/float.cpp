#include <iostream>

using namespace std;

int main() {
    float value = 1234567.89;
    cout << value << '\t'
         << fixed << value << '\t'
         << scientific << value << '\t' << endl;
    return 0;
}
