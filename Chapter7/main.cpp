import std;
using namespace std;

///TryThis
int f(int);
void TryThis2() {
	int i = 7;
	std::cout << f(i) << '\n';
}
namespace TryThis3 {
	struct X {
		void f(int x) {
			struct Y {
				int f() { return 1; }
				int m; //does nothing
			};
			int m; //never used?
			m = x; //never used?
			Y m2;
			return f(m2.f()); //simply loops infinitely
		}
		int m; //still not used
		void g(int m) {
			if (0 < m)
				f(m + 2); //just loops
			else {
				g(m + 2.3); //loops until m > 0 then infinitely loops
			}
		}
		X() {} //m not initialized
		int m3() {} //never used
		void main() {
			X a; //makes another struct of itself when main is called?
			a.f(2);
		}
	};
}
void TryThis4_7() {
	double y = 1001; //7.7; 'x';
	//int x = narrow<int>(y); not a viable one with just import std;
	//int x = round_to<int>(y); not a viable one with just import std;
	int x = floor(y);
	double z = double(x) / y;
	cout << x << ',' << y << ',' << z << endl;

	y = 7.7;
	x = floor(y);
	z = double(x) / y;
	cout << x << ',' << y << ',' << z << endl;

	y = 'x';
	x = floor(y);
	z = double(x) / y;
	cout << x << ',' << y << ',' << z << endl;
}

///Drill
namespace Drill {
	void swap_v(int a, int b) { int temp; temp = a, a = b; b = temp; }
	void swap_r(int& a, int& b) { int temp; temp = a, a = b; b = temp; }
	void swap_cr(const int& a, const int& b) { int temp; temp = a, a = b; b = temp; }

	void Drill1() {
		//TODO
		int x = 7;
		int y = 9;
		//swap_v(x, y);
		//swap_v(7, 9);
		//swap_r(x, y);
		//swap_r(7, 9);
		//swap_cr(x, y);
		//swap_cr(7, 9);
		const int cx = 7;
		const int cy = 9;
		//swap_v(cx, cy);
		//swap_v(7.7, 9.9);
		//swap_r(x, y);
		//swap_r(7, 9);
		//swap_cr(x, y);
		//swap_cr(7, 9);
		double dx = 7.7;
		double dy = 9.9;
		//swap_v(dx, dy);
		//swap_v(7.7, 9.9);
		//swap_r(x, y);
		//swap_r(7, 9);
		//swap_cr(x, y);
		//swap_cr(7, 9);
	}
} //namespace Drill

///Review
//What is the difference between a declaration and a definition ?
// 
//How do we syntactically distinguish between a function declaration and a function definition ?
// 
//How do we syntactically distinguish between a variable declaration and a variable definition ?
// 
//Why can’t you use the functions in the calculator program from Chapter 5 without declaring one or more of them first ?
// 
//Is int a; a definition or just a declaration ?
// 
//Why is it a good idea to initialize variables as they are declared ?
// 
//What can a function declaration consist of ?
// 
//What is the suffix return type notation, and why might you use it ?
// 
//What good does indentation do ?
// 
//What is the scope of a declaration ?
// 
//What kinds of scope are there ? Give an example of each.
// 
//What is the difference between a class scope and local scope ?
// 
//Why should a programmer minimize the number of global variables ?
// 
//What is the difference between pass - by - value and pass - by - reference ?
// 
//What is the difference between pass - by - reference and pass - by - constreference6] What is a swap() ?
// 
//Would you ever define a function with a vector<double> as a by - value parameter ?
// 
//Give an example of undefined order of evaluation.Why can undefined order of evaluation be a problem ?
// 
//What do x&& y and x || y, respectively, mean ?
// 
//Which of the following is standard - conforming C++ : functions within functions, functions within classes, classes within classes, classes within functions ?
// 
//What goes into an activation record ?
// 
//What is a call stack and why do we need one ?
// 
//What is the purpose of a namespace ?
// 
//How does a namespace differ from a class ?
// 
//What is a using declaration ?
// 
//Why should you avoid using directives in a header ?
// 
//What is namespace std ?
//

///Exercises
//ex1:
namespace C7Calculator {
	//Documentation

