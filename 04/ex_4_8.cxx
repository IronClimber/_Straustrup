
#include<iostream>


using namespace std;

int main() {
	int n = 1;
	int i = 1;
	int sum = 1;
	int quantity;
	cout<<"How many grains you need? ";
	cin>>quantity;
	while (sum < quantity) {
		cout<<i<<" "<<n<<" "<<sum<<"\n";
		n *= 2;
		sum += n;
		++i;
		
	}
	cout<<"For " <<i<<" cells you have "<<sum<<" grains\n";
}
