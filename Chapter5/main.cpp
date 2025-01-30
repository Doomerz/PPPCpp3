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
	Token()
		: kind{}, value{} {}
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
class dToken{ //missing 'c' in class
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	dToken(char ch)    // make a Token from a char
		:kind(ch), value(0) {}
	dToken(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) {}
};
class dToken_stream {
public:
	dToken_stream();   // make a Token_stream that reads from cin
	dToken get();      // get a Token (get() is defined elsewhere)
	void putback(dToken t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	dToken buffer;     // here is where we keep a Token put back using putback()
};
dToken_stream::dToken_stream()
	:full(false), buffer(0)    // no Token in buffer
{}
void dToken_stream::putback(dToken t)
{
	if (full) throw runtime_error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}
dToken dToken_stream::get() //missing Token_stream scope for get's definition
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
		return dToken(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': //missing case '8' or token_stream::get()
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return dToken('8', val);   // let '8' represent "a number"
	}
	default:
		throw runtime_error("Bad token");
	}
}
dToken_stream dts;        // provides get() and putback() 
double dexpression();    // declaration so that primary() can call expression()
double dprimary()
{
	dToken t = dts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = dexpression();
		t = dts.get();
		if (t.kind != ')')
			throw runtime_error("')' expected"); //missing closing '"' for string literal in throw for ')' expected
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		throw runtime_error("primary expected");
	}
}
double dterm()
{
	double left = dprimary();
	dToken t = dts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= dprimary();
			t = dts.get();
			break; //missing break for '*' case
		case '/':
		{
			double d = dprimary();
			if (d == 0) throw runtime_error("divide by zero");
			left /= d;
			t = dts.get();
			break;
		}
		default:
			dts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}
double dexpression()
{ //missing closing paranthesis for start of expression()'s first call to term()
	double left = dterm();      // read and evaluate a Term
	dToken t = dts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += dterm();    // evaluate Term and add
			t = dts.get();
			break;
		case '-':
			left -= dterm();    // evaluate Term and subtract
			t = dts.get(); //used += instead of -= for '-' case in expression
			break;
		default:
			dts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}
int Drill()
//missing 'c' in class Token
//missing Token_stream scope for get's definition
//missing closing '"' for string literal in throw for ')' expected
//missing closing paranthesis for start of expression()'s first call to term()
//missing definition of val in main

//missing case '8' or token_stream::get()
//missing break for '*' case
//used += instead of -= for '-' case in expression

