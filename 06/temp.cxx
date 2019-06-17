class Token {
	public:
		char kind;
		double value;	
	
};

Token get_token();
double expression();
double term();
double primary();

double expression() {
	dobke left = expression();
	Token t = get_token();
	switch (t.kind) {
		case '+':
			return left + term();
		case '-':
			return left - term();
		default:
			return left;
	}
}