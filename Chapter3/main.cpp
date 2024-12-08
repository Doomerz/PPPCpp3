import std;
using namespace std;

void TryThis4_1_1() {
	constexpr double d = 1,y = 151.95, k = 10.96, p = 0.77;
	double x{}, res{};
	char from, to;
	string first, last;
	cout << "Enter number of currency followed by from then to currency with associated letters\n(d for dollars, y for yen, k for kroner, p for pound): ";
	cin >> x >> from >> to;
	if (from == 'd') {
		first = "dollars";
		if (to == 'd') {
			last = "dollars";
			res = x;
		}
		else if (to == 'y') {
			last = "yen";
			res = x * y;
		}
		else if (to == 'k') {
			last = "kroner";
			res = x * k;
		}
		else if (to == 'p') {
			last = "pounds";
			res = x * p;
		}
		else cout << to << " not a valid input for convert to unit";
	}
	else if (from == 'y') {
		first = "yen";
		if (to == 'd') {
			last = "dollars";
			res = x / y;
		}
		else if (to == 'y') {
			last = "yen";
			res = x;
		}
		else if (to == 'k') {
			last = "kroner";
			res = x * k / y;
		}
		else if (to == 'p') {
			last = "pounds";
			res = x * p / y;
		}
		else cout << to << " not a valid input for convert to unit";
	}
	else if (from == 'k') {
		first = "kroner";
		if (to == 'd') {
			last = "dollars";
			res = x / k;
		}
		else if (to == 'y') {
			last = "yen";
			res = x * y / k;
		}
		else if (to == 'k') {
			last = "kroner";
			res = x;
		}
		else if (to == 'p') {
			last = "pounds";
			res = x * p / k;
		}
		else cout << to << " not a valid input for convert to unit";
	}
	else if (from == 'p') {
		first = "pounds";
		if (to == 'd') {
			last = "dollars";
			res = x / p;
		}
		else if (to == 'y') {
			last = "yen";
			res = x * y / p;
		}
		else if (to == 'k') {
			last = "kroner";
			res = x * k / p;
		}
		else if (to == 'p') {
			last = "pounds";
			res = x;
		}
		else cout << to << " not a valid input for convert to unit";
	}
	else cout << from << " not a valid input for convert from unit";
	cout << x << ' ' << first << " is " << res << ' ' << last;
}
void TryThis4_1_3() {
	constexpr double d = 1, y = 151.95, k = 10.96, p = 0.77, f = 0.88; //add swiss francs
	double x{}, res{};
	char from, to;
	string first, last;

	cout << "Enter number of currency followed by from then to currency with associated letters\n(d for dollars, y for yen, k for kroner, p for pound): ";
	cin >> x >> from >> to;
	res = x;

	switch (from) {
	case 'd':
		first = "Dollars";
		//skip as this is the reference currency
		//res /= d;
		break;
	case 'y':
		first = "Yen";
		res /= y;
		break;
	case 'k':
		first = "Kroner";
		res /= k;
		break;
	case 'p':
		first = "Pounds";
		res /= p;
		break;
	case 'f':
		first = "Swiss Francs";
		res /= f;
		break;
	default:
		cout << from << " is not a valid convert from value.";
	}

	switch (to) {
	case 'd':
		last = "Dollars";
		//skip as this is the reference currency
		//res *= d;
		break;
	case 'y':
		last = "Yen";
		res *= y;
		break;
	case 'k':
		last = "Kroner";
		res *= k;
		break;
	case 'p':
		last = "Pounds";
		res *= p;
		break;
	case 'f':
		last = "Swiss Francs";
		res *= f;
		break;
	default:
		cout << to << " is not a valid convert to value.";
	}

	cout << x << ' ' << first << " is " << res << ' ' << last;
}
void TryThis4_2_1() {
	char c = 'a';
	while (c <= 'z') {
		cout << c << "\t" << short(c) << endl;
		c++;
	}
}
void TryThis4_2_3() {
	char c = 'a';
	cout << "lower case letters:\n";
	for (; c <= 'z'; c++) cout << c << '\t' << short(c) << endl;
	c = 'A';
	cout << "upper case letters:\n";
	for (; c <= 'Z'; c++) cout << c << '\t' << short(c) << endl;
	c = '0';
	cout << "digits:\n";
	for (; c <= '9'; c++) cout << c << '\t' << short(c) << endl;
	/*lower case letters:
	a       97
	b       98
	c       99
	d       100
	e       101
	f       102
	g       103
	h       104
	i       105
	j       106
	k       107
	l       108
	m       109
	n       110
	o       111
	p       112
	q       113
	r       114
	s       115
	t       116
	u       117
	v       118
	w       119
	x       120
	y       121
	z       122
	upper case letters:
	A       65
	B       66
	C       67
	D       68
	E       69
	F       70
	G       71
	H       72
	I       73
	J       74
	K       75
	L       76
	M       77
	N       78
	O       79
	P       80
	Q       81
	R       82
	S       83
	T       84
	U       85
	V       86
	W       87
	X       88
	Y       89
	Z       90
	digits:
	0       48
	1       49
	2       50
	3       51
	4       52
	5       53
	6       54
	7       55
	8       56
	9       57*/
}
int sqr(int x) {
	int res{};
	for (int i = 0; i < x; i++) res += x;
	return res;
}
void TryThis5_1() {
	for (int i = 0; i <= 100; i++) cout << i << '\t' << sqr(i) << endl;
}
void TryThis6_4() {
	const string censor = "BLEEP";
	vector<string> disliked;
	string s;

	disliked.push_back("Broccoli");
	disliked.push_back("Poo");

	cout << "Enter a word to censor it\n";
	while (cin >> s) {
		for (string str : disliked) {
			if (s == str) {
				s = str;
				break;
			}
		}
		cout << s;
	}
	cout << "end of input stream...";
}