///drill pt2: replace 'q' with 'x' for main and Token_stream::get()
///drill pt3: replace ';' with '=' same places as pt2
///drill pt4: add opening cout in main:
///drill pt5: including operator details and how to print and exit.
try
{
	double val;
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n"
		<< "available operators: +,-,*,/,and ()\n"
		<< "to finish a statement and evaluate delimit with '='\n"
		<< "to exit enter 'x'\n";
	while (cin) {
		dToken t = dts.get();

		if (t.kind == 'x') break; // 'q' for quit
		if (t.kind == '=')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			dts.putback(t);
		val = dexpression();
	}
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

///Review

///What do we mean by “Programming is understanding”?
///
///The chapter details the creation of a calculator program.Write a short analysis of what the calculator should be able to do.
///
///How do you break a problem up into smaller manageable parts ?
///
///Why is creating a small, limited version of a program a good idea ?
///
///Why is feature creep a bad idea ?
///
///What are the three main phases of software development ?
///
///What is a “use case” ?
///
///What is the purpose of testing ?
///
///According to the outline in the chapter, describe the difference between a Term, an Expression, a Number, and a Primary.
///
///In the chapter, an input was broken down into its components : Terms, Expressions, Primarys, and Numbers.Do this for (17 + 4) / (5−1).
///
///Why does the program not have a function called number() ?
///
///What is a token ?
///
///What is a grammar ? A grammar rule ?
///
///What is a class ? What do we use classes for ?
///
///How can we provide a default value for a member of a class ?
///
///In the expression function, why is the default for the switch - statement to “put back” the token ?
///
///What is “look - ahead” ?
///
///What does putback() do and why is it useful ?
///
///Why is the remainder(modulus) operation, %, difficult to implement in the term() ?
///
///What do we use the two data members of the Token class for ?
///
///Why do we(sometimes) split a class’s members into private and public members ?
///
///What happens in the Token_stream class when there is a token in the buffer and the get() function is called ?
///
///Why were the ';' and 'q' characters added to the switch - statement in the get() function of the Token_stream class ?
///
///When should we start testing our program ?
///
///What is a “user - defined type” ? Why would we want one ?
///
///What is the interface to a C++ “user - defined type” ?
///
///Why do we want to rely on libraries of code ?
///

///Exercises
int factorial(int n);
//EX1 complete
//Current Calculator
///Token is above
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
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
	case '{': case '}': case '!':
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
Token_stream ts;        // provides get() and putback() 
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
	case '8':            // we use '8' to represent a number
		d = t.value;  // return the number's value
		break;
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
		Token t = ts.get();

		if (t.kind == 'x') break;
		if (t.kind == '=')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
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
void c5e2() {
	Calc();
	//add {} functionality
}
int factorial(int n) { //warning! not overflow safe!
	if (n < 0) throw runtime_error("Cannot factorial negative integers");
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}
void c5e3() {
	Calc();
	//add factorial functionality
}
class Name_value {
public:
	string name{};
	int value{};

	Name_value(string s, int v)
		: name{ s }, value{ v } {}
};
void c3e20() {
	vector<string> names;
	vector<int> scores;
	string str;
	int x;
	bool found;

	cout << "Enter a user name followed by score separated by a space. Terminate with input: \"NoName 0\"\n";

	while (true) {
		//get string
		if (!(cin >> str)) {
			cout << "unexpected end of file";
			return;
		}
		//get int
		if (!(cin >> x)) {
			cout << "bad input detected. closing application.";
			return;
		}
		//check for end
		if (str == "NoName" && x == 0)
			break;
		//check for duplicate
		for (auto s : names) {
			if (s == str) {
				cout << "Duplicate detected. closing application.";
				return;
			}
		}
		names.push_back(str);
		scores.push_back(x);
	}
	cout << "input complete\nwhat score would you like to know who got it?\n";
	while (true) {
		found = false;
		cout << ">>";
		if (!(cin >> x)) {
			cout << "invalid input.";
			return;
		}
		for (int i{}; i < names.size(); i++) {
			if (scores[i] == x) {
				if (found)
					cout << ", ";
				found = true;
				cout << names[i];
			}
		}
		if (!found) {
			cout << "none";
		}
		cout << endl;
	}
}
void c5e4() {
	//make a name_value class that holds a string and a value.
	//rework c3e20 to use vector<Name_value> instead of two vectors
	vector<Name_value> v;
	string str;
	int x;
	bool found;

	cout << "Enter a user name followed by score separated by a space. Terminate with input: \"NoName 0\"\n";

	while (true) {
		//get string
		if (!(cin >> str)) {
			cout << "unexpected end of file";
			return;
		}
		//get int
		if (!(cin >> x)) {
			cout << "bad input detected. closing application.";
			return;
		}
		//check for end
		if (str == "NoName" && x == 0)
			break;
		//check for duplicate
		for (auto s : v) {
			if (s.name == str) {
				cout << "Duplicate detected. closing application.";
				return;
			}
		}
		Name_value n{ str,x };
		v.push_back(n);
	}
	cout << "input complete\nwhat score would you like to know who got it?\n";
	while (true) {
		found = false;
		cout << ">>";
		if (!(cin >> x)) {
			cout << "invalid input.";
			return;
		}
		for (int i{}; i < v.size(); i++) {
			if (v[i].value == x) {
				if (found)
					cout << ", ";
				found = true;
				cout << v[i].name;
			}
		}
		if (!found) {
			cout << "none";
		}
		cout << endl;
	}
}
void c5e5() {
	//write grammar for bitwise logical expressions
	//!,~,&,|,^
	//^ before |
	//& before ^
	//! and ~ are unary like - before a number

	//Expression:
	// Term
	// Expression "|" term
	//Term:
	// Primary
	// Term "^" Primary
	//Primary:
	// Value
	// Primary "&" Value
	//Value:
	// Number
	// "!" Value
	// "~" Value
	// "(" Expression ")"
	//Number:
	// Integer Literal
	cout << "see source";
}
void c4e12() {
	default_random_engine e;
	uniform_int_distribution<int> dist(0, 9);
	e.seed(chrono::system_clock::now().time_since_epoch().count());

	vector<int> answer{ dist(e),dist(e),dist(e),dist(e) };

	cout << "Welcome to bulls and cows!\nThere are 4 numbers 0-9 and you gotta guess 'em!\nIf you get a number right but it is in the wrong place, that's a cow\nGet a number right where it needs to be, that's a bull. You want 4 bulls.\n";
	for (int moves{ 1 }; true; moves++) {
		string input{};
		bool chk = false;
		cout << ">> ";
		getline(cin, input);
		if (input.size() != 4) {
			cout << "Bad input length!\n";
			moves--;
			continue;
		}
		for (auto& c : input) {
			if (c < '0' || c > '9') {
				chk = true;
				break;
			}
		}
		if (chk) {
			cout << "Bad input value!\n";
			moves--;
			continue;
		}
		//eval bulls and cows
		vector<bool> bulls{ false,false,false,false }, cow;
		uint8_t bullc{}, cows{};
		for (int i{}; i < answer.size(); i++) {
			if (input[i] == answer[i] + '0') {
				bulls[i] = true;
			}
		}
		for (const auto& i : bulls)
			if (i)
				bullc++;
		cow = bulls;
		for (int i{}; i < answer.size(); i++) {
			if (bulls[i])
				continue;
			for (int k{}; k < answer.size(); k++) {
				if (bulls[k])
					continue;
				if (input[i] == answer[k] + '0') {
					if (!cow[k]) {
						cow[k] = true;
						cows++;
					}
				}
			}
		}
		if (bullc == 4) {
			cout << "Congratulations! You got it in only " << moves << " move" << (moves == 1 ? "" : "s") << "!\n";
			break;
		}
		cout << "You have " << bullc << " Bulls and " << cows << " Cows.\n";
	}
	//cows and bulls
	//bulls is right
	//cows is right num, wrong place.
}
void c5e6() {
	default_random_engine e;
	uniform_int_distribution<int> dist(0, 25);
	e.seed(chrono::system_clock::now().time_since_epoch().count());

	vector<int> answer{ dist(e),dist(e),dist(e),dist(e) };

	cout << "Welcome to bulls and cows!\nThere are 4 lowercase letters a-z and you gotta guess 'em!\nIf you get a letter right but it is in the wrong place, that's a cow\nGet a letter right where it needs to be, that's a bull. You want 4 bulls.\n";
	for (int moves{ 1 }; true; moves++) {
		string input{};
		bool chk = false;
		cout << ">> ";
		getline(cin, input);
		if (input.size() != 4) {
			cout << "Bad input length!\n";
			moves--;
			continue;
		}
		for (auto& c : input) {
			if (c < 'a' || c > 'z') {
				chk = true;
				break;
			}
		}
		if (chk) {
			cout << "Bad input value!\n";
			moves--;
			continue;
		}
		//eval bulls and cows
		vector<bool> bulls{ false,false,false,false }, cow;
		uint8_t bullc{}, cows{};
		for (int i{}; i < answer.size(); i++) {
			if (input[i] == answer[i] + 'a') {
				bulls[i] = true;
			}
		}
		for (const auto& i : bulls)
			if (i)
				bullc++;
		cow = bulls;
		for (int i{}; i < answer.size(); i++) {
			if (bulls[i])
				continue;
			for (int k{}; k < answer.size(); k++) {
				if (bulls[k])
					continue;
				if (input[i] == answer[k] + 'a') {
					if (!cow[k]) {
						cow[k] = true;
						cows++;
					}
				}
			}
		}
		if (bullc == 4) {
			cout << "Congratulations! You got it in only " << moves << " move" << (moves == 1 ? "" : "s") << "!\n";
			break;
		}
		cout << "You have " << bullc << " Bulls and " << cows << " Cows.\n";
	}
	//cows and bulls
	//bulls is right
	//cows is right num, wrong place.
}
void c5e7() {
	cout << "enter up to a four digit integer" << endl;
	char c;
	int total{}, temp{};
	for (int i{}; i < 4; i++) {
		if (!(cin >> c)) {
			if (i)
				break;
			throw runtime_error("Unexpected eof");
		}
		if (c < '0' || c > '9') {
			//TODO
		}
	}

	//results
	cout << total << "is ";
	temp = total / 1000;
	if (temp) {
		cout << temp << " thousand and ";
	}
	total -= temp * 1000;
	temp = total / 100;
	if (temp) {
		cout << temp << " hundred and ";
	}
	total -= temp * 100;
	temp = total / 10;
	if (temp) {
		cout << temp << " tens and ";
	}
	total -= temp * 10;
	cout << total << " ones.";
}

int main() {
	c5e5();
	return 0;
}