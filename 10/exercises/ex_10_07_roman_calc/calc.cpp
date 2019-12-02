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
	Roman_int
	
Input from cin using Token_stream called ts
*/

#include <iostream>
#include <math.h>
#include <vector>

#include "params.h"
#include "Token.h"
#include "Symbol.h"
#include "helper.h"
#include "Roman.h"

using namespace std;

Symbol_table sym_table;
Token_stream ts;

void clean_up_mess(void) { ts.ignore(print); }

/*----------------------Grammary realization-------------*/
Roman_int expression();

Roman_int primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		Roman_int d = expression();
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
		Roman_int e = expression();
		t = ts.get();
		if (t.kind != ',') {
			error("Pow expect two args, separated by coma (Roman_int, int)");	
		}
		Roman_int n = expression();
		Roman_int pow{1};
		for (int i = 0; i < n.as_int(); ++i) {
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

Roman_int term() {
	Roman_int left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*': 
			left *= primary();
			t = ts.get();
			break;	
		case '/': 
		{
			Roman_int d = primary();
			if (d == 0)  {
				error("Zero devision!");
			}
			left /= d;
			t = ts.get();
			break;
		}
		case '%': 
		{
			Roman_int d = primary();
			if (d == 0) {
				error("Zero devision!");
			}
			left = left%d;
			t = ts.get();
			break;	
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

Roman_int expression() {
	Roman_int left = term();
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

Roman_int declaration(char kind) {
	Token t = ts.get();
	if (t.kind != name) {
		error("Expecting name of variable.");
	}
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') {
		error("Expecting '=' after variable ", var_name);
	}
	
	Roman_int d = expression();
	if (kind == const_cmd) {
		sym_table.define_const(var_name, d);
	}
	else {	
		sym_table.define_name(var_name, d);
	}
	return d;
}

Roman_int statement(void) {
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
