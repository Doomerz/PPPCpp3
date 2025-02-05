import std;
using namespace std;

constexpr char calcnumber = '8',
calcquit = 'q',
calcprint = ';';
constexpr string_view calcprompt = "> ",
calcresult = "= "; // at pg254

//c5calc
int factorial(int n) { //warning! not overflow safe!
	if (n < 0) throw runtime_error("Cannot factorial negative integers");
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}
class c5Token {
public:
	char kind;
	double value;
	c5Token()
		: kind{}, value{} {
	}
	c5Token(char k)
		: kind{ k }, value{ 0.0 } {
	}
	c5Token(char k, double v)
		: kind{ k }, value{ v } {
	}
};
class c5Token_stream {
public:
	c5Token_stream();   // make a Token_stream that reads from cin
	c5Token get();      // get a Token (get() is defined elsewhere)
	void putback(c5Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	c5Token buffer;     // here is where we keep a Token put back using putback()
};
c5Token_stream::c5Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}
void c5Token_stream::putback(c5Token t)
{
	if (full) throw runtime_error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}
c5Token c5Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
	case '{': case '}': case '!':
		return c5Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return c5Token('8', val);   // let '8' represent "a number"
	}
	default:
		throw runtime_error("Bad token");
	}
}
c5Token_stream c5ts;
double c5expression();    // declaration so that primary() can call expression()
double c5primary()
{
	double d{}; //adjustment for adding factorial
	c5Token t = c5ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
		d = c5expression();
		t = c5ts.get();
		if (t.kind != ')')
			throw runtime_error("')' expected");
		break;
	case '{': //handle '{' expr '}'
		d = c5expression();
		t = c5ts.get();
		if (t.kind != '}')
			throw runtime_error("'}' expected");
		break;
	case '8':            // we use '8' to represent a number
		d = t.value;  // return the number's value
		break;
	default:
		throw runtime_error("primary expected");
	}
	t = c5ts.get();
	if (t.kind == '!') {
		if (d != floor(d))
			throw runtime_error("Can't factorial non-int numbers");
		d = factorial(static_cast<int>(d));
	}
	else
		c5ts.putback(t);
	return d;
}
double c5term()
{
	double left = c5primary();
	c5Token t = c5ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= c5primary();
			t = c5ts.get();
			break;
		case '/':
		{
			double d = c5primary();
			if (d == 0) throw runtime_error("divide by zero");
			left /= d;
			t = c5ts.get();
			break;
		}
		default:
			c5ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}
double c5expression()
{
	double left = c5term();      // read and evaluate a Term
	c5Token t = c5ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += c5term();    // evaluate Term and add
			t = c5ts.get();
			break;
		case '-':
			left -= c5term();    // evaluate Term and subtract
			t = c5ts.get();
			break;
		default:
			c5ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}
int c5Calc()
try
{
	double val;
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n"
		<< "available operators: +,-,*,/,and ()\n"
		<< "to finish a statement and evaluate delimit with '='\n"
		<< "to exit enter 'x'\n";
	while (cin) {
		c5Token t = c5ts.get();

		if (t.kind == 'x') break;
		if (t.kind == '=')
			cout << "=" << val << '\n';
		else
			c5ts.putback(t);
		val = c5expression();
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

///TryThis/Reading
class Token {
public:
	char kind;
	double value;
	Token()
		: kind{}, value{} {
	}
	Token(char k)
		: kind{ k }, value{ 0.0 } {
	}
	Token(char k, double v)
		: kind{ k }, value{ v } {
	}
};
class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}
void Token_stream::putback(Token t)
{
	if (full) throw runtime_error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}
Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case calcprint:    // for "print"
	case calcquit:    // for "quit"
	case '(': case ')':
	case '+': case '-':
	case '*': case '/':
	case '{': case '}':
	case '!': case '%':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token(calcnumber, val);   // let '8' represent "a number"
	}
	default:
		throw runtime_error("Bad token");
	}
}
Token_stream ts;
double expression();    // declaration so that primary() can call expression()
double primary()
{
	double d{}; //adjustment for adding factorial
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
		d = expression();
		t = ts.get();
		if (t.kind != ')')
			throw runtime_error("')' expected");
		break;
	case '{': //handle '{' expr '}'
		d = expression();
		t = ts.get();
		if (t.kind != '}')
			throw runtime_error("'}' expected");
		break;
	case calcnumber:            // we use '8' to represent a number
		d = t.value;  // return the number's value
		break;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		throw runtime_error("primary expected");
	}
	t = ts.get();
	if (t.kind == '!') {
		if (d != floor(d))
			throw runtime_error("Can't factorial non-int numbers");
		d = factorial(static_cast<int>(d));
	}
	else
		ts.putback(t);
	return d;
}
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) throw runtime_error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0)
				throw runtime_error("%:divide by zero");
			left = fmod(left, d); //x%y==x-y*int(x/y)
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}
int Calc()
try
{
	double val;
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n"
		<< "available operators: +,-,*,/,and ()\n"
		<< "to finish a statement and evaluate delimit with '='\n"
		<< "to exit enter 'x'\n";
	while (cin) {
		cout << "> ";

		Token t = ts.get();
		while (t.kind == calcprint)
			t = ts.get();		//eat calcprints
		if (t.kind == calcquit)
			return 0;
		ts.putback(t);
		cout << "= " << expression() << '\n';
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}
//reading

//trythis
void TryThis3() {
	//exercise
}
void TryThis();

///Drill

///Review

///Exercises

int main() try {
	TryThis3();
	return 0;
}
catch (exception& e) {
	cerr << e.what();
	return -1;
}