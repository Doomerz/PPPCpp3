///reading notes

//cin (see-in) is the character input stream
//uses >> (extraction operator) to get values out of cin.
//conventionally, reading of strings is terminated by whitespace
//whitespace is space (' '), newline ('\n'), and tab ('\t')
//whitespace is ignored by >>
//some possible variable names are keywords and cannot be used.

import std;
using namespace std;

int TryThis3() {
	//modify name and age example to write out the age in number of months using a double.
	cout << "Please enter your first name and age\n";
	string name;
	double age;
	cin >> name >> age;
	cout << "Hello, " << name << " (age " << age * 12 << " months)\n";
	return 0;
}
int TryThis4() {
	cout << "Please enter a floating-point value: ";
	double n = 0;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< '\n';
	cout << "\nPlease enter an integer value: ";
	int x = 0;
	cin >> x;
	cout << "x == " << x
		<< "\nx+1 == " << x + 1
		<< "\nthree times x == " << 3 * x
		<< "\ntwice x == " << x + x
		<< "\nx squared == " << x * x
		<< "\nhalf of x == " << x / 2
		<< "\nsquare root of x == " << sqrt(x)
		<< "\nmodulo 2 of x == " << x%2
		<< '\n';
	return 0;
}

int TryThis5_1() {
	cout << "";
	string current, previous;
	while (cin >> current) {
		if (current == previous) cout << "repeated word: " << current << endl;
		previous = current;
	}
	return 0;
}
//result from test string has "did", "very", and "good" as repeats.

//int TryThis6() {
//	STRING s = "Goodbye, cruel world! ";
//	cOut << S << '\n';
//	return 0;
//}
//this gives errors:
//error C2065: 'STRING': undeclared identifier
//error C2146: syntax error: missing ';' before identifier 's'
//error C2065: 's': undeclared identifier
//error C2065: 'cOut': undeclared identifier
//error C2065: 'S': undeclared identifier

int TryThis9() {
	double d = 0;
	while (cin >> d) {
		int i = d;
		char c = i;
		cout << "d==" << d
			<< " i==" << i
			<< " c==" << c
			<< " char(" << c << ")\n";
	}
	return 0;
}
//d==2 i==2 c==☻ char(☻)
//d==3 i==3 c==♥ char(♥)
//d==129 i==129 c==ü char(ü)
//d==1025 i==1025 c==☺ char(☺)
//d==-42 i==-42 c==╓ char(╓)
//d==56 i==56 c==8 char(8)
//d==89 i==89 c==Y char(Y)
//d==128 i==128 c==Ç char(Ç)
//d==56.9 i==56 c==8 char(8)
//d==56.2 i==56 c==8 char(8)

///Drill
int Drill1() {
	cout << "Please enter your first name (followed by 'enter'):\n";
	string first_name;
	cin >> first_name;
	cout << "Hello " << first_name << ",\n";
	return 0;
}
int Drill2() {
	cout << "Please enter your first name(followed by 'enter') :\n";
	string first_name;
	cin >> first_name;
	cout << "Hello " << first_name << ",\n"
		<< "\n\tHow are you? I am fine. I miss you..." << endl;
	return 0;
}
int Drill3() {
	cout << "Please enter your first name(followed by 'enter') :\n";
	string first_name,friend_name;
	cin >> first_name;
	cout << "Please enter a friend's name(followed by 'enter') :\n";
	cin >> friend_name;

	cout << "Hello " << first_name << ",\n"
		<< "\n\tHow are you? I am fine. I miss you..."
		<< "\nHave you seen " << friend_name << " lately?" << endl;
	return 0;
}
int Drill4() {
	cout << "Please enter your first name(followed by 'enter') :\n";
	string first_name, friend_name;
	cin >> first_name;
	cout << "Please enter a friend's name(followed by 'enter') :\n";
	cin >> friend_name;
	cout << "Please enter your age(followed by 'enter') :\n";
	int age;
	cin >> age;
	if (age <= 0) throw std::runtime_error("Hey, you can't be 0 or less years old!");
	if (age >= 110) throw std::runtime_error("Whoa!? Are you sure you can be 110 or more years old!?");
	
	cout << "Hello " << first_name << ",\n"
		<< "\n\tHow are you? I am fine. I miss you..."
		<< "\nHave you seen " << friend_name << " lately?"
		<< "\nI hear you just had a birthday and you are " << age << " years old."
		<< endl;

	return 0;
}
int Drill5() {
	cout << "Please enter your first name(followed by 'enter') :\n";
	string first_name, friend_name;
	cin >> first_name;
	cout << "Please enter a friend's name(followed by 'enter') :\n";
	cin >> friend_name;
	cout << "Please enter your age(followed by 'enter') :\n";
	int age;
	cin >> age;
	if (age <= 0) throw std::runtime_error("Hey, you can't be 0 or less years old!");
	if (age >= 110) throw std::runtime_error("Whoa!? Are you sure you can be 110 or more years old!?");

	cout << "Hello " << first_name << ",\n"
		<< "\n\tHow are you? I am fine. I miss you..."
		<< "\nHave you seen " << friend_name << " lately?"
		<< "\nI hear you just had a birthday and you are " << age << " years old."
		<< endl;

	if (age < 12) cout << "Next year you will be " << age + 1 << '.';
	if (age == 17) cout << "Next year you will be able to vote.";
	if (age > 70) cout << "Are you retired?";

	return 0;
}
int Drill6() {
	cout << "Please enter your first name(followed by 'enter') :\n";
	string first_name, friend_name;
	cin >> first_name;
	cout << "Please enter a friend's name(followed by 'enter') :\n";
	cin >> friend_name;
	cout << "Please enter your age(followed by 'enter') :\n";
	int age;
	cin >> age;
	if (age <= 0) throw std::runtime_error("Hey, you can't be 0 or less years old!");
	if (age >= 110) throw std::runtime_error("Whoa!? Are you sure you can be 110 or more years old!?");

	cout << "Hello " << first_name << ",\n"
		<< "\n\tHow are you? I am fine. I miss you..."
		<< "\nHave you seen " << friend_name << " lately?"
		<< "\nI hear you just had a birthday and you are " << age << " years old."
		<< endl;

	if (age < 12) cout << "Next year you will be " << age + 1 << '.';
	if (age == 17) cout << "Next year you will be able to vote.";
	if (age > 70) cout << "Are you retired?";

	cout << "\nYours Sincerely,\n\n";
	return 0;
}


