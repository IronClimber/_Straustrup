#include "Person.h"

using namespace std;


Person::Person(string name, string second_name, int age) {
  
  if (age > 150 || age < 0) { throw out_of_range("Age should be in range from 0 to 150"); }
  
  string stop_sym = ";:\"'[]*&^%$#@!";
  for (char c : name) {
    for (char s : stop_sym) {
	  if (c==s) { throw invalid_argument("Symbols - ;:\"'[]*&^%$#@! denied in first name."); }
    }
  }

  for (char c : second_name) {
    for (char s : stop_sym) {
	  if (c==s) { throw invalid_argument("Symbols - ;:\"'[]*&^%$#@! denied in second name."); }
    }
  }

  first_name_ = name;
  second_name_ = second_name;
  age_ = age;

}

ostream& operator<<(ostream& os, const Person& p) {
  os << '[' << p.name() << " " << p.second_name() << " " << p.age() << ']';
  return os;
}

istream& operator>>(istream& is, Person& p) {
  string n, sn;
  int a;
  char ch1, ch2;
  is >> ch1 >> n >> sn >> a >> ch2;
  if (!is) return is;
  if (ch1!='[' || ch2!=']') {
	is.clear(ios_base::failbit);
    return is;
  }
  p = Person(n,sn, a);
  return is;
}
