// þ7.7 wrong input 1c4, 1z4 good. why?

/*
Simple calculator.

This program provide simple calculator expressions.

Input  - cin stream. Output  - cout stream.

Grammar for input:

Calculation:
	Instruction
	Quit
	Print
	Calculation Inctruction
	
Instruction:
	Expression
	Adverticement
	
Adverticeme
	let "name" = Expression
		
Print:
	;
	
Quit:
	q

Expression:
	Term
	Expression + Term
	Expression - Term
	
Term:
	Primary
	Term * Primary
	Term / Primary
	Term % Primary

Primary:
	Number
	( Expression )
	- Primary
	+ Primary
	Variable
	
Number:
	Float
	
Input from cin using Token_stream called ts
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//Command line operators
const char quit = 'q';
const char print = ';';
const string declkey = "let";

//User interface
const string prompt =  "> ";
const string result =  "= ";

//Token kind
const char name = 'a';
const char let = 'L';
const char number = '8';                        

void error(string str) {
	throw runtime_error("Error: " + str);
}

void error(string str1, string str2) {
	throw runtime_error(str1 + str2);
}

void error(string str1, char ch) {
	throw runtime_error(str1 + ch);
}

void keep_window_open(char sign) {
		cout << "Enter symbol '" << sign 
		        << "' to close program.\n";
		for (char ch; cin>>ch;) {
			if (ch == sign) return;	
		}	
}

/*-------------------Variable mechanism------------------*/
class Variable {
	public:
		string name;
		double value;	
		
		Variable(string n, double v) : name(n), value(v) { }
};

vector<Variable> var_table;

double get_value(string s) {
	for (const Variable& v : var_table) {
		if (v.name == s) { return v.value; }
	}
	error("get: undefined variable ", s);
}

void set_value(string s, double d) {
	for (Variable& v : var_table) {
		if (v.name == s) {
			v.value = d;
			return;	
		}
	error("set: undefined variable ", s);
	}
}

bool is_declared(string var) {
	for (Variable& v : var_table) {
		if (v.name == var) {
			return true;
		}	
	}
	return false;	
}

double define_name(string var, double value) {
	if (is_declared(var)) { 
		error(var, " this variable already exist.");
	} 
	var_table.push_back(Variable(var, value));
	//cout << " Value defined! \n";
	return value;
}

/*----------------------Token_stream-------------------------*/

class Token {
	public:
		char kind;
		double value;
		string name;
		
		Token() { }
		Token(char ch) : kind(ch) { }
		Token(char ch, double val) : kind(ch), value(val) { }
		Token(char ch, string n) : kind(ch), name(n) { }		
};

class Token_stream {
	public:
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full {false};
		Token buffer;
};

Token_stream ts;

void clean_up_mess(void) {
	/*while (true) {
		Token t = ts.get();
		if (t.kind == print) { return; }
	}
	*/
	ts.ignore(print);
}

void Token_stream::putback(Token t) {
	if (full) error("putback(): Buffer is full."); 
	buffer = t;
	full = true;	
}

Token Token_stream::get() {
	//Read symbols from cin and make Token
	if (full) {  //Check is Token in buffer
		full = false;
		return buffer;
	}
	
	char ch;
	cin >> ch; //cin skip space  symbols
	
	switch (ch) {
	case quit:
	case print:
	case '=':
	case '*':
	case '/': 
	case '+': 
	case '-':
	case '%':
	case '(': 
	case ')': //each symbol present itself
		return Token{ch};
	case '.':
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9': {
		cin.putback(ch); //back number to the input  stream
		double val;
		cin>>val; //read float point number
		return Token{number, val}; 
	}
	default:
		if  (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
				s += ch;
			}
			cin.putback(ch);
			//cin >> s;
			if (s == declkey) {
				return Token(let);	
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
	while(cin>>ch) {
		if(ch==c) {
			return;
		}	
	}
			
}

/*----------------------Grammary realization-------------*/
double expression();

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') {
			error("It should be ')'.");
		}
		return d;
	}
	case number:
	{
		return t.value;
	}
	case name:
	{
		return get_value(t.name);	
	}
	case '-': {
		return - primary();
	}
	case '+': {
		return primary();
	}
	default:
		error("Waiting fot primary expression.");
	}
}

double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*': 
			left *= primary();
			t = ts.get();
			break;	
		case '/': 
		{
			double d = primary();
			if (d == 0)  {
				error("Zero devision!");
			}
			left /= d;
			t = ts.get();
			break;
		}
		case '%': 
		{
			double d = primary();
			if (d == 0) {
				error("Zero devision!");
			}
			left = fmod(left, d);
			t = ts.get();
			break;	
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration(void) {
	Token t = ts.get();
	if (t.kind != name) {
		error("Expecting name of variable.");
	}
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') {
		error("Expecting '=' after variable ", var_name);
	}
	
	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement(void) {
	Token t = ts.get();
	switch (t.kind) {
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void calculate(void) {
		while (cin) {
			try {
				cout << prompt;
				Token t = ts.get();	
				while (t.kind == print) {t = ts.get();}
				if (t.kind == quit) {return;}
				ts.putback(t);
				cout << result << statement() << "\n";
			} 
			catch (exception& e) {
				cerr << e.what() << "\n";
				//cout << "return calculate; \n";
				clean_up_mess();
			}
		}
}

/*-------------------------Main-------------------------------------*/

int main() {
	try {
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		calculate();
		//cout << "return 0;\n";
		keep_window_open('~'); 
		return 0;
	} 
	/*
		catch (exception &e) {
		cout << "E!\n";
		cerr << e.what() << "\n";
		return 1;
	}
	*/
	catch (...) {
		cerr << "Exception! \n";
		//cout << "return 2; \n";
		keep_window_open('~'); 
		return 2;
	}
}