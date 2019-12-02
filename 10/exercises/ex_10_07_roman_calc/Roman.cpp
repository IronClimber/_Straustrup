#include <iostream>
#include <vector>
#include "Roman.h"
#include "helper.h"

//May be additional class Roman_digit?
using namespace std;


vector<char> roman_digits{'I','V','X','L','C','D','M'};
vector<int> arabic{1,5,10,50,100,500,1000};

constexpr int max_int = 3999;
constexpr int min_int = 1;

//return -1 if no char
int get_roman_index(char ch) {
    for (int i = 0; i < roman_digits.size(); ++i) {
        if (roman_digits[i]==ch) { return i; }
    }
    return -1;
}

//ToDo: Rules of conversion! Lighter - harder
//LXLIX - not throw error (but wrong according rules)
// (FIXED) ToDo: Do not throw error MXMXCMLIX. return 2039 (MMXXXIX right answer)
//max.min constrain your own job 1-3999
int roman_to_int(string r) {

    int value = 0;
    int i = 0;
    int higher_index = roman_digits.size() - 1;

    while (i < r.size()) {
        char roman_digit = r[i];
        if (!is_roman(roman_digit) || 
            get_roman_index(roman_digit) > higher_index) { 
            //cout << get_roman_index(roman_digit) << " " << higher_index << endl;
            error("Wrong first roman number: ", roman_digit);
        }
        
        char next_roman_digit = r[i+1]; 
        if (!is_roman(next_roman_digit)) { 
            //Check end of string
            if (i+1<r.size() || get_roman_index(next_roman_digit) > higher_index) { 
                error("Wrong second roman number."); 
            }
            value += get_arabic(roman_digit);
            break;
        }
        else {
            int current_index = get_roman_index(roman_digit);       
            int next_index = get_roman_index(next_roman_digit);
            if (next_index>current_index) {                
                if (current_index%2 == 0 && 
                   (next_index == current_index+1 ||
                    next_index == current_index+2)) {
                    value -= get_arabic(roman_digit);
                    ++i;
                    value += get_arabic(next_roman_digit);
                    ++i;
                    higher_index = next_index - 1;
                }
                else {
                    error("Wrong order in roman number");
                }
            }
            else {
                value += get_arabic(roman_digit);
                ++i;
                higher_index = current_index;
            }
        }
    }
    return value;
}

//User shoud validate char before use
//return -1 if undefine char
int get_arabic(char ch) {
    for (int i = 0; i < roman_digits.size(); ++i) {
        if (roman_digits[i]==ch) { return arabic[i]; }
    }
    return -1;
}

bool is_roman(char ch) {
    for (int i = 0; i < roman_digits.size(); ++i) {
        if (ch == roman_digits[i]) { return true; }
    }
    return false;   
}

//deep to roman recursive?
string int_to_roman(int num) {
    
    //min/max constrain
    if (num < min_int || num > max_int) {
        cout << "Value should be in range [1:3999]." << endl;
        error("Integer out of Romanian range.");
    }

    string roman;

    int dec = num;
    int counter = 0;
    int digits = 0;
    int devider = 1;

    //Find number order
    while (dec/=10) {++digits; devider*=10;}

    //Process each decimal order
    for (int i = digits; i >= 0; --i) {
        counter = num/devider;
        num -= counter*devider;
        if (counter==9) {
            roman+=roman_digits[i*2];
            roman+=roman_digits[i*2+2];
        }
        else if (counter>=5) {
            roman+=roman_digits[i*2+1];
            counter-=5;
            for (int j=0; j<counter; ++j) {
                roman += roman_digits[i*2];
            }
        }
        else if (counter==4) {
            roman+=roman_digits[i*2];
            roman+=roman_digits[i*2+1];
        }
        else {
            for (int j=0; j<counter; ++j) {
                roman += roman_digits[i*2];
            }
        }
        devider/=10;
    }

    return roman;

}

void Roman_int::set_value(int v) { 
    if (v < min_int || v > max_int) {
        cout << "Value should be in range [1:3999]." << endl;
        error("Integer out of Romanian range.");
    }
    value = v;
}

Roman_int& Roman_int::operator=(const Roman_int& a) {
    value = a.as_int();
    return *this;
}

Roman_int& Roman_int::operator*=(const Roman_int& a) {
    value *= a.as_int();
    return *this;
}

Roman_int& Roman_int::operator/=(const Roman_int& a) {
    value /= a.as_int();
    return *this;
}

Roman_int& Roman_int::operator+=(const Roman_int& a) {
    value += a.as_int();
    return *this;
}

Roman_int& Roman_int::operator-=(const Roman_int& a) {
    value -= a.as_int();
    return *this;
}

//How to catch errors?
std::istream& operator>>(std::istream& is, Roman_int& ri) {
    string roman;
    char ch;
    while (is >> ch) {
        if (is_roman(ch)) { roman += ch; }
        else { is.unget(); break;}
    }
    ri.set_value(roman_to_int(roman));
    return is;
}

ostream& operator<<(ostream& os, const Roman_int& ri) {
    return os << int_to_roman(ri.as_int());
}

Roman_int operator+(const Roman_int& a, const Roman_int& b) {
    return Roman_int(a.as_int()+b.as_int());
}

Roman_int operator-(const Roman_int& a, const Roman_int& b) {
    return Roman_int(a.as_int()-b.as_int());
}

Roman_int operator/(const Roman_int& a, const Roman_int& b) {
    return Roman_int(a.as_int()/b.as_int());
}

Roman_int operator*(const Roman_int& a, const Roman_int& b) {
    return Roman_int(a.as_int()*b.as_int());
}

Roman_int operator%(const Roman_int& a, const Roman_int& b) {
    return Roman_int(a.as_int()%b.as_int());
}

bool operator==(const Roman_int& a, const Roman_int& b) {
    if (a.as_int()==b.as_int()) { return true; }
    return false;
}

bool operator!=(const Roman_int& a, const Roman_int& b) {
    if (a.as_int()!=b.as_int()) { return true; }
    return false;
}

//But there are no minus values!
Roman_int operator-(const Roman_int& a) {
    return Roman_int(-a.as_int());
}

