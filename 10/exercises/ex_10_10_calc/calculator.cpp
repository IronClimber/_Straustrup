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
#include <math.h>
#include <vector>

#include "token.h"
#include "params.h"
#include "handles.h"

using namespace std;

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

Token_stream ts(cin);

void clean_up_mess(void) {
	/*while (true) {
		Token t = ts.get();
		if (t.kind == print) { return; }
	}
	*/
	ts.ignore(print);
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
        bool just_continue = false;
		while (cin) {
			try {
  
				Token t = ts.get();
                //cout << prompt;
                if (t.kind == '\n') {
                    cout << prompt;
                    t = ts.get();
                    //continue;	
                }

				while (t.kind == print /*|| t.kind == '\n'*/) {
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
                    print_help();
                    continue;
                    //cout << prompt;
                    //t = ts.get();
                }

				else if (t.kind == quit) {return;}
                 
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
        cout << prompt;
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
