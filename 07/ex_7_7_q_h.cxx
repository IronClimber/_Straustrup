 // space separate numbers

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
	Function
	
Function
	sqrt ( Expression )
	
Number:
	Float
	
Input from cin using Token_stream called ts
*/

#include <iostream>
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

void print_help(void) {
    cout << "------------HELP------------" << endl;
    cout << prompt << " - is prompt to write expression" << endl;
    cout << quitkey << " - quit program" << endl;
    cout << print << " - finish expression" << endl;
    cout << print << " or Enter - print result" << endl;
	cout << "You may use standart math operations: +, -, *, /, %." << endl;
    cout << "There are some function pow(x, n) and sqrt(x)" << endl;
	cout << "To create variable use " << let << " (" << let << " x = 3" << print << ")" << endl;
    cout << "To create const use " << constkey << " (" << constkey <<" x = 3" << print << ")" << endl;
    cout << "-----------------------------" << endl;
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
        //cout << "set_value(" << s << ", " << d << ")" << endl;
        for (Variable& v : var_table) {
            //cout << "(" << v.name << ":" << s << "), ";
            if (v.name == s) {
                    //cout << "v.name == s" << endl;
                    if (v.is_const) {
                            //cout << "v is const" << endl;
                            error(s, " is const");
                    }
                    v.value = d;
                    //cout << "return" << endl;
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
		//cout << " Value defined! \n";
	}
	return value;
}

double Symbol_table::define_name(string var, double value) {
	if (is_declared(var)) { 
		//error(var, " this variable already exist.");
		set_value(var, value);
	}
	else {
		var_table.push_back(Variable(var, value));
		//cout << " Value defined! \n";
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
            ch = print;
            break;
        }
        cin.get(ch);
    }
    
    //cout << "Switch: '" << ch << "'" << endl;
    //-------------
	switch (ch) {
	//case '\n':
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
	case '.':
	case '0': case '1': case '2': case '3': case '4': 
	case '5': case '6': case '7': case '8': case '9': {
		cin.putback(ch); //back number to the input  stream
        //to read then full value
		double val;
		cin>>val; //read float point number
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
			else if (s == "sqrt") { 
				return Token(sqrt_f);
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

/*----------------------Grammary realization-------------*/
double expression();

double primary() {
	Token t = ts.get();
	//cout << "\'" <<t.kind<<"\'";
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

void calculate(void) {
        //While cin OK. All cin operations is fine.
		while (cin) {
			try {
				cout << prompt;
				Token t = ts.get();	
                
				while (t.kind == print) {t = ts.get();}

                if (t.kind == help) {
                    print_help();
                    continue;
                    //cout << prompt;
                    //t = ts.get();
                }

				if (t.kind == quit) {return;}
				ts.putback(t);
				cout << result << statement() << "\n";
			} 
			catch (exception& e) {
                cout << "bu!" << endl;
				cerr << e.what() << "\n";
				//cout << "return calculate; \n";
				clean_up_mess();
			}
		}
}

/*-------------------------Main-------------------------------------*/

int main() {
	try {
        //if (isspace('t')) cout << "True" << endl;
        //print_help();
		sym_table.define_const("pi", 3.1415926535);
		sym_table.define_const("e", 2.7182818284);
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
