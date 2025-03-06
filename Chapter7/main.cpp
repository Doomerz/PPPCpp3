import std;
using namespace std;

///TryThis
int f(int) { return 1; }
void TryThis2() {
	int i = 7;
	std::cout << f(i) << '\n';
}
namespace TryThis3 {
	//struct X {
	//	void f(int x) {
	//		struct Y {
	//			int f() { return 1; }
	//			int m; //does nothing
	//		};
	//		int m; //never used?
	//		m = x; //never used?
	//		Y m2;
	//		return f(m2.f()); //simply loops infinitely
	//	}
	//	int m; //still not used
	//	void g(int m) {
	//		if (0 < m)
	//			f(m + 2); //just loops
	//		else {
	//			g(m + 2.3); //loops until m > 0 then infinitely loops
	//		}
	//	}
	//	X() {} //m not initialized
	//	int m3() {} //never used
	//	void main() {
	//		X a; //makes another struct of itself when main is called?
	//		a.f(2);
	//	}
	//};
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
void d3test();
void d4test();
namespace Drill {
	void swap_v(int a, int b) { int temp; temp = a, a = b; b = temp; }
	void swap_r(int& a, int& b) { int temp; temp = a, a = b; b = temp; }
	//void swap_cr(const int& a, const int& b) { int temp; temp = a, a = b; b = temp; } //always throws compiler error, can't swap const

	void Drill1() {
		//TODO
		int x = 7;
		int y = 9;
		//swap_v(x, y); //7|9
		//swap_v(7, 9); //compiles but nothing happens
		//swap_r(x, y); //9|7 works!
		//swap_r(7, 9); //cannot convert argument from literal int to int&
		//swap_cr(x, y); //never compiles
		//swap_cr(7, 9); //never compiles
		cout << x << '|' << y << endl;
		const int cx = 7;
		const int cy = 9;
		//swap_v(cx, cy); //7|9
		//swap_v(7.7, 9.9); //compiles but nothing happens
		//swap_r(cx, cy); //cannot convert argument from const int to int&
		//swap_r(7.7, 9.9); //cannot convert argument from literal int to int&
		//swap_cr(x, y); //never compiles
		//swap_cr(7.7, 9.9); //never compiles
		cout << cx << '|' << cy << endl;
		double dx = 7.7;
		double dy = 9.9;
		//swap_v(dx, dy); //7.7|9.9 //not even narrowed!?
		//swap_v(7.7, 9.9); //compiles but nothing happens
		//swap_r(dx, dy); //cannot convert argument from double to int&
		//swap_r(7.7, 9.9); //cannot convert argument from literal int to int&
		//swap_cr(x, y); //never compiles
		//swap_cr(7.7, 9.9); //never compiles
		cout << dx << '|' << dy << endl;
	}

