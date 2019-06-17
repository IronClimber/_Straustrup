#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> monday, tuesday, wednesday, thursday, friday, saturday, sunday;
	int wrong = 0;
	string day;
	int value;
	while (cin>>day>>value) {
		if (		  day == "Monday"
					|| day == "Mon"
					|| day == "monday") {
			monday.push_back(value);
		}
		else if (  day == "Tuesday" 
					|| day == "Tue"
					|| day == "tuesday") {
			tuesday.push_back(value);
		}
		else if (  day == "Wednesday" 
					|| day == "Wed" 
					|| day == "wednesday") {
			wednesday.push_back(value);
		}
		else if (  day == "Thursday" 
					|| day == "Thu"
					|| day == "thursday") {
			thursday.push_back(value);
		}
		else if (  day == "Friday" 
					|| day == "Fri"
					|| day == "friday") {
			friday.push_back(value);
		}
		else if (  day == "Saturday" 
					|| day == "Sat"
					|| day == "saturday") {
			saturday.push_back(value);
		}
		else if (  day == "Sunday" 
					|| day == "Sun"
					|| day == "sunday") {
			sunday.push_back(value);
		}
		else {
			++wrong;
		}
	}
	
	//Monday
	cout << "Monday: \n";
	int monday_sum = 0;
	for (int i = 0; i < monday.size(); ++i) {
		cout << monday[i] << " ";
		monday_sum += monday[i];
	}
	cout << "\nSum = " << monday_sum << "\n";
	
	//Tuesday
	cout << "Tuesday: \n";
	int tuesday_sum = 0;
	for (int i = 0; i < tuesday.size(); ++i) {
		cout << tuesday[i] << " ";
		tuesday_sum += tuesday[i];
	}
	cout << "\nSum = " << tuesday_sum << "\n";
	
	//Wednesday
	cout << "Wednesday: \n";
	int wednesday_sum = 0;
	for (int i = 0; i < wednesday.size(); ++i) {
		cout << wednesday[i] << " ";
		wednesday_sum += wednesday[i];
	}
	cout << "\nSum = " << wednesday_sum << "\n";
	
	//Thursday
	cout << "Thursday: \n";
	int thursday_sum = 0;
	for (int i = 0; i < thursday.size(); ++i) {
		cout << thursday[i] << " ";
		thursday_sum += thursday[i];
	}
	cout << "\nSum = " << thursday_sum << "\n";
	
	//Friday
	cout << "Friday: \n";
	int friday_sum = 0;
	for (int i = 0; i < friday.size(); ++i) {
		cout << friday[i] << " ";
		friday_sum += friday[i];
	}
	cout << "\nSum = " << friday_sum << "\n";
	
	//Saturday
	cout << "Saturday: \n";
	int saturday_sum = 0;
	for (int i = 0; i < saturday.size(); ++i) {
		cout << saturday[i] << " ";
		saturday_sum += saturday[i];
	}
	cout << "\nSum = " << saturday_sum << "\n";
	
	//Sunday
	cout << "Sunday: \n";
	int sunday_sum = 0;
	for (int i = 0; i < sunday.size(); ++i) {
		cout << sunday[i] << " ";
		sunday_sum += sunday[i];
	}
	cout << "\nSum = " << sunday_sum << "\n";
	
	cout << "Wrong values: " << wrong;
}