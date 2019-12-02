#include <iostream>
#include "Token.h"
#include "params.h"
#include "helper.h"

using namespace std;

//Put Token to buffer
void Token_stream::putback(Token t) {
	if (full) error("putback(): Buffer is full."); 
	buffer = t;
	full = true;	
}

Token Token_stream::get() {
	//Read symbols from cin and make Token
	if (full) {  
    //Check is Token in buffer
    //If there are something, read from buffer
		full = false;
		return buffer;
	}
	
    //Edit this input to detect NewLine and then skip spaces
	char ch;
    //cin skip spaces and newlines
    //use cin.get() to read spaces and newlines
    //cin >> ch;
    
    cin.get(ch);
    while (isspace(ch)) {
        if (ch == '\n') {
            //ch = print;
            break;
        }
        cin.get(ch);
    }
    
    //cout << "Switch: '" << ch << "'" << endl;
    //-------------
	switch (ch) {
	case '\n':
	//	//cout << "print";
	//	return Token(print);
	case print:
	case let:
	case ',':
	case '=':
	case '*':
	case '/': 
	case '+': 
	case '-':
	case '%':
	case '(': 
	case ')': //each symbol present itself
		return Token{ch};
	//case '.':
	//case '0': case '1': case '2': case '3': case '4': 
	//case '5': case '6': case '7': case '8': case '9': 
    case 'I': case 'V': case 'X': case 'L':
    case 'C': case 'D': case 'M': {
		cin.putback(ch); //back number to the input  stream
        //to read then full value
		Roman_int val;
		cin>>val; //read float point number
        //cout << "Roman_value: " << val << endl;
		return Token{number, val}; 
	}
	default:
		if  (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
				s += ch;
			}
			cin.putback(ch);
			//cin >> s;
			//string sl = tolower(s);
			if (s == quitkey) {
				return Token(quit);	
			}		
            else if (s == helpkey) {
                return Token(help);
            }
			else if (s == "pow") {
				return Token(pow_f);
			}
			else if (s == "const") {
				return Token(const_cmd);
			}		
			return Token(name, s);
		}
		error("Wrong token: ", ch);	
	}	
}

void Token_stream::ignore(char c) {

	if (full && buffer.kind == c) {
		full = false;
		return;
	}	
	full = false;
	
	char ch = 0;
	while(cin.get(ch)) {
		if(ch==c || ch=='\n') {
			return;
		}	
	}
			
}
