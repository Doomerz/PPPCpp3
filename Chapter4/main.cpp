import std;
using namespace std;

constexpr int frame_width = 2;
int area(int length, int width) { return length * width; }
int framed_area(int x, int y) { return area(x - frame_width, y - frame_width); }
void TryThis3_1() {
	//int s1 = area(7, 2;
	//int s2 = area(7,2)
	//Int s3 = area(7, 2);
	//int s4 = area('7,2);
}
//error s1
	//error C2143: syntax error: missing ')' before ';'
	//error C3861: 'area': identifier not found
//error s2
	//error C3861: 'area': identifier not found
	//error C2143: syntax error: missing ';' before '}'
//error s3
	//error C2065: 'Int': undeclared identifier
	//error C2146: syntax error: missing ';' before identifier 's3'
	//error C2065: 's3': undeclared identifier
	//error C3861: 'area': identifier not found
//error s4
	//error C2001: newline in constant
	//error C2015: too many characters in constant
	//error C2143: syntax error: missing ')' before '}'
	//error C3861: 'area': identifier not found
	//error C2143: syntax error: missing ';' before '}'
void TryThis3_2() {
	//int x0 = arena(7, 2);
	//int x1 = area(7);
	//int x2 = area("seven", 2);
}
//errors x0
	//error C3861: 'arena': identifier not found
//errors x1
	//error C2660: 'area': function does not take 1 arguments
//errors x2
	//error C2664: 'int area(int,int)': cannot convert argument 1 from 'const char [6]' to 'int'
void TryThis5_3() {
	int x = 0,
		y = 0,
		z = 0;
	int area1 = area(x, y); //x and y cannot be negative
	if (area1 <= 0)
		cout << "Error: " << "non-positive area" << endl;
	int area2 = framed_area(1, z); //this outright will be negative and makes no sense without changing frame_width
	int area3 = framed_area(y, z); //y and z must be >= 2; (therefore z>2 and y>2, because z=y=2 is an error)
	double ratio = double(area1) / area3; //y and z must neither be == 2;
	cout << "area1 = " << area1 << endl
		<< "area2 = " << area2 << endl
		<< "area3 = " << area3 << endl
		<< "ratio = " << ratio << endl;
}
void TryThis6_3() {
	throw std::runtime_error("test");
}
//void TryThis7_1() {
	//hexagon w/ 2cm sides. calculate if area is ~9.
	//6*1*tan(90-(360/6/2)) = 6*tan(90-30) = 6*tan(60deg) = 6*sqrt(3) = 6*1.7305080757 = 10.3923048454
	//estimate travel distances. trivial
//}
void expect(bool test, string error) {
	if (test)
		throw runtime_error(error);
}
void TryThis7_3_3() {
	int length = 20, width = 200000000; //overflow the int into a negative number
	expect(!(0 < length && 0 < width), "bad args to area()");
	int a = length * width;
	expect(!(0 < a), "bad area() result");
	cout << a;
	return;
}
void TryThis() {
	//pick up at 4.7.5 pg.181
	default_random_engine rande; //engine for generating randomness
	uniform_int_distribution<int> dist(1, 6); //the distribution for randomness [1:6] range integers of uniform probability (like a die)
	rande.seed(chrono::system_clock::now().time_since_epoch().count()); //seed random engine with something more or less random to get more or less random results
	//without seed, or if an identical seed is given, a random number generator will produce identical results each time.
	for (int i{}; i < 10; i++) //roll dice 10 times
		cout << dist(rande) << endl;
}

///Drill

