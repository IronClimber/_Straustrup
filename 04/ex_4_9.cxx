
#include<iostream>


using namespace std;

int main() {
	double n = 1;
	int i = 1;
	double sum = 1;
	double quantity;
	cout<<"How many cells you need? ";
	cin>>quantity;
	while (i < quantity) {
		cout<<i<<" "<<n<<" "<<sum<<"\n";
		n *= 2;
		sum += n;
		++i;
		
	}
	cout<<"For " <<i<<" cells you have "<<sum<<" grains\n";
}
