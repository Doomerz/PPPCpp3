import std;
using namespace std;

namespace c6reading {
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
		Variable(string n, double v) :name(n), value(v) {}
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
				s += ch;
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
} //namespace c6reading

//trythis
void TryThis3() {
	//exercise
}

///Drill
namespace drill {
	/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/
	struct Token {
		char kind;
		double value;
		string name;
		Token(char ch) :kind(ch), value(0) {}
		Token(char ch, double val) :kind(ch), value(val) {}
		Token(char ch, string n) :kind(ch), name(n) {}
	};
	class Token_stream {
		bool full;
		Token buffer;
	public:
		Token_stream() :full(0), buffer(0) {}

		Token get();
		void putback(Token t);

		void ignore(char);
	};

	const char let = 'L';
	const char quit = 'Q';
	const char print = ';';
	const char number = '8';
	const char name = 'a';
	const char constant = 'C';
	const string declvar = "#"; //let
	const string quitstr = "exit";
	const string sqrtstr = "sqrt";
	const string powstr = "pow";
	const string conststr = "const";

	void Token_stream::putback(Token t) {
		if (full) throw runtime_error("Token_stream::putback already full buffer");
		buffer = t;
		full = true;
	}
	Token Token_stream::get()
	{
		if (full) { full = false; return buffer; }
		char ch;
		do {
			cin.get(ch);
			if (ch == '\n') return Token(print);
		} while (isspace(ch));
		switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case print:
		case '=': //for declaration and assignment
		case ',': //for func arguments
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.unget();
			double val;
			cin >> val;
			return Token(number, val);
		}
		case '#': //special let as #
			return Token(let);
		default:
			if (isalpha(ch) || ch == '_') {
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
				cin.unget();
				if (s == declvar) return Token(let); //won't occur because !isalpha('#')
				if (s == quitstr) return Token(quit);
				if (s == conststr) return Token(constant);
				return Token(name, s);
			}
			throw runtime_error("Bad token");
		}
	}
	void Token_stream::ignore(char c)
	{
		if (full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		char ch;
		while (cin >> ch)
			if (ch == c)
				return;
	}

	struct Variable {
		string name;
		double value;
		const bool constant;
		Variable(string n, double v) :name(n), value(v), constant(false) {}
		Variable(string n, double v, bool cnst) :name(n), value(v), constant(cnst) {}
	};
	struct Symbol_table {
		double get(string n);
		void set(string n, double v);
		bool is_declared(string n);
		void declare(string n, double v, bool constant);
		void reset();

		Symbol_table() {
			set_default();
		}
	private:
		void clear();
		void set_default();
		vector<Variable> var_table;
	};
	Symbol_table symbols;
	double Symbol_table::get(string n) {
		for (const Variable& v : var_table)
			if (v.name == n)
				return v.value;
		throw runtime_error("get: undefined name " + n);
	}
	void Symbol_table::set(string n, double v) {
		for (Variable& var : var_table) {
			if (var.name == n) {
				if (var.constant) throw runtime_error(n + " is constant and can't be changed");
				var.value = v;
				return;
			}
		}
		throw runtime_error("set: undefined name " + n);
	}
	bool Symbol_table::is_declared(string n) {
		for (const Variable& v : var_table)
			if (v.name == n)
				return true;
		return false;
	}
	void Symbol_table::declare(string n, double v, bool constant = false) {
		if (!is_declared(n))
			throw runtime_error(n + " already declared");
		var_table.push_back(Variable(n, v, constant));
	}
	void Symbol_table::reset() {
		clear();
		set_default();
	}
	void Symbol_table::clear() {
		var_table = vector<Variable>();
	}
	void Symbol_table::set_default() {
		var_table.push_back(Variable("k", 1000, true));
	}

	//double get_value(string s)
	//{
	//	for (int i = 0; i < names.size(); ++i)
	//		if (names[i].name == s)
	//			return names[i].value;
	//	throw runtime_error("get: undefined name " + s);
	//}
	//
	//void set_value(string s, double d)
	//{
	//	for (int i = 0; i < names.size(); ++i)
	//		if (names[i].name == s) {
	//			if (names[i].constant) throw runtime_error("can't set a constant variable " + s);
	//			names[i].value = d;
	//			return;
	//		}
	//	throw runtime_error("set: undefined name " + s);
	//}
	//
	//bool is_declared(string s)
	//{
	//	for (int i = 0; i < names.size(); ++i)
	//		if (names[i].name == s)
	//			return true;
	//	return false;
	//}

	Token_stream ts;

	double expression();

	double primary()
	{
		Token t = ts.get();
		switch (t.kind) {
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') throw runtime_error("')' expected");
		}
		case '-':
			return -primary();
		case number:
			return t.value;
		case name:
			if (t.name == sqrtstr) { //handle sqrt
				char c;
				c = cin.peek(); //doesn't skip whitespace
				if (c != '(') {
					return symbols.get(t.name);
				}
				double d = primary();
				if (d <= 0) throw runtime_error("can't sqrt <= 0");
				return sqrt(d);
			}
			if (t.name == powstr) { //handle power of (pow)
				char c;
				c = cin.peek();
				if (c != '(') {
					return symbols.get(t.name);
				}
				t = ts.get();
				double d = primary();
				t = ts.get();
				if (t.kind != ',') throw runtime_error("expected ',' in pow(x,i)");
				double i = primary();
				t = ts.get();
				if (t.kind != ')') throw runtime_error("expected ')' to end pow(x,i)");
				if (i != floor(i)) throw runtime_error("i in pow(x,i) must be an integer");
				return pow(d, i);
			}
			return symbols.get(t.name);
		default:
			throw runtime_error("primary expected");
		}
	}

	double term()
	{
		double left = primary();
		while (true) {
			Token t = ts.get();
			switch (t.kind) {
			case '*':
				left *= primary();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) throw runtime_error("divide by zero");
				left /= d;
				break;
			}
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	double expression()
	{
		double left = term();
		while (true) {
			Token t = ts.get();
			switch (t.kind) {
			case '+':
				left += term();
				break;
			case '-':
				left -= term();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	double declaration()
	{
		bool cnst = false;
		Token t = ts.get();
		if (t.kind == constant) {
			cnst = true;
			t = ts.get();
		}
		if (t.kind != name) throw runtime_error("name expected in declaration");
		string name = t.name;
		Token t2 = ts.get();
		if (t2.kind != '=') throw runtime_error("= missing in declaration of " + name);
		double d = expression();
		symbols.declare(name, d, cnst);
		return d;
	}

	double assignment(string name) {
		Token t = ts.get();
		if (t.kind != '=') throw runtime_error("assignment called without '='");
		symbols.set(name, expression());
	}

	double statement()
	{
		Token t = ts.get();
		switch (t.kind) {
		case let:
			return declaration();
		case name:
		{
			char c;
			if (!(cin.get(c))) throw runtime_error("unexpected eof");
			cin.unget();
			if (c == '=') {
				return assignment(t.name);
			}
			//intentional fall through.
		}
		default:
			ts.putback(t);
			return expression();
		}
	}

	void clean_up_mess()
	{
		symbols.reset();
		ts.ignore(print);
	}

	const string prompt = "> ";
	const string result = "= ";

	void calculate()
	{
		while (true) try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}

	int Calc()
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}

	//ex. 1
	// added constructor for Token for variables.
	//ex. 2&3
	// added error handling for putback when buffer is full
	// use non-magic characters for switch cases in ts.get() (print and quit chars)
	// missing '+' for += in ts.get()'s default switch case
	// for evaluating quit it was Token(name) but should be Token(quit) and made literal a variable
	// set_value for look had <= names.size() which would throw a range error
	// primary's throw on ')' expected using wrong '('
	// remove magic constant from declaration
	//ex. 4&5
	// skipped
	//ex. 6
	// added 'k' init Main (Calc)
	//ex. 7
	// added sqrt handling to primary
	//ex. 8
	// added sqrt error handling in primary
	//ex. 9
	// added pow handling into primary
	//ex. 10
	// updated let to #
	//ex. 11
	// changed quit to exit
}

///Review
//What is the purpose of working on the program after the first version works ? Give a list of reasons.
//
//Why does 1 + 2; q typed into the calculator not quit after it receives an error ?
//
//Why did we choose to make a constant character called number ?
//
//We split main() into two separate functions.What does the new function do and why did we split main() ?
//
//Why do we split code into multiple functions ? State principles.
//
//What is the purpose of commenting ?
//
//What is the use of symbolic constants ?
//
//Why do we care about code layout ?
//
//How do we handle % (remainder)of floating - point numbers ?
//
//What does is_declared() do and how does it work ?
//
//The input representation for let is more than one character.How is it accepted as a single token in the modified code ?
//
//What are the rules for what names can and cannot be in a calculator program ?
//
//Why is it a good idea to build a program incrementally ?
//
//When do you start to test ?
//
//When do you retest ?
//
//How do you decide what should be a separate function ?
//
//How do you choose names for variables and functions ? List possible reasons.
//
//What should be in comments and what should not?
//
//When do we consider a program finished ?
//

///Exercises
//ex1: added underscores to drill::calc
//ex2: added assignment, beware giving the ability to assign within expression!
//ex3: added *let* const var = expr logic
//ex4: defined Symbol_table and replaced var_table
//ex5: //TODO verify-- modify ts.get() to return Token(print) when it sees a newline. isspace(ch) might be helpful

namespace C6Calculator {
	//
} //namespace C6Calculator

int main() try {
	drill::Calc();
	return 0;
}
catch (exception& e) {
	cerr << e.what();
	return -1;
}

//finish chapter's completed calc
//resume 7.4.8 but all TT need to be done