#include <iostream>

int main() {
	std::cout << "Please, type name: ";	
	std::string first_name;
	std::string last_name;
	std::cin >> first_name >> last_name;
	std::cout << "Age: ";
	int age = -1;
	std::cin >> age;
	if (age <= 0 || age >= 110) {
		std::cout << "You are joking!";
		return 1;
	}
	std::cout << "Please enter friend name: ";
	std::string friend_name;
	std::cin >> friend_name;
	std::cout << "Friend sex: ";
	char friend_sex = '0';
	std::cin >> friend_sex;
	std::cout << "Dear, " << first_name 
	                << " " << last_name
	                << ", how are you?\n"
	                << "I am fine. I looking for you.\n"
	                << "When you met " << friend_name
	                << "?\n";
	if (friend_sex == 'f') {
		std::cout << "Told her to call me.\n";
	}
	else if (friend_sex == 'm') {
		std::cout << "Told him to call me.\n";
	}
	std::cout << "I heard that you have Birthday. And now you are " << age << " years old.";
	if (age < 12) {
		std::cout << " Next year you will be " << age + 1 << " years old.\n";
	}
	else if (age == 17) {
		std::cout << " Next year you can vote.\n";
	}
	else if (age > 70) {
		std::cout << " I hope you have good time in your pleasure.\n";
	}
	std::cout << "Your sencerelly.\n\nStepan.";                               
	                
}