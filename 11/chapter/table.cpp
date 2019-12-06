#include <iostream>
#include <iomanip>

using namespace std;

constexpr int name = 10;
constexpr int surname = 15;
constexpr int tel = 15;
constexpr int email = 30;

int main() {
    float value = 1234567.89;
    cout << setw(name) << "Stepan" << '|' 
         << setw(surname) << "Kostusiev" << '|'
         << setw(tel) << "+380631437784" << '|' 
         << setw(email) << "ironclimber@gmail.com" << '|' << endl;
    cout << setw(name) << "Maria" << '|' 
         << setw(surname) << "Zaika" << '|'
         << setw(tel) << "+380324234235" << '|' 
         << setw(email) << "mzaika@gmail.com" << '|' << endl;
    cout << setw(name) << "Dmitrii" << '|' 
         << setw(surname) << "Ivanchenko" << '|'
         << setw(tel) << "+380933823298" << '|' 
         << setw(email) << "samx@bigmir.net" << '|' << endl;
    cout << setw(name) << "Anna" << '|' 
         << setw(surname) << "Sheverdyukova" << '|'
         << setw(tel) << "+380666666452" << '|' 
         << setw(email) << "anna_sheverdyukova@gmail.com" << '|' << endl;
    cout << setw(name) << "Olexandr" << '|' 
         << setw(surname) << "Schevchuk" << '|'
         << setw(tel) << "+380992349053" << '|' 
         << setw(email) << "oshev4uk@gmail.com" << '|' << endl;

    return 0;
}
