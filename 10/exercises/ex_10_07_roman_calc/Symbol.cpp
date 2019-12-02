#include "Symbol.h"
#include "helper.h"

using namespace std;

Roman_int Symbol_table::get_value(string s) {
	for (const Variable& v : var_table) {
		if (v.name == s) { return v.value; }
	}
	error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, Roman_int d) {
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

Roman_int Symbol_table::define_const(string var, Roman_int value) {
	if (is_declared(var)) {
		error(var, " this variable already exist.");
	}
	else {
		var_table.push_back(Variable(var, value, true));
		//cout << " Value defined! \n";
	}
	return value;
}

Roman_int Symbol_table::define_name(string var, Roman_int value) {
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