/// Review

///what is meant by the term prompts?
// something that calls upon the user to take an action
///which operator do you use to read into a variable?
// >>
///what notations can you use to initialize an object?
// name(), name{}, name = rval;
///if you want the user to input an integer value into your program for a variable named number, what are two lines of code you could write to ask the user to do it and to input the value into your program?
// cout << "please enter an integer: "; cin >> number;
///what is \n called and what purpose does it server?
// a newline character. moves the cursor to the next line.
///what terminates input into a string?
// whitespace, conventionally.
///what terminates input into an integer?
// any non-'-'(at the beginning) or not a digit.
///how would you write the following as a single line of code: cout << "Hello, "; cout << first_name; cout << "!\n";
// cout << "Hello, " << first_name << "!\n";
///what is an object?
// an allocated space of memory where the meaning of the values are interpreted in relation to the type.
///what is a literal?
// a direct value not held in a variable directly.
///what kinds of literals are there?
// boolean, integer, floating-point, string, character.
///what is a variable?
// a space in memory that holds a value in bytes.
///what are typical sizes for a char, an int, and a double?
// 1, 4, 8 bytes respectively.
///what measures do we use for the size of small entities in memory, such as ints and strings?
// bytes
///what is the difference between = and ==?
// = is assignment and == is evaluating whether they are equal
///what is a definition?
// where the operation of a function or a class is defined.
///what is an initialization and how does it differ from an assignment?
// initialization is setting a starting value for a variable, assignment changes its held value.
///what is string concatenation and how do you make it work in c++?
// concatenation is combining two strings to form the first appended by the second. ie. string1 + string2 == string1appended_by_string2
///what operators can you apply to an int?
// +,-,*,/,=,==,%,<,>,<=,>=, ++, --, +=, -=, *=, /=, %=, !=, >>, <<
///which of the following are legal names in C++? if a name is illegal, why not?
// good: This_little_pig, _this_is_ok, MineMineMine, number
// bad:'This_1_is fine' - cannot have whitespace, '2_For_1_special' - must start with '_' or alphabetical, 'latest thing' - cannot have whitespace, 'George@home' - @ not a alphanumeric, 'correct?' - '?' not a alphanumeric, Stroustrup.com - '.' non-alphanumeric, $PATH - '$' not a alphanumeric
///give five examples of legal names that you shouldn't use because they are likely to cause confusion.
// things with i, l, 1 and o,O,0.
///what are some good rules for choosing names?
// concise but descriptive.
///what is type safety and why is it important?
// type safety prevents unintentional operations occuring on the wrong type.
///why can conversion from double to int be a bad thing?
// it can be narrowing causing unintentional loss of data.
///define a rule to help decide if a conversion from one type to another is safe or unsafe.
// if the convert to type can hold all potential values from convert from type it is safe.
///How can we avoid undesirable conversions?
// using static_cast<T> and {}
///what are the uses of auto
// to impicitly create variable based on the type of the rvalue given.


