#ifndef SYMBOL_H
#define SYMBOL_H

#include <vector>
#include <string>
#include "Roman.h"

class Variable {
	public:
		std::string name;
		Roman_int value;	
		bool is_const;
			
		Variable(std::string n, Roman_int v) : name(n), value(v), is_const(false) { }
		
		Variable(std::string n, Roman_int v, bool  c) : name(n), value(v), is_const(c) { }
};

class Symbol_table {
	public:
		std::vector<Variable> var_table;
		Roman_int get_value(std::string s);
		void set_value(std::string s, Roman_int d);
		bool is_declared(std::string var);
		Roman_int define_const(std::string var, Roman_int value);
		Roman_int define_name(std::string var, Roman_int value);
};

#endif /* SYMBOL_H */
