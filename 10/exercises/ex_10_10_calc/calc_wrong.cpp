/* TODO
   1) Remove prompt symbol with multiple output;
        > 23; 232; 232;
        = 23
        > = 232             // this
        > = 232             // and this
        > 
   2) Add trigonometric functions
   3) Add equations solving
   4) Input buffer
*/
/*
Simple calculator.

This program provide simple calculator expressions.

Input  - cin stream. Output  - cout stream.

Symbol table for storing variables and constances

Grammar for input:

Calculation:
    Instruction; Inctruction; ...
	Instruction
	Quit
	Print
    Help
	Calculation Inctruction
	
Instruction:
	Expression
	Adverticement
	
Adverticeme
	# "name" = Expression
    const "name" = Expression
		
Print:
	;
	
Quit:
	quit

Help:
    help

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
	Function	
	
Function
	sqrt ( Expression )
    pow ( Expression, int ( Expression ) )
	
Number:
	Float
	
Input from cin using Token_stream called ts
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

//Command line operators
const string quitkey = "quit";
const string constkey = "const";
const string helpkey = "help";

//User interface
const string prompt =  "> ";
const string result =  "= ";

//Token kind
const char quit = 'q';
const char print = ';';
const char const_cmd = 'C';
const char name = 'a';
const char let = '#';
const char number = '8'; 
const char sqrt_f = 's';
const char pow_f ='p';            
const char help = 'h';
const char from_to = 'f';

void error(string str) {
	throw runtime_error("Error: " + str);
}

void error(string str1, string str2) {
	throw runtime_error(str1 + str2);
}

void error(string str1, char ch) {
	throw runtime_error(str1 + ch);
}

void print_help(ostream& os) {
    os << "------------HELP------------" << endl;
    os << prompt << " - is prompt to write expression" << endl;
    os << quitkey << " - quit program" << endl;
    os << print << " - finish expression" << endl;
    os << print << " or Enter - print result" << endl;
	os << "You may use standart math operations: +, -, *, /, %." << endl;
    os << "There are some function pow(x, n) and sqrt(x)" << endl;
	os << "To create variable use " << let << " (" << let << " x = 3" << print << ")" << endl;
    os << "To create const use " << constkey << " (" << constkey <<" x = 3" << print << ")" << endl;
    os << "-----------------------------" << endl;
}

/*-------------------Variable------------------------------------*/
class Variable {
	public:
		string name;
		double value;	
		bool is_const;
			
		Variable(string n, double v) : name(n), value(v), is_const(false) { }
		
		Variable(string n, double v, bool  c) : name(n), value(v), is_const(c) { }
};

/*-------------------SymbolTable------------------------------*/
class Symbol_table {
	public:
		vector<Variable> var_table;
		double get_value(string s);
		void set_value(string s, double d);
		bool is_declared(string var);
		double define_const(string var, double value);
		double define_name(string var, double value);
};

double Symbol_table::get_value(string s) {
	for (const Variable& v : var_table) {
		if (v.name == s) { return v.value; }
	}
	error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, double d) {
        for (Variable& v : var_table) {
            if (v.name == s) {
                    if (v.is_const) {
                            error(s, " is const");
                    }
                    v.value = d;
                    return;
            }
        }
        error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string var) {
	for (Variable& v : var_table) {
		if (v.name == var) {
			return true;
		}	
	}
	return false;	
}

double Symbol_table::define_const(string var, double value) {
	if (is_declared(var)) {
		error(var, " this variable already exist.");
	}
	else {
		var_table.push_back(Variable(var, value, true));
	}
	return value;
}

double Symbol_table::define_name(string var, double value) {
	if (is_declared(var)) { 
		set_value(var, value);
	}
	else {
		var_table.push_back(Variable(var, value));
	}
	return value;
}

Symbol_table sym_table;

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
        void set_isbuf(streambuf* ib) {is.rdbuf(ib); }
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full {false};
		Token buffer;
        istream& is {cin};
};

Token_stream ts;

void clean_up_mess(void) {
	ts.ignore(print);
}

//Put Token to buffer
void Token_stream::putback(Token t) {
	if (full) error("putback(): Buffer is full."); 
	buffer = t;
	full = true;	
}

