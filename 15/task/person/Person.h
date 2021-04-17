#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

struct Person {

  //Person(string n="", int a=0) : name_{n}, age_{a} { }
  Person(string n="", string sn="", int a=0);
  int age() const { return age_; }
  string name() const { return first_name_; }
  string second_name() const { return second_name_; }
  
private:
  string first_name_;
  string second_name_;
  int age_;

};

ostream& operator<<(ostream& os, const Person& p);
istream& operator>>(istream& is, Person& p);



#endif /* PERSON_H_ */

