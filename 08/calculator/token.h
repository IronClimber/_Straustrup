#include <iostream>

class Token {
	public:
		char kind;
		double value;
		std::string name;
		
		Token() { }
		Token(char ch) : kind(ch) { }
		Token(char ch, double val) : kind(ch), value(val) { }
		Token(char ch, std::string n) : kind(ch), name(n) { }		
};

class Token_stream {
	public:
        Token_stream(std::istream& s) : input_stream{s} {};
        Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full {false};
		Token buffer;
        std::istream& input_stream;
};
