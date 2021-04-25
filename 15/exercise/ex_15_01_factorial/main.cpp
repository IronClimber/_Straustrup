#include <iostream>
#include <iomanip>

using namespace std;

long facr(int n) { return n>1 ? n*facr(n-1) : 1; }
long faci(int n) {
	long r = 1;
	while (n>1) {
		r*=n;
		--n;
	}
	return r;
}


int main() {
	cout << " # |""            Recursive" << " | " << "            Iterative" << endl;
    cout << "---|" << "---------------------" << "-|-" << "---------------------" << endl;

    for (int i = 0; i <= 20; ++i) {
		cout << setw(2) << i << " |" << setw(21) << facr(i) <<  " | " << setw(21) << faci(i) << endl;
	}
    return 0;

}
