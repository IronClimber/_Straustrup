#include <iostream>
#include <limits>
#include <bitset>

using namespace std;

int main()
{
	for (unsigned int i; cin >> i;) {
		//cout << sizeof(int) << "\n";
		cout << dec << i << "=="
		         << hex << "0x" << i << "=="
				 << bitset<8*sizeof(unsigned int)> {i} << "\n";
	}
}