//iostream& is - need a lot of code formatting. How to save refference to istream in class?
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
    //use is.get() to read spaces and newlines
    is.get(ch);
    while (isspace(ch)) {
        if (ch == '\n') {
            break;
        }
        is.get(ch);
    }
    
    //-------------
	switch (ch) {
	case '\n':
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
	case '.':
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9': {
		is.putback(ch); //back number to the input  stream
        //to read then full value
		double val;
		is>>val; //read float point number
		return Token{number, val}; 
	}
	default:
		if  (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (is.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) {
				s += ch;
			}
			is.putback(ch);
			if (s == quitkey) {
				return Token(quit);	
			}		
            else if (s == helpkey) {
                return Token(help);
            }
			else if (s == "sqrt") { 
				return Token(sqrt_f);
			}
			else if (s == "pow") {
				return Token(pow_f);
			}
			else if (s == "const") {
				return Token(const_cmd);
			}
            else if (s == "from") {
                return Token(from_to);
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
	while(is.get(ch)) {
		if(ch==c || ch=='\n') {
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
	case sqrt_f:
	{
		t = ts.get();
		if (t.kind != '(') {
			error("It should be '(' before sqrt.");
		}
		
		double e = expression();
		if (e<0) {
			error("sqrt expression should be >= 0");
		}
		double d = sqrt(e);
		
		
		t = ts.get();
		if (t.kind != ')') {
			error("It should be ')'.");
		}
		return d;
	}
	case pow_f:
	{
		t = ts.get();
		if (t.kind != '(') {
			error("It should be '(' after pow.");
		}
		double e = expression();
		t = ts.get();
		if (t.kind != ',') {
			error("Pow expect two args, separated by coma (double, int)");	
		}
		double n = expression();
		if (n<0) {
			error("Pow degree should be >= 0");
		}
		else if (n-int(n)!=0) {
			error("Pow should be integer");
		}
		double pow = 1;
		for (int i = 0; i < n; ++i) {
			pow *= e;	
		}
		t = ts.get();
		if (t.kind != ')') {
			error("It should be ')'.");
		}
		return pow;	
	}		
	case number:
	{
		return t.value;
	}
	
	case name:
	{
		return sym_table.get_value(t.name);	
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

double declaration(char kind) {
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
	if (kind == const_cmd) {
		sym_table.define_const(var_name, d);
	}
	else {	
		sym_table.define_name(var_name, d);
	}
	return d;
}

void calculate(istream& is, ostream& os);

void calc_from(istream& is, ostream& os) {
    string ifile, str, ofile;
    is>>ifile>>str>>ofile;
    if (str != "to") { return; }
    ifstream ifs(ifile);
    if (!ifs) { return; }
    ofstream ofs(ofile);
    if (!ofs) { return; }
    calculate(ifs, ofs);
    ts.set_isbuf(cin.rdbuf());
}

double statement(void) {
	Token t = ts.get();
	switch (t.kind) {
		case let:
		case const_cmd:
			return declaration(t.kind);
		default:
			ts.putback(t);
			return expression();
	}
}

void calculate(istream& is, ostream& os) {
        //While is OK. All is operations is fine.
        bool just_continue = false;
        ts.set_isbuf(is.rdbuf());
		while (is) {
			try {
  
				Token t = ts.get();
                if (t.kind == '\n') {
                    os << prompt;
                    t = ts.get();
                }

				while (t.kind == print) {
                    t = ts.get();
                    if (t.kind == '\n') {
                        ts.putback(t);
                        just_continue = true;
                        break;
                    }             
                }

                if (just_continue) {
                    just_continue = false;
                    continue; 
                }

                if (t.kind == help) {
                    print_help(os);
                    continue;
                }
                else if (t.kind == from_to) {
                    calc_from(is, os);
                }

				else if (t.kind == quit) {return;}
                 
				ts.putback(t);
				os << result << statement() << "\n";
			} 
			catch (exception& e) {
                os << "bu!" << endl;
				cerr << e.what() << "\n";
				clean_up_mess();
			}
		}
}

/*-------------------------Main-------------------------------------*/

int main() {
	try {
		//sym_table.define_const("pi", 3.1415926535);
		//sym_table.define_const("e", 2.7182818284);
        cout << prompt;
		calculate(cin, cout);
		return 0;
	} 
	catch (...) {
		cerr << "Exception! \n";
		return 2;
	}
}