	namespace X {
		int var;
		void print() { cout << var << endl; }
	}
	namespace Y {
		int var;
		void print() { cout << var << endl; }
	}
	namespace Z {
		int var;
		void print() { cout << var << endl; }
	}
	void Drill2() {
		X::var = 7;
		X::print(); // print X’s var
		using namespace Y;
		var = 9;
		print(); // print Y’s var
		{
			using Z::var;
			using Z::print;
			var = 11;
			print(); // print Z’s var
		}
		print(); // print Y’s var
		X::print(); // print X’s var
	}
	void Drill3() {
		d3test();
	}
	void Drill4() {
		d4test();
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
void c7e2print(const string& label, const vector<int>& data) {
	cout << "Dataset: " << label << endl;
	for (const int& i : data)
		cout << ' ' << i << '\n';
}
//ex3:
void fibonacci(const int& x, const int& y,vector<int>& v,const unsigned int& n) {
	if (v.size() != 0) throw runtime_error("Expected empty vector");
	v.reserve(n);
	if (n > 0) v.push_back(x);
	if (n > 1) v.push_back(y);
	for (int i{ 2 }; i < n; i++)
		v.push_back(v[i-1] + v[i - 2]);
}
void c7e3() {
	int x = 1, y = 1;
	unsigned int n = 20;
	vector<int> v;
	fibonacci(x, y, v, n);
	c7e2print("fib" + to_string(x) + "," + to_string(y) + "w/" + to_string(n), v);
}
//ex4:
void c7e4() {
	vector<int> v;
	int i{ 1 };
	v.reserve(64);
	v.push_back(1);
	v.push_back(1);
	cout << "1\t\t1\n2\t\t1\n";
	while (v[v.size() - 1] < numeric_limits<int>::max() / 2) {
		i++;
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);
		cout << i << "\t\t" << v[v.size() - 1] << endl;
	}
	cout << "Max fib=" << i << '|' << v[v.size() - 1] << endl;
	//max is 45@1134903170
}
//ex5:
vector<int> e5newreverse(const vector<int>& v) {
	vector<int> res;
	res.reserve(v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		res.emplace_back(v[i]);
	return res;
}
void e5swapreverse(vector<int>& v) {
	for (int i{}, k = v.size() - 1; i < k; i++, k--)
		swap(v[i], v[k]);
}
void c7e5() {
	vector<int> v = { 1,3,5,7,9 };
	c7e2print("starting", v);
	c7e2print("result of e5newreverse", e5newreverse(v));
	e5swapreverse(v);
	c7e2print("after e5swapreverse", v);
}
//ex6:
vector<string> e6newreverse(const vector<string>& v) {
	vector<string> res;
	res.reserve(v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		res.emplace_back(v[i]);
	return res;
}
void e6swapreverse(vector<string>& v) {
	for (int i{}, k = v.size() - 1; i < k; i++, k--)
		swap(v[i], v[k]);
}
void e6print(string label, const vector<string>& data) {
	cout << label << endl;
	for (const string& i : data)
		cout << ' ' << i << '\n';
}
void c7e6() {
	vector<string> v = { "1","3","5","7","9" };
	e6print("starting", v);
	e6print("result of e5newreverse", e6newreverse(v));
	e6swapreverse(v);
	e6print("after e5swapreverse", v);
}
//ex7:
vector<string> e7input(bool use_default = false) {
	if (use_default) {
		return vector<string>{"b", "a", "c", "e", "d"};
	}
	vector<string> res;
	res.reserve(5);
	cout << "Enter 5 names:\n";
	while (res.size() < 5) {
		string input;
		cin >> input;
		cout << "added " << input << endl;
		res.push_back(input);
	}
	cout << "\n\n";
	return res;
}
double e7getage(const string& name) {
	double res;
	string s;
	size_t idx;
	bool valid = false;
	while (!valid) {
		cout << "Please enter a valid age for\n" << name << ": ";
		try {
			getline(cin, s);
			res = stod(s, &idx);
			if (idx != s.size())
				throw runtime_error("Entry contained additional characters after number");
			else if (res < 0) {
				throw runtime_error("Age cannot be < 0");
			}
			else
				valid = true;
		}
		catch (exception& e) {
			string err;
			if (e.what() == "invalid stod argument")
				err = "Entry not a number.";
			else if (e.what() == "stod argument out of range")
				err = "Entry does not fit in double.";
			else
				err = e.what();
			cerr << "Invalid input: " << e.what() << "\nTry again:\n";
		}
	}
	return res;
}
vector<double> e7ages(const vector<string>& name, bool use_default = false) {
	if (use_default)
		return vector<double>{2, 1, 3, 5, 4};
	vector<double> res;
	res.reserve(name.size());
	for (const string& n : name) {
		res.push_back(e7getage(n));
	}
	return res;
}
void c7e7(bool use_default = true) {
	//read 5 names into a vec<str> name;
	//prompt for ages of each and store ages in a vector of doubles (age)
	//print out the 5 name/age pairs, sort the name/age pairs (std::sort) and then print
	//hint: make a copy before sorting and use that to order the age vector
	vector<string> name = e7input(use_default);
	vector<double> age = e7ages(name, use_default);
	cout << "Our list is: \n";
	for (int i{}; i < name.size(); i++) {
		cout << name[i] << ": " << age[i] << endl;
	}
	vector<string> temp = name;
	sort(name.begin(), name.end());
	
	for (int i{}; i < name.size(); i++) {
		for (int k{i+1}; k < temp.size(); k++) { //not best
			if (name[i] != temp[k]) continue;
			if (i == k) break;
			swap(age[i], age[k]);
			swap(temp[i], temp[k]);
		}
	}
	cout << "Our sorted list is: \n";
	for (int i{}; i < name.size(); i++)
		cout << name[i] << ": " << age[i] << endl;
}
//ex8:
vector<string> e8input(bool use_default = false) {
	if (use_default) {
		return vector<string>{"b", "a", "c", "e", "d"};
	}
	vector<string> res;
	cout << "Enter names, end by entering an empty string:\n";
	while (true) {
		string input;
		getline(cin, input);
		if (input == "")
			break;
		cout << "added " << input << endl;
		res.push_back(input);
	}
	cout << "\n\n";
	return res;
}
double e8getage(const string& name) {
	double res;
	string s;
	size_t idx;
	bool valid = false;
	while (!valid) {
		cout << "Please enter a valid age for\n" << name << ": ";
		try {
			getline(cin, s);
			res = stod(s, &idx);
			if (idx != s.size())
				throw runtime_error("Entry contained additional characters after number");
			else if (res < 0) {
				throw runtime_error("Age cannot be < 0");
			}
			else
				valid = true;
		}
		catch (exception& e) {
			string err;
			if (e.what() == "invalid stod argument")
				err = "Entry not a number.";
			else if (e.what() == "stod argument out of range")
				err = "Entry does not fit in double.";
			else
				err = e.what();
			cerr << "Invalid input: " << e.what() << "\nTry again:\n";
		}
	}
	return res;
}
vector<double> e8ages(const vector<string>& name, bool use_default = false) {
	if (use_default)
		return vector<double>{2, 1, 3, 5, 4};
	vector<double> res;
	res.reserve(name.size());
	for (const string& n : name) {
		res.push_back(e8getage(n));
	}
	return res;
}
void c7e8(bool use_default = false) {
	//make e7 take arbitrary number of names
	vector<string> name = e8input(use_default);
	vector<double> age = e8ages(name, use_default);
	cout << "Our list is: \n";
	for (int i{}; i < name.size(); i++) {
		cout << name[i] << ": " << age[i] << endl;
	}
	vector<string> temp = name;
	sort(name.begin(), name.end());

	for (int i{}; i < name.size(); i++) {
		for (int k{ i + 1 }; k < temp.size(); k++) {
			if (name[i] != temp[k]) continue;
			if (i == k) break;
			swap(age[i], age[k]);
			swap(temp[i], temp[k]);
		}
	}
	cout << "Our sorted list is: \n";
	for (int i{}; i < name.size(); i++)
		cout << name[i] << ": " << age[i] << endl;
}
//ex9:
double e9index(const vector<double>& price, const vector<double>& weight) {
	if (price.size() != weight.size())
		throw runtime_error("vector sizes do not match e9index");
	double sum{};
	for (int i{}; i < price.size(); i++) {
		sum += price[i] * weight[i];
	}
	return sum;
}
void c7e9() {
	//write func that given two vec<double> (price and weight) compute the sum of all price*weight elements
	//ensure vector sizes match
	vector<double> price{ 5,10,15,20 },
		weight{ 4,3,2,1 };
	cout << "index of default for e9 is: " << e9index(price, weight) << endl;
}
//ex10:
template<typename T>
T maxv(vector<T> v) {
	if (v.size() == 0)
		throw runtime_error("maxv: vector size cannot be 0");
	if (v.size() == 1)
		return v[0];
	int max;
	max = 0;
	for (int i{1}; i < v.size(); i++)
		if (v[max] < v[i])
			max = i;
	return v[max];
}
void c7e10() {
	//write func maxv() that returns the largest element of a vector
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	cout << "max of c7e10 default is " << maxv(v) << endl;
}
//ex11:
template<typename T>
void vecstat_ref(const vector<T>& v, T& max, T& min, T& mean, T& median) {
	if (v.size() == 0)
		throw runtime_error("vecstat can't use empty vector");
	max = v[0];
	min = v[0];
	if (v.size() == 1) {
		median = v[0];
		mean = v[0];
		return;
	}
	vector<T> x = v;
	sort(x.begin(), x.end());
	median = x[x.size() / 2];
	max = x[x.size() - 1];
	min = x[0];
	mean = 0;
	for (const T& e : v) {
		mean += e;
	}
	mean /= v.size();
	return;
}
template<typename T>
struct e11struct {
	T max, min, mean, median;
};
template<typename T>
e11struct<T> vecstat_struct(const vector<T>& v) {
	e11struct<T> res;
	vecstat_ref(v, res.max, res.min, res.mean, res.median);
	return res;
}
void c7e11() {
	//write a func that finds the smallest and largest element of a vec
	//also computer the mean and median
	//do not use globals
	//
	// Comments:
	// by ref makes writing and composing functions a bit messy
	// however returning a struct can bloat a lot of different structs, but only takes additional work within the function using it.
	vector<int> data{ 1,2,3,4,5,6,7,8,9 };
	e11struct<int> ans = vecstat_struct(data);
	cout << "our data is: 1,2,3,4,5,6,7,8,9\n"
		<< "max = " << ans.max
		<< "\nmin = " << ans.min
		<< "\nmean = " << ans.mean
		<< "\nmedian = " << ans.median << endl;
}
//ex12:
void print_until(vector<string> v, string quit) {
	for (string s : v) {
		if (s == quit)
			return;
		cout << s << '\n';
	}
}
void print_until_s(const vector<string>& v, const string& quit) {
	for (const string& s : v) {
		if (s == quit)
			return;
		cout << s << '\n';
	}
}
void print_until_ss(const vector<string>& v, const string& quit) {
	bool second = false;
	for (const string& s : v) {
		if (s == quit) {
			if (second)
				return;
			second = true;
		}
		cout << s << '\n';
	}
}
void c7e12() {
	//improve print_until_s from 7.4.2
	//test it, what makes a good set of test cases?
	//write print_until_ss that prints until it hits a second occurance of the quit argument
}
//ex13:
void c7e13() {
	//write a func that takes vec<str> and returns vec<int> containing number of char in each str.
	// find longest and shortest str and lexicographically first and last str.
	// how many separate funcs would we use for these tasks and why
	vector<string> vs{ "There", "is", "no", "one", "who", "loves", "pain", "itself,", "who", "seeks", "after", "it", "and", "wants", "to", "have", "it,", "simply", "because", "it", "is", "pain..." };
	vector<int> vi;
	string longest{vs[0]}, shortest{ vs[0] }, first{ vs[0] }, last{ vs[0] };
	vi.reserve(vs.size());
	vi.push_back(vs[0].size());
	for (int i{1}; i < vs.size(); i++) {
		vi.push_back(vs[i].size());
		if (vs[i].size() > longest.size())
			longest = vs[i];
		else if (vs[i].size() < shortest.size())
			shortest = vs[i];
		if (vs[i] < first)
			first = vs[i];
		else if (vs[i] > last)
			last = vs[i];
	}
	cout << "our vectors are:\n";
	for (int i{}; i < vs.size(); i++)
		cout << vi[i] << "|" << vs[i] << endl;
	cout << "longest@" << longest.size() << "|" << longest << endl
		<< "shortest@" << shortest.size() << "|" << shortest << endl
		<< "first=" << first << endl
		<< "last =" << last << endl;
	//just needed the one function otherwise we'd have to iterate through the vector a lot more and the logic for each step wasn't so complex as to not be readable in line.
	//if we needed to evaluate lexicographical order with case-insensitive then we'd likely have a function to evaluate that.
}
//ex14:
void fe14(const int x) {
	cout << x << endl;
}
void c7e14() {
	//can we declare a non-ref func arg const (void f(const int);)
	// what might that mean?
	// why might we want to do that?
	// why don't people do that often?
	// 
	// it means copy the value, but don't allow it to change in the function
	// we might do that to ensure that the root copy that is passed to sub-functions doesn't change as it is passed to subsequent sub-functions.
	// Since the value is just a copy the original passed value is not changed anyways. At this point we might as well make it a const-reference and save the trouble of copying it unnecessarily.
	fe14(2);
}

///Main
int main() try {
	c7e14();
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