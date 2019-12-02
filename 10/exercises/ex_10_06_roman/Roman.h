#ifndef ROMAN_H
#define ROMAN_H

#include <iostream>

bool is_roman(char ch);
int get_arabic(char ch);
std::string int_to_roman(int num);
int roman_to_int(std::string r);

class Roman_int {
public:
    Roman_int() : value{0} {};
    Roman_int(int v) : value{v} {};
    Roman_int(std::string ri) { value = this->as_int(); }
    int as_int() const { return value; }
    void set_value(int v);
    
private:
    int value;
};

std::istream& operator>>(std::istream& is, Roman_int& ri);
std::ostream& operator<<(std::ostream& os, const Roman_int& ri);

#endif /* ROMAN_H */