/// Drill
void graceful_exit() {
	cout << "Exit Character detected, ending program.\n";
}
void invalid_input() {
	cout << "Invalid input detected, please review input and try again.\n";
}
double obtain_drill6() {
	double res;
	if (cin >> res) {
		return res;
	}
	char c;
	cin.clear();
	cin >> c;
	if (c == '|') {
		graceful_exit();
		exit(0);
	}
	invalid_input();
	exit(-1);
}
void process1(const int a, const int b) {
	cout << a << "\t" << b << endl;
}
void Drill1() {
	//pseudo
	//RAII
	//loop
		//prompt
		//check for exit
		// +graceful exit
		//intake int
		//check failure
		// +invalid input exit
		//check for exit
		// +graceful exit
		//intake int
		//check failure
		// +invalid input exit
		//generate output
	int a, b;
	while (true) {
		cout << "Enter two integers and I will output them back.\n"
			<< "int a = ";
		if (!(cin >> a)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (!(cin >> b)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		process1(a, b);
		cout << endl;
	}
}
void process2(const int a, const int b) {
	cout << "The smaller value is: " << (a>b?b:a) << "\n"
		<< "The larger value is: " << (a>b?a:b) << endl;
}
void Drill2() {
	int a, b;
	while (true) {
		cout << "Enter two integers and I will tell you which is larger.\n"
			<< "int a = ";
		if (!(cin >> a)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (!(cin >> b)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		process2(a, b);
		cout << endl;
	}
}
void process3(const int a, const int b) {
	if (a == b) cout << "The numbers are equal." << endl;
	else cout << "The smaller value is: " << (a > b ? b : a) << "\n"
			<< "The larger value is: " << (a > b ? a : b) << endl;
}
void Drill3() {
	int a, b;
	while (true) {
		cout << "Enter two integers and I will tell you which is larger.\n"
			<< "int a = ";
		if (!(cin >> a)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (!(cin >> b)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		process3(a, b);
		cout << endl;
	}
}
void process4(const double a, const double b) {
	if (a == b) cout << "The numbers are equal." << endl;
	else cout << "The smaller value is: " << (a > b ? b : a) << "\n"
		<< "The larger value is: " << (a > b ? a : b) << endl;
}
void Drill4() {
	double a, b;
	while (true) {
		cout << "Enter two numbers and I will tell you which is larger.\n"
			<< "int a = ";
		if (!(cin >> a)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (!(cin >> b)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		process4(a, b);
		cout << endl;
	}
}
void process5(const double a, const double b) {
	if (a == b) cout << "The numbers are equal." << endl;
	else {
		cout << "The smaller value is: " << (a > b ? b : a) << "\n"
			<< "The larger value is: " << (a > b ? a : b) << endl;
		if (a - b < .01 && a - b > -.01) cout << "The numbers are almost equal." << endl;
	}
}
void Drill5() {
	double a, b;
	while (true) {
		cout << "Enter two numbers and I will tell you which is larger.\n"
			<< "int a = ";
		if (!(cin >> a)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (!(cin >> b)) {
			char c;
			cin.clear();
			cin >> c;
			if (c == '|') {
				graceful_exit();
				return;
			}
			invalid_input();
			return;
		}
		process5(a, b);
		cout << endl;
	}
}
void Drill6() {
	double big, lil;
	cout << "Enter a starting number: ";
	if (!(cin >> big)) {
		invalid_input();
		return;
	}
	lil = big;

	while (true) {
		double x;
		cout << "Enter a number: ";
		x = obtain_drill6();
		if (x > big) {
			cout << x << " is the largest so far.\n";
			big = x;
		}
		else if (x < lil) {
			cout << x << " is the smallest so far.\n";
			lil = x;
		}
		else cout << x << " is between the largest and smallest";
	}
}
double Drill7get_dist() {
	const vector<string> units{ "cm","m","in","ft" };
	const vector<double> conversion{ 0.01,1,0.0254,0.0254 * 12 };
	double quantity;
	string quality;
	if (!(cin >> quantity)) {
		char c;
		cin.clear();
		cin >> c;
		if (c == '|') {
			graceful_exit();
			exit(0);
		}
		invalid_input();
		exit(-1);
	}
	cin >> quality;
	if (quality[0] == '|') {
		graceful_exit();
		exit(0);
	}
	for (int i{}; i < units.size(); i++) {
		if (units[i] == quality) {
			return quantity * conversion[i];
		}
	}
	invalid_input();
	exit(-1);
}
void Drill7() {
	double big, lil;
	cout << "Enter a starting distance: ";
	big = Drill7get_dist();
	lil = big;

	while (true) {
		double x;
		cout << "Enter a distance: ";
		x = Drill7get_dist();
		if (x > big) {
			cout << x << "m is the largest so far.\n";
			big = x;
		}
		else if (x < lil) {
			cout << x << "m is the smallest so far.\n";
			lil = x;
		}
		else cout << x << "m is between the largest and smallest";
	}
}
double Drill9get_dist(int entries, double big, double lil, double sum) {
	const vector<string> units{ "cm","m","in","ft" };
	const vector<double> conversion{ 0.01,1,0.0254,0.0254 * 12 };
	double quantity;
	string quality;
	if (!(cin >> quantity)) {
		char c;
		cin.clear();
		cin >> c;
		if (c == '|') {
			graceful_exit();

			cout << "The largest distances: " << big << "m\n"
				<< "The smallest distances: " << lil << "m\n"
				<< "The sum of distances: " << sum << "m\n"
				<< "number of entries: " << entries << endl;
			exit(0);
		}
		invalid_input();
		exit(-1);
	}
	cin >> quality;
	if (quality[0] == '|') {
		graceful_exit();

		cout << "The largest distances: " << big << "m\n"
			<< "The smallest distances: " << lil << "m\n"
			<< "The sum of distances: " << sum << "m\n"
			<< "number of entries: " << entries << endl;
		exit(0);
	}
	for (int i{}; i < units.size(); i++) {
		if (units[i] == quality) {
			return quantity * conversion[i];
		}
	}
	invalid_input();
	exit(-1);
}
void Drill9() {
	int entries{};
	double big{}, lil{}, sum{};
	cout << "Enter a starting distance: ";
	sum = lil = big = Drill9get_dist(entries,big,lil,sum);
	entries++;

	while (true) {
		double x;
		cout << "Enter a distance: ";
		x = Drill9get_dist(entries, big, lil, sum);
		if (x > big) {
			cout << x << "m is the largest so far.\n";
			big = x;
		}
		else if (x < lil) {
			cout << x << "m is the smallest so far.\n";
			lil = x;
		}
		else cout << x << "m is between the largest and smallest";
	}
}
void finish_drill10(int entries, double big, double lil, double sum, vector<double> values) {
	cout << "The largest distances: " << big << "m\n"
		<< "The smallest distances: " << lil << "m\n"
		<< "The sum of distances: " << sum << "m\n"
		<< "number of entries: " << entries << endl
		<< "Values entered:" << endl;
	for (auto& v : values)
		cout << v << "m\n";
	exit(0);
}
double Drill10get_dist(int entries, double big, double lil, double sum, vector<double> values) {
	const vector<string> units{ "cm","m","in","ft" };
	const vector<double> conversion{ 0.01,1,0.0254,0.0254 * 12 };
	double quantity;
	string quality;
	if (!(cin >> quantity)) {
		char c;
		cin.clear();
		cin >> c;
		if (c == '|') {
			graceful_exit();
			finish_drill10(entries, big, lil, sum, values);
		}
		invalid_input();
		exit(-1);
	}
	cin >> quality;
	if (quality[0] == '|') {
		graceful_exit();
		finish_drill10(entries, big, lil, sum, values);
	}
	for (int i{}; i < units.size(); i++) {
		if (units[i] == quality) {
			return quantity * conversion[i];
		}
	}
	invalid_input();
	exit(-1);
}
void Drill10() {
	int entries{};
	double big{}, lil{}, sum{};
	vector<double> values;

	cout << "Enter a starting distance: ";
	sum = lil = big = Drill10get_dist(entries, big, lil, sum, values);
	entries++;

	while (true) {
		double x;
		cout << "Enter a distance: ";
		x = Drill10get_dist(entries, big, lil, sum, values);
		if (x > big) {
			cout << x << "m is the largest so far.\n";
			big = x;
		}
		else if (x < lil) {
			cout << x << "m is the smallest so far.\n";
			lil = x;
		}
		else cout << x << "m is between the largest and smallest";
		values.push_back(x);
	}
}
void finish_drill11(int entries, double big, double lil, double sum, vector<double> values) {
	cout << "The largest distances: " << big << "m\n"
		<< "The smallest distances: " << lil << "m\n"
		<< "The sum of distances: " << sum << "m\n"
		<< "number of entries: " << entries << endl
		<< "Values entered:" << endl;
	sort(values.begin(), values.end());
	for (auto& v : values)
		cout << v << "m\n";
	exit(0);
}
double Drill11get_dist(int entries, double big, double lil, double sum, vector<double> values) {
	const vector<string> units{ "cm","m","in","ft" };
	const vector<double> conversion{ 0.01,1,0.0254,0.0254 * 12 };
	double quantity;
	string quality;
	if (!(cin >> quantity)) {
		char c;
		cin.clear();
		cin >> c;
		if (c == '|') {
			graceful_exit();
			finish_drill11(entries, big, lil, sum, values);
		}
		invalid_input();
		exit(-1);
	}
	cin >> quality;
	if (quality[0] == '|') {
		graceful_exit();
		finish_drill11(entries, big, lil, sum, values);
	}
	for (int i{}; i < units.size(); i++) {
		if (units[i] == quality) {
			return quantity * conversion[i];
		}
	}
	invalid_input();
	exit(-1);
}
void Drill11() {
	int entries{};
	double big{}, lil{}, sum{};
	vector<double> values;

	cout << "Enter a starting distance: ";
	sum = lil = big = Drill11get_dist(entries, big, lil, sum, values);
	entries++;

	while (true) {
		double x;
		cout << "Enter a distance: ";
		x = Drill11get_dist(entries, big, lil, sum, values);
		if (x > big) {
			cout << x << "m is the largest so far.\n";
			big = x;
		}
		else if (x < lil) {
			cout << x << "m is the smallest so far.\n";
			lil = x;
		}
		else cout << x << "m is between the largest and smallest";
		values.push_back(x);
	}
}

/// REVIEW
//What is a computation?
// something that takes an input and gives an output
//what do we mean by inputs and outputs to a computation?
// information used by the computer to determine and output is an input and the result of the computation is the output.
//what are the three requirements a programmer should keep in mind when expressing computations?
// readability, correctness, efficiency.
//what does an expression do?
// resolves to some value
//what is the difference between a statement and an expression, as described in this chapter?
// statements do something, expressions are something.
//what is an lvalue? list the operators that require an lvalue. why do these operators, and not the others, require an lvalue?
// ..
//what is a constant expression?
// ..
//what is a literal?
// ..
//what is a symbolic constant and why do we use them?
// ..
//what is a magic constant? give examples.
// ..
//what are some operators that we can use for integers and floating-point values?
// ..
//what operators can be used on integers but not on floating-point numbers?
// ..
//what are some operators that can be used for strings?
// ..
//when would a programmer prefer a switch-statement to an if-statement?
// ..
//what are some common problems with switch-statements?
// ..
//what is the function of each part of the header line in a for-loop, and in what sequence are they executed?
// ..
//what when should the for-loop be used and when should the while-loop be used?
// ..
//describe what the line char foo(int x) means in a function definition.
// ..
//when should you define a separate function for part of a program? list reasons.
// ..
//what can you do to an int that you cannot do to a string?
// ..
//what is the index of the third element of a vector?
// ..
//how do you write a for-loop that prints every element of a vector?
// ..
//what does vector<char> alphabet(26); do?
// ..
//describe what push_back() does to a vector.
// ..
//what does vector's member size() do?
// ..
//what makes vector so popular/useful?
// ..
//how do you sort the elements of a vector?
// ..

void c3e2() {
	char c;
	while (cin >> c) {
		if (c == '|') {
			cout << c << " = " << int(c) << endl;
			return;
		}
		cout << c << " = " << int(c) << endl;
	}
}
void c3e3() {
	vector<double> temps;
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	if (!temps.size()) return;
	
	double sum = 0;
	for (double x : temps)
		sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	sort(temps.begin(), temps.end());
	cout << "Median temperature: " << temps[temps.size() / 2] << '\n';
}
void c3e4() {
	//read doubles into a vector.
	//output the sum, smallest, largest, mean
	vector<double> route;
	double sum{},
		near{},
		far{},
		dist;

	cout << "Enter distances between cities along a route, terminate with any non-double:\n";
	if (!(cin >> dist)) {
		cout << "no values entered, exiting application.";
		return;
	}
	sum = near = far = dist;
	route.push_back(dist);

	while(cin >> dist) {
		route.push_back(dist);
		sum += dist;
		if (dist > far) far = dist;
		if (dist < near) near = dist;
	}

	sort(route.begin(), route.end());

	cout << "Total Distance: " << sum << endl
		<< "Shortest Distance: " << near << endl
		<< "Longest Distance: " << far << endl
		<< "Mean Distance: " << sum / route.size() << endl;
}
void c3e5() {
	//program to play a numbers guessing game; pick number between 1-100 > program asks questions to figure out what the number is.
	//program gets answer after no more than seven questions
	int lowest{ 1 }, highest{ 100 }, ref{50};
	char c;

	cout << "Think of a number between 1-100.\nIs it over " << ref << "?[y/n]: ";
	if (!(cin >> c)) {
		cout << "Unexpected end of file";
		return;
	}
	do {
		switch (c) {
		case 'y':
			lowest = ref+1;
			break;
		case 'n':
			highest = ref;
			break;
		default:
			cout << "unexpected character, closing application";
			return;
		}
		if (lowest == highest) {
			cout << "Your number is " << lowest << "!" << endl;
			return;
		}

		ref = (lowest + highest) / 2;
		cout << "Is it over " << ref << "?[y/n]: ";
	} while (cin >> c);
	cout << "unexpected end of file" << endl;
	return;
}
void c3e6() {
	//simple calc
	double a, b, res;
	char c;
	string str;
	while (true) {
		cout << "Simple Calculator!\nEnter first operand: ";
		if (!(cin >> a)) {
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "Enter second operand: ";
		if (!(cin >> b)) {
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "Enter operator: ";
		if (!(cin >> c)) {
			cout << "unexpected end of file, closing application\n";
			return;
		}

		switch (c) {
		case '+':
			str = "sum";
			res = a + b;
			break;
		case '-':
			str = "difference";
			res = a - b;
			break;
		case '*':
			str = "multiplication";
			res = a * b;
			break;
		case '/':
			if (b == 0) {
				cout << "The division of " << a << " and " << b << " is undefined.\n";
				continue;
			}
			str = "division";
			res = a / b;
			break;
		default:
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "The " << str << " of " << a << " and " << b << " is " << res << ".\n\n";
	}
}
void c3e7_convert(const vector<string> nums, const string input) {
	for (int i{}; i < nums.size(); i++) {
		if (nums[i] == input) {
			cout << input << " is " << i << endl;
			return;
		}
	}
	cout << "Invalid input, please try again.\n";
}
void c3e7() {
	//make a vector holding the ten string values of "zero" through "nine"
	//use this to convert digit to spelled out and vice versa
	const vector<string> nums{"zero","one","two","three","four","five","six","seven","eight","nine"};
	string input, prompt = "Single digit number to convert: ";

	cout << "single digit number to convert: ";
	while (cin >> input) {
		if (input.size() == 1) {
			if (isdigit(input[0])) {
				cout << input << " is " << nums[stoi(input)] << endl << prompt; //stoi is short for string to int.
				continue;
			}
			cout << "Invalid input, please try again.\n" << prompt;
			continue;
		}
		c3e7_convert(nums, input);
		cout << prompt;
	}
}
double c3e8_getinput() {
	const vector<string> nums{ "zero","one","two","three","four","five","six","seven","eight","nine" };
	string input;
	if (!(cin >> input)) return -1;
	if (input.size() == 1) {
		if (isdigit(input[0])) {
			return stoi(input);
		}
		return -1;
	}
	for (int i{}; i < nums.size(); i++) {
		if (nums[i] == input) {
			return i;
		}
	}
	return -1;
}
void c3e8() {
	//modify simple calc to use single digit and spelled out option
	double a, b, res;
	char c;
	string str;
	while (true) {
		cout << "Simple Calculator!\nEnter first operand: ";
		a = c3e8_getinput();
		if (0 > a) {
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "Enter second operand: ";
		b = c3e8_getinput();
		if (0 > b) {
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "Enter operator: ";
		if (!(cin >> c)) {
			cout << "unexpected end of file, closing application\n";
			return;
		}

		switch (c) {
		case '+':
			str = "sum";
			res = a + b;
			break;
		case '-':
			str = "difference";
			res = a - b;
			break;
		case '*':
			str = "multiplication";
			res = a * b;
			break;
		case '/':
			if (b == 0) {
				cout << "The division of " << a << " and " << b << " is undefined.\n";
				continue;
			}
			str = "division";
			res = a / b;
			break;
		default:
			cout << "Invalid input, closing application\n";
			return;
		}
		cout << "The " << str << " of " << a << " and " << b << " is " << res << ".\n\n";
	}
}
void c3e9() {
	//64 squares; how many squares until 1000, 1000000, and 1000000000
	long long sum{};
	for (int i{}; i < 64; i++)
		cout << "Square " << i + 1 << " has " << (long long)(pow(2, i)) << " grains of rice for a sum of " << (sum += (long long)(pow(2, i))) << endl;
	//note squares 63 and 64
}
void c3e10() {
	//answer: int = 31, double = 64+

	int sum{};
	for (int i{}; i < 64; i++)
		cout << "Square " << i + 1 << " has " << static_cast<int>(pow(2, i)) << " grains of rice for a sum of " << (sum += static_cast<int>(pow(2, i))) << endl;
	for (int i{}; i < 64; i++)
		cout << i + 1 << " | " << pow(2, i) << endl;
}
string c3e11_enum2word(int e) {
	switch (e) {
	case 0:
		return "rock";
	case 1:
		return "paper";
	case 2:
		return "scissors";
	default:
		return "<ERROR>";
	}
}
void c3e11() {
	//roshambo
	vector<int> moves{ 0,1,2,1,0,2,0,1,2,0 };
	int move{}, player;
	string input;
	while (true) {
		cout << "Your move: ";
		if (!(cin >> input)) {
			cout << "Encountered eof" << endl;
			return;
		}
		if (input == "rock") player = 0;
		else if (input == "paper") player = 1;
		else if (input == "scissors") player = 2;
		else {
			cout << "invalid input. closing application." << endl;
			return;
		}
		if (player == moves[move%moves.size()]) {
			cout << "It's a tie!" << endl;
			move++;
			continue;
		}
		if ((player + 1) % 3 == moves[move%moves.size()]) {
			cout << "Computer wins! " << c3e11_enum2word(moves[move%moves.size()]) << " beats " << input << endl;
			moves[move%moves.size()] = player;
			move++;
			continue;
		}
		cout << "Player wins! " << input << " beats " << c3e11_enum2word(moves[move % moves.size()]) << endl;
		moves[move % moves.size()] = player;
		move++;
	}
}
void c3e12() {
	//find prime numbers between 1-100
	cout << "Calculating...\n";
	vector<int> primes{ 2 };
	int max = 100;
	for (int i{3}; i <= max; i++) {
		bool prime = true;
		for (int k{}; k < primes.size(); k++) {
			if (!(i % primes[k])) {
				prime = false;
				break;
			}
		}
		if (prime)
			primes.push_back(i);
	}
	//output
	cout << "primes up to 100:\n";
	for (int i{}; i < primes.size(); i++)
		cout << primes[i] << endl;
}
vector<int> remove_divisible(vector<int> arr, int val) {
	vector<int> res;
	for (int i{}; i < arr.size(); i++)
		if (arr[i] % val)
			res.push_back(arr[i]);
	return res;
}
void c3e13() {
	cout << "Calculating...\n";
	//build board
	constexpr int max = 100;
	vector<int> num, primes{ 2 };
	//build num
	for (int i{ 3 }; i < max; i++) {
		num.push_back(i);
	}
	//cull even
	num = remove_divisible(num, primes[primes.size() - 1]);

	while (num.size()) {
		primes.push_back(num[0]);
		num = remove_divisible(num, primes[primes.size() - 1]);
	}

	cout << "Primes up to 100:\n";
	for (int i{}; i < primes.size(); i++) {
		cout << primes[i] << endl;
	}
}
void find_max_primes() {
	cout << "Finding max number of primes determinable in an int\nThis may take some time...\n";
	vector<int> primes{ 2 };
	bool prime = true;
	int progress{1};

	for (int i{ 3 }; i < numeric_limits<int>::max(); i++) {
		prime = true;
		if (!(i % progress)) {
			if (i / progress == 9)
				progress *= 10;
			cout << "On " << i << " and still processing...\n";
		}
		for (int k{}; k < primes.size(); k++) {
			if (i % primes[k]) continue;
			prime = false;
		}
		if (prime)
			primes.push_back(i);
	}
	prime = true;
	for (int k{}; k < primes.size(); k++) {
		if (numeric_limits<int>::max() % primes[k]) continue;
		prime = false;
	}
	if (prime) {
		primes.push_back(numeric_limits<int>::max());
		cout << "Numeric limit is prime." << endl;
	}

	cout << "There are a max of " << primes.size() << "primes within the max value of an int.\nThese are:\n";
	for (int i{}; i < primes.size(); i++)
		cout << i << '|' << primes[i];
	fstream f;
	f.open("maxprime.txt");
	f << primes.size();
	f.close();
	cin.get();
}
void c3e14() {
	find_max_primes();
	return;
	//find the first n primes where n = a number passed by the user.
	vector<int> primes{ 2 };
	int n, max{};

	cout << "Please enter how many primes you want: ";
	if (!(cin >> n)) {
		cout << "input error, closing application.";
		return;
	}
	if (n < 1) {
		cout << "less than 1 prime makes no sense, closing application.";
		return;
	}
	if (n > max) {
		cout << "Safety limit for primes set to a max of " << max << endl;
		return;
	}

	cout << "Calculating...\n";
	for (int i{ 3 }; primes.size() < n; i++) {
		bool prime = true;
		for (int k{}; k < primes.size(); k++) {
			if (!(i % primes[k])) {
				prime = false;
				break;
			}
		}
		if (prime) {
			cout << primes.size() << "|" << i << endl;
			primes.push_back(i);
		}
	}
	cout << "Complete." << endl;
}
void c3e15() {
	cout << "Enter a series of numbers to find the mode.\n";
	vector<int> set;
	int x;

	while (cin >> x)
		set.push_back(x);

	if (set.size() == 0) {
		cout << "no values entered.";
		return;
	}

	sort(set.begin(), set.end());

	vector<int> value{ set[0] }, count{ 1 };
	for (int i{ 1 }; i < set.size(); i++) {
		if (set[i] != value[value.size() - 1]) {
			value.push_back(set[i]);
			count.push_back(1);
		}
		else
			++count[count.size() - 1];
	}

	x = 0;
	for (auto c : count)
		if (c > x)
			x = c;

	cout << "The modes of this set with a total count of " << x << " are:\n";
	for (int i{}; i < value.size(); i++)
		if (count[i] == x)
			cout << value[i] << endl;
}
void c3e16() {
	//find min, max, and mode of strings
	vector<string> set, value;
	vector<int> count;
	string str;
	int x;

	while (cin >> str) {
		if (str == "|")
			break;
		set.push_back(str);
	}

	if (set.size() == 0) {
		cout << "No values entered.\n";
		return;
	}

	sort(set.begin(), set.end());

	value.push_back(set[0]);
	count.push_back(1);
	for (int i{1}; i < set.size(); i++) {
		if (set[i] != value[value.size() - 1]) {
			value.push_back(set[i]);
			count.push_back(1);
		}
		else
			++count[count.size() - 1];
	}

	x = 0;
	for (auto c : count)
		if (c > x)
			x = c;

	cout << "The alphabetically minimum string is: " << set[0] << endl << "The maximum string is: " << set[set.size()-1] << "The mode(s) of the set with an occurance of " << x << " are:\n";
	for (int i{}; i < count.size(); i++)
		if (count[i] == x)
			cout << value[i] << endl;
}
void e17badinput() {
	cout << "Bad input, application closing.";
}
void c3e17() {
	//x = (-b +/- sqrt(b^2-4ac))/2a
	//init
	double a, b, c, x1, x2;
	
	//prompt
	cout << "Solve 0 = ax^2+bx+c...\n"
		<< "Enter value for a: ";
	if (!(cin >> a)) {
		e17badinput();
		return;
	}
	cout << "Enter value for b: ";
	if (!(cin >> b)) {
		e17badinput();
		return;
	}
	cout << "Enter value for c: ";
	if (!(cin >> c)) {
		e17badinput();
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
void c3e18() {
	//take name-value pairs
	//terminate on "NoName 0"
	//verify each name is unique, if a repeat name exit with error
	//write out each pair at the end
	vector<string> names;
	vector<int> scores;
	while (true) {
		string str;
		int x;
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
	cout << "input complete, our set is:\n";
	for (int i{}; i < names.size(); i++)
		cout << names[i] << " : " << scores[i] << endl;
}
void c3e19() {
	vector<string> names;
	vector<int> scores;
	string str;
	int x;
	bool found;
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
	cout << "input complete\nWho would you like the score for?\n";
	while (true) {
		found = false;
		cout << ">>";
		cin >> str;
		if (!cin) {
			cout << "Unexpected eof.";
			return;
		}
		for (int i{}; i < names.size(); i++) {
			if (names[i] == str) {
				found = true;
				cout << scores[i] << endl;
				break;
			}
		}
		if (!found) {
			cout << "name not found\n";
		}
	}
}
void c3e20() {
	vector<string> names;
	vector<int> scores;
	string str;
	int x;
	bool found;
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
		if (!(cin>>x)) {
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

int main() {
	c3e14();
}