int drill() 
try {
	//code
	//1: Cout << "Success!\n"; //Cout should be cout
	//2: cout << "Success!\n; //string literal not terminated
	//3: cout << "Success" << !\n" //second string literal not started with '"' and not terminated with ;
	//4: cout << success << '\n'; //success is not a literal and is not defined
	//5: string res=7; vector<int> v(10); v[5] = res; cout << "Success!\n"; //can't init string with int nor assign a string to an int
	//6: vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n"; //accessing vector requires subscripting [] not parenthesis ()
	//7: if (cond) cout << "Success!\n"; else cout << "Fail!\n"; //cond not defined
	//8: bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; //for success to be printed we'll need c = true
	//9: string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n"; //boo should be bool, since 'f' > 'a' "fool" < s is false and thus won't be true unless "fool" > s
	//10: string s = "ape"; if (s == "fool") cout << "Success!\n"; //s != "fool" would result in success
	//11: string s = "ape"; if (s == "fool") cout < "Success!\n"; //same as 10, but needs << not < for insertion operator
	//12: string s = "ape"; if (s + "fool") cout < "Success!\n"; //insertion operator needed for cout like 11 and string isn't a boolean so we need != instead of +
	//13: vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n"; //0 < v.size() will never evalutate to false stopping the loop
	//14: vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n"; //this is fine, but if we use i the subscript vector it will error on the last iteration as it is a range error
	//15: string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i]; //6 is not enough as it will cout << "Succe"; instead we need s.size() or 9 or 10 for the extra new line
	//16: if (true) then cout << "Success!\n"; else cout << "Fail!\n"; //then is not defined, if removed it works.
	//17: int x = 2000; char c = x; if (c == 2000) cout << "Success!\n"; //limit of char is 255, thus this is truncated and will never be true.
	//18: string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i]; //this is good.
	//19: vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n"; //vector requires a type in <>
	//20: int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n"; //replace ++j with ++i
	//21: int x = 2; double d = 5 / (x - 2); if (d == 2 * x + 0.5) cout << "Success!\n"; //if x = 2, x-2 is zero and will cause divide by 0 error
	//22: string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i]; //string doesn't take a type in <>, plus we have a range error, should be i<10 or i<s.size();
	//23: int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n"; //j is not defined and ++j must be ++i;
	//24: int x = 4; double d = 5 / (x - 2); if (d = 2 * x + 0.5) cout << "Success!\n"; //this will pass as d= will result in d and since d would be != 0 it will be true
	//25: cin << "Success!\n"; //cin doesn't use an insertion operator so cin should be cout

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
//1: Cout << "Success!\n;

///Review

/// Name four major types of errors and briefly define each one.
//
/// What kinds of errors can we ignore in student programs ?
//
/// What guarantees should every completed project offer ?
//
/// List three approaches we can take to eliminate errors in programs and produce acceptable software.
//
/// Why do we hate debugging ?
//
/// What is a syntax error ? Give five examples.
//
/// What is a type error ? Give five examples.
//
/// What is a linker error ? Give three examples.
//
/// What is a logic error ? Give three examples.
//
/// List four potential sources of program errors discussed in the text.
//
/// How do you know if a result is plausible ? What techniques do you have to answer such questions ?
//
/// How do you test if an input operation succeeded ?
//
/// Compare and contrast having the caller of a function handle a run - time error vs.having the called function handle the run - time error.
//
/// When is throwing an exception preferable to returning an “error value” ?
//
/// When is returning an “error value” preferable to throwing an exception ?
//
/// Describe the process of how exceptions are thrown and caught.
//
/// Why, with a vector called v, is v[v.size()] a range error ? What would be the result of calling this ?
//
/// What is an assertion ?
//
/// Define precondition and postcondition; give an example(that is not the area() function from this chapter), preferably a computation that requires a loop.
//
/// When would you not test a precondition ?
//
/// When would you not test a postcondition ?
//
/// What are the steps in debugging a program ?
//
/// Why does commenting help when debugging ?
//
/// How does testing differ from debugging ?
//
/// What is a random number ?
//
/// How do we use random_int() and seed() ?
//


///Exercises
//ex1 done
double ctok(double c) {
	double k = c + 273.15;
	return k;
}
void c4e2() {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';
}
//kelvin difference is 273.15
//k should be a double
//ctok should return k and end with ;
//cin >> c instead of d
//ctok(c) instead of ctok("c")
//cout instead of Cout
void c4e3() {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	if (k < 0) cout << k << "not a real temperature.\n";
	else cout << k << '\n';
}
double ctok4(double c) {
	double k = c + 273.15;
	if (k < 0) throw runtime_error("not a real temperature!\n");
	return k;
}
void c4e4()
try {
	double c = 0;
	cin >> c;
	double k = ctok4(c);
	cout << k << '\n';
}
catch (exception& e) {
	cout << e.what();
}
double ktoc(double k) {
	if (k < 0) throw runtime_error("not a real temperature!\n");
	double c = k - 273.15;
	return c;
}
void c4e5()
try {
	cout << "Enter a temperature and c for celsius or k for kelvin to convert to the other.\n";
	double x{};
	string unit;
	cin >> x;
	cin >> unit;
	if (unit.size() != 1) throw runtime_error("Not a valid unit type.\n");
	if (tolower(unit[0]) == 'c') cout << ctok4(x) << " Kelvin.\n";
	else if (tolower(unit[0]) == 'k') cout << ktoc(x) << " Celsius.\n";
	else throw runtime_error("not a valid unit type.\n");
}
catch (exception& e) {
	cout << e.what() << endl;
}
double ftoc(double f) {
	double c = 5 / 9 * (f - 32);
	if (c < 273.15) throw runtime_error("not a real temperature!\n");
	return c;
}
double ctof(double c) {
	if (c < 273.15) throw runtime_error("not a real temperature!\n");
	double f = 9 / 5 * c + 32;
	return f;
}
void c4e6()
try {
	cout << "Enter a temperature and a unit type followed by a space and what to convert to. [c/k/f]\n";
	double x{};
	string unit1, unit2;
	cin >> x >> unit1 >> unit2;
	if (unit1.size() != 1 || unit2.size() != 1) throw runtime_error("Not ta valid unit type.\n");
	switch (tolower(unit1[0])) {
	case 'c':
		if (tolower(unit2[0]) == 'k') cout << ctok4(x) << " Kelvin.\n";
		else if (tolower(unit2[0]) == 'f') cout << ctof(x) << " Fahrenheit.\n";
		else throw runtime_error("not a valid conversion type.\n");
		break;
	case 'k':
		if (tolower(unit2[0]) == 'c') cout << ktoc(x) << " Celsius.\n";
		else if (tolower(unit2[0]) == 'f') cout << ctof(ktoc(x)) << " Fahrenheit.\n";
		else throw runtime_error("not a valid conversion type.\n");
		break;
	case 'f':
		if (tolower(unit2[0]) == 'c') cout << ftoc(x) << " Celsius.\n";
		else if (tolower(unit2[0]) == 'k') cout << ctok4(ftoc(x)) << " Kelvin.\n";
		else throw runtime_error("not a valid converstion type.\n");
		break;
	default:
		throw runtime_error("not a valid convert from type.\n");
	}
}
catch (exception& e) {
	cout << e.what() << endl;
}
void c4e7() {
	double a, b, c, x1, x2;

	//prompt
	cout << "Solve 0 = ax^2+bx+c...\n"
		<< "Enter value for a: ";
	if (!(cin >> a)) {
		cerr << "bad input.\n";
		return;
	}
	cout << "Enter value for b: ";
	if (!(cin >> b)) {
		cerr << "bad input.\n";
		return;
	}
	cout << "Enter value for c: ";
	if (!(cin >> c)) {
		cerr << "bad input.\n";
		return;
	}
	//calculation
	x2 = b * b - 4 * a * c;
	if (x2 == 0) {
		x1 = -b / (2 * a);
		cout << "vertex is the only point that intersects at x = " << x1 << endl;
	}
	else if (x2 > 0) {
		x2 = sqrt(x2);
		x1 = (-b + x2) / (2 * a);
		x2 = (-b - x2) / (2 * a);
		cout << "The polynomial intersects at " << x1 << " and " << x2 << endl;
	}
	else if (x2 < 0) {
		x2 *= -1;
		x2 = sqrt(x2) / (2 * a);
		x1 = -b / (2 * a);
		cout << "The polynomial does not intersect and has these imaginary intersects: " << x1 << " + " << x2 << "i and " << x1 << " - " << x2 << "i\n";
	}
}
void c4e8() {
	//read in a series of integers and then compute the sum of the first n integers
	//first ask for n, then read the values into a vector
	//see book for format
	//handle all inputs such as providing more than n inputs
	cout << "Please enter the number of values you want to sum: ";
	int n{};
	bool loop = true;
	vector<int> nums;
	if (!(cin >> n)) {
		cerr << "Expected int for n.\n";
		return;
	}
	cout << "Please enter some integers (press '|' to stop): ";
	while (true) {
		string input;
		if (!(cin >> input)) {
			cerr << "unexpected end of file.\n";
		}
		try {
			int x = stoi(input);
			nums.push_back(x);
		}
		catch (exception& e) {
			if (input == "|") loop=false;
			else {
				cerr << "input did not convert to number properly.\n";
				return;
			}
		}
	}
	if (nums.size() != n) {
		cout << "quantity of quantities provided don't match expected.\n";
		return;
	}
	int sum = 0;
	for (const auto& x : nums) sum += x;
	cout << "The sum of the first " << n << " numbers ( ";
	for (const auto& x : nums) cout << x << ' ';
	cout << ") is " << sum << ".\n";
}
void c4e9() {
	//read in a series of integers and then compute the sum of the first n integers
	//first ask for n, then read the values into a vector
	//see book for format
	//handle all inputs such as providing more than n inputs
	cout << "Please enter the number of values you want to sum: ";
	int n{};
	bool loop = true;
	vector<int> nums;
	if (!(cin >> n)) {
		cerr << "Expected int for n.\n";
		return;
	}
	cout << "Please enter some integers (press '|' to stop): ";
	while (true) {
		string input;
		if (!(cin >> input)) {
			cerr << "unexpected end of file.\n";
		}
		try {
			int x = stoi(input);
			nums.push_back(x);
		}
		catch (exception& e) {
			if (input == "|") loop = false;
			else {
				cerr << "input did not convert to number properly.\n";
				return;
			}
		}
	}
	if (nums.size() != n) {
		cout << "quantity of quantities provided don't match expected.\n";
		return;
	}
	int sum = 0;
	for (const auto& x : nums) {
		if (numeric_limits<int>::max() - sum < x) {
			cout << "Sum exceeds numeric limits.\n";
			return;
		}
		sum += x;
	}
	cout << "The sum of the first " << n << " numbers ( ";
	for (const auto& x : nums) cout << x << ' ';
	cout << ") is " << sum << ".\n";
}
void c4e10() {
	//read in a series of integers and then compute the sum of the first n integers
	//first ask for n, then read the values into a vector
	//see book for format
	//handle all inputs such as providing more than n inputs
	cout << "Please enter the number of values you want to sum: ";
	int n{};
	bool loop = true;
	vector<double> nums;
	if (!(cin >> n)) {
		cerr << "Expected int for n.\n";
		return;
	}
	cout << "Please enter some integers (press '|' to stop): ";
	while (true) {
		string input;
		if (!(cin >> input)) {
			cerr << "unexpected end of file.\n";
		}
		try {
			double x = stod(input);
			nums.push_back(x);
		}
		catch (exception& e) {
			if (input == "|") loop = false;
			else {
				cerr << "input did not convert to number properly.\n";
				return;
			}
		}
	}
	if (nums.size() != n) {
		cout << "quantity of quantities provided don't match expected.\n";
		return;
	}
	double sum = 0;
	for (const auto& x : nums) {
		if (numeric_limits<double>::max() - sum < x) {
			cout << "Sum exceeds numeric limits.\n";
			return;
		}
		sum += x;
	}
	cout << "The sum of the " << n << " numbers ( ";
	for (const auto& x : nums) cout << x << ' ';
	cout << ") is " << sum << ".\n";
	cout << "The differences in values are: ";
	for (int i{}; i < nums.size() - 3; ++i) {
		cout << nums[i] - nums[i + 1] << ", ";
	}
	cout << nums[nums.size() - 2] - nums[nums.size() - 1];
}
void c4e11() {
	//
}

int main() {
	drill();
	return 0;
}