/// Exercises

//see trythis above
int c2e2() {
	cout << "Please enter a number of miles to convert to km: ";
	double miles;
	double conversion{1.609};
	cin >> miles;
	cout << miles << " miles is " << miles * conversion << " km.";
	return 0;
}
int c2e3() {
	//int double = 0;
	//bool this_is fine = false;
	string $PATH = "C:\\"; //this shouldn't work, but does?
	//string George@home;
	//char 23c = 23;
	return 0;
}
int c2e4() {
	int a, b;
	cout << "Enter two integers to see how they evaluate.\n"
		<< "int a = ";
	cin >> a;
	cout << "int b = ";
	cin >> b;
	cout << "a >= b : " << (a >= b)
		<< "\na + b : " << a + b
		<< "\na - b : " << a - b
		<< "\na * b : " << a * b
		<< "\na / b : " << a / b
		<< "\na % b : " << a % b;
	return 0;
}
int c2e5() {
	double a, b;
	cout << "Enter two floating-point numbers to see how they evaluate.\n"
		<< "float a = ";
	cin >> a;
	cout << "float b = ";
	cin >> b;
	cout << "a >= b : " << (a >= b)
		<< "\na + b : " << a + b
		<< "\na - b : " << a - b
		<< "\na * b : " << a * b
		<< "\na / b : " << a / b;
	return 0;
}
int c2e6() {
	int a, b, c;
	cout << "Enter 3 integers to sort.\n"
		<< "int a = ";
	cin >> a;
	cout << "int b = ";
	cin >> b;
	cout << "int c = ";
	cin >> c;
	if (a > b) swap(a, b); //just swaps values
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}
int c2e7() {
	string a, b, c;
	cout << "Enter 3 strings to sort.\n"
		<< "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}
int c2e8() {
	int x;
	cout << "Enter a number to determine evenness: ";
	cin >> x;
	cout << "The value " << x << " is an " << (x % 2 ? "odd" : "even") << "number"; //a fancy if/else style syntax: <boolean expression> ? <if true result> : <if false result>
	return 0;
}
int c2e9() {
	string s;
	cout << "Enter a word to evaluate to a number: ";
	cin >> s;
	if (s == "zero") cout << "zero is 0";
	else if (s == "one") cout << "one is 1";
	else if (s == "two") cout << "two is 2";
	else if (s == "three") cout << "three is 3";
	else if (s == "four") cout << "four is 4";
	else cout << "not a prepared input";
	return 0;
}
int c2e10() {
	string op;
	double x{}, y{};
	cout << "Enter operator followed by operands left then right:";
	cin >> op;
	cin >> x;
	cin >> y;
	cout << "result: ";
	if (op == "+" || op == "plus") cout << x + y;
	else if (op == "-" || op == "minus") cout << x - y;
	else if (op == "*" || op == "multi" || op == "multiplication" || op == "multiply") cout << x * y;
	else if (op == "/" || op == "divide" || op == "division") {
		if (y == 0) cout << "undefined (divide by 0)";
		else cout << x / y;
	}
	else cout << "operator not recognized: " << op;
	return 0;
}
int c2e11() {
	int pennies{}, nickels{}, dimes{}, quarters{}, half_dollars{}, dollars{};
	constexpr int p = 1, n = 5, d = 10, q = 25, h = 50, c = 100;
	cout << "Enter the change that you have.\n"
		<< "Pennies: ";
	cin >> pennies;
	cout << "Nickels: ";
	cin >> nickels;
	cout << "Dimes: ";
	cin >> dimes;
	cout << "Quarters: ";
	cin >> quarters;
	cout << "Half Dollars: ";
	cin >> half_dollars;
	cout << "Dollars: ";
	cin >> dollars;
	cout << "You have " << pennies << (pennies == 1 ? " Pennies.\n" : " Penny.\n")
		<< "You have " << nickels << (nickels == 1 ? " Nickels.\n" : " Nickel.\n")
		<< "You have " << dimes << (dimes == 1 ? " Dimes.\n" : " Dime.\n")
		<< "You have " << quarters << (quarters == 1 ? " Quarters.\n" : " Quarter.\n")
		<< "You have " << half_dollars << (half_dollars == 1 ? " Half Dollars.\n" : " Half Dollar.\n")
		<< "You have " << dollars << (dollars == 1 ? " Dollars.\n" : " Dollar.\n")
		<< "The value of all of your coins is " << p * pennies + n * nickels + d * dimes + q * quarters + h * half_dollars + c * dollars << (p * pennies + n * nickels + d * dimes + q * quarters + h * half_dollars + c * dollars == 1 ? " cents." : " cent.");
	return 0;
}

int main() {
	return c2e11();
}