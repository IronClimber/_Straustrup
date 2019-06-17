#include <iostream>

int main() {
	
	int coin1=0, coin2=0, coin5=0, coin10=0, coin25=0, coin50=0;
	int sum = 0;

	std::cout<<"1-";
	std::cin>>coin1;
	std::cout<<"2-";
	std::cin>>coin2;
	std::cout<<"5-";
	std::cin>>coin5;
	std::cout<<"10-";
	std::cin>>coin10;
	std::cout<<"25-";
	std::cin>>coin25;
	std::cout<<"50-";
	std::cin>>coin50;
	
	if (coin1>0) {
		std::cout<<"You have " <<coin1<<" one cent coins.\n";
		sum+=coin1;
	}
	if (coin2>0) {
		std::cout<<"You have " <<coin2<<" two cent coins.\n";
		sum+=coin2*2;
	}
	if (coin5>0) {
		std::cout<<"You have " <<coin5<<" five cent coins.\n";
		sum+=coin5*5;
	}
	if (coin10>0) {
		std::cout<<"You have " <<coin10<<" ten cent coins.\n";
		sum+=coin10*10;
	}
	if (coin25>0) {
		std::cout<<"You have " <<coin25<<" twenty five cent coins.\n";
		sum+=coin25*25;
	}
	if (coin50>0) {
		std::cout<<"You have " <<coin50<<" fifty cent coins.\n";
		sum+=coin50*50;
	}
	int dollars, cents;
	dollars = sum/100;
	cents = sum%100;
	std::cout<<"You have "<<dollars<<" dollars and "<< cents << " cents.";
	
}