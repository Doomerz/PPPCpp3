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
} //verify finished

int main() {
	c3e3();
}