	///Grammar
	// Calculation:
	// quit
	// help
	// Statement
	// 
	// Statement:
	// Declaration
	// Assignment
	// Expression
	// 
	// Declaration:
	// const # var = Expression
	// # var = Expression
	// 
	// Assignment:
	// var = Expression
	// 
	// Expression:
	// Term
	// Term + Expression
	// Term - Expression
	// 
	// Term:
	// Primary
	// Term * Primary
	// Term / Primary
	// Term % Primary
	// 
	// Primary:
	// Number
	// Function
	// ( Expression )
	// -Primary
	// +Primary
	// 
	// Function:
	// sqrt ( Expression )
	// pow ( Expression , Expression )
	// 
	// Number:
	// floating-point-literal
	bool cout, cin, cerr;
	//Assignments
	const char quit = 'q';
	const char help = 'h';
	const char print = '\n';
	const char number = '1';
	const char name = 'a';
	const char let = '#';
	const char assign = '=';
	const char constant = 'c';
	const string helpstr = "help";
	const string prompt = "> ";
	const string result = "= ";
	const string quitstr = "exit";
	const string conststr = "const";
	//features
	const string sqrtstr = "sqrt";
	const string powstr = "pow";
	//Asserts

	//Documentation
	//Implementation
		//classes
	struct Token {
		char kind;
		double value;
		string name;
		Token(char ch) :kind(ch), value(0) {}
		Token(char ch, double val) :kind(ch), value(val) {}
		Token(char ch, string n) :kind(ch), name(n) {}
	};
	class Token_stream {
		istream& input;
		ostream& output;
		bool full;
		Token buffer;
	public:
		Token_stream(istream& is, ostream& os) :input(is), output(os), full(0), buffer(0) {}

		Token get();
		void putback(Token t);

		void ignore(char);
		void reset();
	};
	struct IO_Core {
		istream& input;
		ostream& output;
		Token_stream ts;

