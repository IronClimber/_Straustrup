#include <iostream>
#include <bitset>

using namespace std;

int main() {
	constexpr int size = 8;
	bitset<size> b1 = 0x4a;
	bitset<size> b2 = 0xf2;
	
	cout << b1 << " " << b1 << " "  
			 << b1 << " " << b1 << " " 
			 << b1 << " " << b1 << " " <<"\n";
	cout << b2 << " " << b2 << " "  
			 << b2 << " " << b2 << " " 
			 << b2 << " " << b2 << " " <<"\n";
		
	cout << bitset<size> {b1&b2} << " "
			 << bitset<size> {b1|b2} << " "
			 << bitset<size> {b1^b2} << " "
			 << bitset<size> {~b1} << " "
			 << bitset<size> {b1<<2} <<" "
			 << bitset<size> {b1>>3} << "\n";
	
}