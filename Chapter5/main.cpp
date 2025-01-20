import std;
using namespace std;

void TryThis3_4() {
	//first validate expressions syntactic accuracy
	//we could make a vector of these tokens perhaps and a token that represents a sub-expression
	//make a first pass on the vector of tokens that replaces tokens enclosed in paranthesis as a sub-expression
	//then separate the vector and vectors within the sub-expression tokens so that highest order of operation items are evaluated
	//proceed with further and further lower order operations, several passes might be required.
	//this may not be the most efficient solution though.
}
class Token {
public:
	char kind;
	double value;
	Token(char k)
		: kind{ k }, value{ 0.0 } {}
	Token(char k, double v)
		: kind{ k }, value{ v } {}
};
Token tt6_get_token() {
	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
		//not yet   case ';':    // for "print"
		//not yet   case 'q':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		throw runtime_error("Bad token");
	}
}
double tt6_term();
double tt6_primary();
double tt6_expression() {
	double left = tt6_term();
	Token t = tt6_get_token();
	while (true) {
		switch (t.kind) {
		case '+':
			left += tt6_term();
			t = tt6_get_token();
			break;
		case '-':
			left -= tt6_term();
			t = tt6_get_token();
			break;
		default:
			return left;
		}
	}
}
double tt6_term() {
	double left = tt6_primary();
	Token t = tt6_get_token();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= tt6_primary();
			t = tt6_get_token();
			break;
		case '/':
		{
			double d = tt6_primary();
			if (d == 0)
				throw runtime_error("Divide by zero");
			left /= d;
			t = tt6_get_token();
			break;
		}
		default:
			return left;
		}
	}
}
double tt6_primary() {
	Token t = tt6_get_token();
	switch (t.kind) {
	case '(': //handle '(' expression ')'
	{
		double d = tt6_expression();
		t = tt6_get_token();
		if (t.kind != ')')
			throw runtime_error("')' expected.");
		return d;
	}
	case '8':
		return t.value;
	default:
		throw runtime_error("Primary expected.");
	}
}
void TryThis6() {
	try {
		while (cin)
			cout << "=" << tt6_expression() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		return;
	}
	catch (...) {
		cerr << "unhandled exception..\n";
		return;
	}
}
Token tt9_get_token() {
	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
		//not yet   case ';':    // for "print"
		//not yet   case 'q':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		throw runtime_error("Bad token");
	}
}
class tt9_Tokenstream {
public:
	Token get() {
		if (full) {
			full = false;
			return buffer;
		}
		char ch = 0;
		if (!(cin >> ch))
			throw runtime_error("no input");
		switch (ch) {
		case ';': case 'q': case '(': case ')': case '+': case '-': case '*': case '/':
			return Token{ ch };
		case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val;
			return Token{ '8',val };
		}
		default:
			throw runtime_error("Bad Token");
		}
	}
	void putback(Token t) {
		if (full)
			throw runtime_error("putback() into a full buffer");
		buffer = t;
		full = true;
	}
private:
	bool full = false;
	Token buffer;
};
tt9_Tokenstream tt9_ts;
double tt9_term();
double tt9_primary();
double tt9_expression() {
	double left = tt9_term();
	Token t = tt9_ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += tt9_term();
			t = tt9_ts.get();
			break;
		case '-':
			left -= tt9_term();
			t = tt9_ts.get();
			break;
		default:
			tt9_ts.putback(t);
			return left;
		}
	}
}
double tt9_term() {
	double left = tt9_primary();
	Token t = tt9_ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= tt9_primary();
			t = tt9_ts.get();
			break;
		case '/':
		{
			double d = tt9_primary();
			if (d == 0)
				throw runtime_error("Divide by zero");
			left /= d;
			t = tt9_ts.get();
			break;
		}
		default:
			tt9_ts.putback(t);
			return left;
		}
	}
}
double tt9_primary() {
	Token t = tt9_ts.get();
	switch (t.kind) {
	case '(': //handle '(' expression ')'
	{
		double d = tt9_expression();
		t = tt9_ts.get();
		if (t.kind != ')')
			throw runtime_error("')' expected.");
		return d;
	}
	case '8':
		return t.value;
	default:
		throw runtime_error("Primary expected.");
	}
}
void TryThis9() {
	try {
		double val = 0;
		while (cin) {
			Token t = tt9_ts.get();
			if (t.kind == 'q')
				break;
			if (t.kind == ';')
				cout << "=" << val << '\n';
			else
				tt9_ts.putback(t);
			val = tt9_expression();
		}
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		return;
	}
	catch (...) {
		cerr << "unhandled exception..\n";
		return;
	}
}

///Drill

///Review

///Exercises

int main() {
	TryThis9(); // awaiting tt9 testing
	return 0;
}