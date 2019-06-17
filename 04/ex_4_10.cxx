#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<string> sign = {"stone", "scissors", "paper"};	
	vector<string> machine = {"scissors", "paper", "stone"}; 

	bool is_not_shutdown = true;

	int k = 0;
	int m;
	
	while (is_not_shutdown) {
		cout<<"Your go (stone, scissors, paper): ";
		string go;
		cin>>go;
		//for (int i =0; i < sign.size(); ++i) {
		//if (go == sign[0]) m = 0;
		//}
		if (go == sign[0] ||
			go == sign[1] ||
			go == sign[2]) {
				
			if (k>=machine.size()) {
				k = 0;
			}
			
			string mgo = machine[k];
			cout<<go<<" vs "<<mgo<<"\n";
		
			if (go == mgo) {
				cout<<"You tied.\n";
			}
			else if ((go=="paper" && mgo=="stone")
		  	|| (go=="stone" && mgo=="scissors")
			  || (go=="scissors" && mgo=="paper")) {
			  	cout<<"You win!\n";
			}
			else {
				cout<<"You lose.\n";
			}
		
			++k;
		
		}	
		else {
			cout<<"You use other sign. Game over.";
			return 1;	
		}
	}
}