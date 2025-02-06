import std;
using namespace std;

constexpr char calcnumber = '8',
calcquit = 'q',
calcprint = ';',
calclet = 'L',
calcname = 'a';
constexpr string_view calcprompt = "> ",
calcresult = "= ",
declkey = "let";

double define_name(string, double);

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
class Variable {
public:
	string name;
	double value;
};
vector<Variable> var_table;
double get_value(string s) {
	for (const Variable& v : var_table)
		if (v.name == s)
			return v.value;
	throw runtime_error("Trying to read undefined variable " + s);
}
void set_value(string s, double d) {
	for (Variable& v : var_table) {
		if (v.name == s) {
			v.value = d;
			return;
		}
	}
	throw runtime_error("Trying to write undefined variable " + s);
}

class Token {
public:
	char kind;
	double value;
	string name;
	Token()
		: kind{}, value{} {
	}
	Token(char k)
		: kind{ k }, value{ 0.0 } {
	}
	Token(char k, double v)
		: kind{ k }, value{ v } {
	}
	Token(char k, string n)
		: kind{ k }, name{ n } {
	}
};
class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);	//discard characters up to and including a c
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
void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	//now search input:
	char ch = 0;
	while (cin >> ch)
		if (ch == c)
			return;
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
	case '{': case '}':
	case '+': case '-':
	case '*': case '/':
	case '!':
	case '%':
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
		if (isalpha(ch)) {
			string s;
			s+=ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.putback(ch);
			if (s == declkey)
				return Token{ calclet };
			return Token{ calcname,s };
		}
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
void clear_all() {
	ts.ignore(calcprint);
}
double statement();
void calculate() {
	while (cin) try {
		cout << calcprompt;

		Token t = ts.get();
		while (t.kind == calcprint)
			t = ts.get();		//eat calcprints
		if (t.kind == calcquit)
			return;
		ts.putback(t);
		cout << calcresult << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clear_all();
	}
}
int Calc()
try
{
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n"
		<< "available operators: +,-,*,/,and ()\n"
		<< "to finish a statement and evaluate delimit with " << calcprint << "\n"
		<< "to exit enter " << calcquit << "\n";
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);

	calculate();
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
void clean_up_mess_bad() {
	while (true) {
		Token t = ts.get();
		if (t.kind == calcprint)
			return;
	}
}

/*
Grammar:::

Calculation:
	Statement
	Print
	Quit
	Calculation Statement

Statement:
	Declaration
	Expression
Declaration:
	"let" Name "=" Expression
*/

bool is_declared(string var) {
	for (const Variable& v : var_table)
		if (v.name == var)
			return true;
	return false;
}
double define_name(string var, double val) {
	if (is_declared(var))
		throw runtime_error(var + " declared twice");
	var_table.push_back(Variable{ var,val });
	return val;
}
double declaration()
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "Expression"
{
	Token t = ts.get();
	if (t.kind != calcname)
		throw runtime_error("Name expected in declaration");

	Token t2 = ts.get();
	if (t2.kind != '=')
		throw runtime_error("= missing in declaration of " + t.name);
	double d = expression();
	define_name(t.name, d);
	return d;

}
double statement() {
	Token t = ts.get();
	switch (t.kind) {
	case calclet:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

//trythis
void TryThis3() {
	//exercise
}

///Drill

///Review

///Exercises

int main() try {
	Calc();
	return 0;
}
catch (exception& e) {
	cerr << e.what();
	return -1;
}