		IO_Core(istream& is, ostream& os)
			: input(is), output(os), ts(is, os) {
		}
	};
	typedef IO_Core& ioc;
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
	//class implementation
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
			input.get(ch);
			if (ch == print) return Token(print);
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
			input.unget();
			double val;
			input >> val;
			return Token(number, val);
		}
		case let:
			return Token(let);
		default:
			if (isalpha(ch) || ch == '_') {
				string s;
				s += ch;
				while (input.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
				input.unget();
				//if (s == declvar) return Token(let); //won't occur because !isalpha('#')
				if (s == quitstr) return Token(quit);
				if (s == conststr) return Token(constant);
				if (s == helpstr) return Token(help);
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
		while (input >> ch)
			if (ch == c)
				return;
	}
	void Token_stream::reset() {
		ignore(print);
	}
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
		var_table.push_back(Variable("pi", 3.1415926535, true));
		var_table.push_back(Variable("e", 2.7182818284, true));
	}

	//Globals
	Symbol_table symbols;

	//Functions
	int factorial(int n) { //warning! not overflow safe!
		if (n < 0) throw runtime_error("Cannot factorial negative integers");
		if (n == 0 || n == 1) return 1;
		return n * factorial(n - 1);
	}
	void print_help(ioc io) {
		io.output << "Welcome to our PPP integer calculator!\n"
			<< "available operators: +,-,*,/,%, and ()\n"
			<< "to finish a statement and evaluate delimit by pressing enter\n"
			<< "to exit enter " << quitstr << "\n"
			<< "To define a constant variable use: " << conststr << " " << let << " <var_name> " << assign << " <expression>\n"
			<< "To define a mutable variable drop the " << conststr << " you can re-assign these variables with <var_name> = <new_expression>\n";
		//supported operations
		//controls
		io.output << endl;
	}
	void clean_up_mess(ioc io)
	{
		symbols.reset();
		io.ts.reset();
	}
	double expression(ioc io);
	double primary(ioc io)
	{
		double d{};
		char c{};
		Token t = io.ts.get();
		switch (t.kind) {
		case '(':
		{
			d = expression(io);
			t = io.ts.get();
			if (t.kind != ')') throw runtime_error("')' expected");
			break;
		}
		case '-':
			d = -primary(io);
			break;
		case number:
			d = t.value;
			break;
		case name:
			if (t.name == sqrtstr) { //handle sqrt
				c = io.input.peek(); //doesn't skip whitespace
				if (c != '(') {
					return symbols.get(t.name);
				}
				d = primary(io);
				if (d <= 0) throw runtime_error("can't sqrt <= 0");
				d = sqrt(d);
				break;
			}
			if (t.name == powstr) { //handle power of (pow)
				c = io.input.peek();
				if (c != '(') {
					return symbols.get(t.name);
				}
				t = io.ts.get();
				d = primary(io);
				t = io.ts.get();
				if (t.kind != ',') throw runtime_error("expected ',' in pow(x,i)");
				double i = primary(io);
				t = io.ts.get();
				if (t.kind != ')') throw runtime_error("expected ')' to end pow(x,i)");
				if (i != floor(i)) throw runtime_error("i in pow(x,i) must be an integer");
				d = pow(d, i);
				break;
			}
			d = symbols.get(t.name);
			break;
		default:
			throw runtime_error("primary expected");
		}
		c = io.input.peek();
		if (c == '!') {
			if (d != floor(d))
				throw runtime_error("Can't factorial non-int numbers");
			d = factorial(static_cast<int>(d));
		}
		return d;
	}
	double term(ioc io)
	{
		double left = primary(io);
		while (true) {
			Token t = io.ts.get();
			switch (t.kind) {
			case '*':
				left *= primary(io);
				break;
			case '/':
			{
				double d = primary(io);
				if (d == 0) throw runtime_error("divide by zero");
				left /= d;
				break;
			}
			default:
				io.ts.putback(t);
				return left;
			}
		}
	}
	double expression(ioc io)
	{
		double left = term(io);
		while (true) {
			Token t = io.ts.get();
			switch (t.kind) {
			case '+':
				left += term(io);
				break;
			case '-':
				left -= term(io);
				break;
			default:
				io.ts.putback(t);
				return left;
			}
		}
	}
	double assignment(ioc io, string name) {
		Token t = io.ts.get();
		if (t.kind != assign) throw runtime_error("assignment called without '='");
		symbols.set(name, expression(io));
		return symbols.get(name);
	}
	double declaration(ioc io)
	{
		bool cnst = false;
		Token t = io.ts.get();
		if (t.kind == constant) {
			cnst = true;
			t = io.ts.get();
		}
		if (t.kind != name) throw runtime_error("name expected in declaration");
		string name = t.name;
		Token t2 = io.ts.get();
		if (t2.kind != assign) throw runtime_error(to_string(assign) + " missing in declaration of " + name);
		double d = expression(io);
		symbols.declare(name, d, cnst);
		return d;
	}
	double statement(ioc io)
	{
		Token t = io.ts.get();
		switch (t.kind) {
		case let:
			return declaration(io);
		case name:
		{
			char c;
			c = io.input.peek();
			if (!io.input) throw runtime_error("unexpected eof");
			if (c == assign) {
				return assignment(io, t.name);
			}
			//intentional fall through.
		}
		//intentional fall through.
		default:
			io.ts.putback(t);
			return expression(io);
		}
	}
	void calculator(ioc io)
	{
		io.output << "Enter " << helpstr << " for help." << endl;
		while (true) try {
			io.output << prompt;
			Token t = io.ts.get();
			while (t.kind == print) t = io.ts.get(); //consume empty statements
			if (t.kind == quit) return; //is this quit?
			//help; this can be easier if we could putback a couple tokens and we just check help then print
			if (t.kind == help) {
				char c;
				do {
					io.input.get(c);
					if (c == print)
						break;
				} while (isspace(c));
				if (c == print) { //not taking print tokens, it has to be helpstr\n
					print_help(io);
					continue;
				}
				io.input.unget();
			}
			io.ts.putback(t);
			io.output << result << statement(io) << endl;
		}
		catch (runtime_error& e) {
			io.output << e.what() << endl;
			clean_up_mess(io);
		}
	}
	int Calc(istream& input_stream, ostream& output_stream)
		try {
		IO_Core io(input_stream, output_stream);
		calculator(io);
		return 0;
	}
	catch (exception& e) {
		output_stream << "exception: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		output_stream << "exception" << endl;
		return 2;
	}
} //namespace C6Calculator
//ex2:


///Main
int main() try {
	Drill::Drill1();
	return 0;
}
catch (exception& e) {
	cout << "Exception: " << e.what() << endl;
	return -1;
}
catch (...) {
	cout << "unhandled exception" << endl;
	return -2;
}

//resume 7.4.8 but all TT need to be done pg 308