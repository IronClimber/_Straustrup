#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Roman.h"

class Token {
	public:
		char kind;
		Roman_int value;
		std::string name;
		
		Token() { }
		Token(char ch) : kind(ch) { }
		Token(char ch, Roman_int val) : kind(ch), value(val) { }
		Token(char ch, std::string n) : kind(ch), name(n) { }		
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

#endif /* Tokeh.h */
