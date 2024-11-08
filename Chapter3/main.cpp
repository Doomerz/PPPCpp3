import std;
using namespace std;

//https://www.youtube.com/watch?v=DaMimdNNnAw

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
		if (cin.peek() == '|') {
			graceful_exit();
			return;
		}
		if (!(cin >> a)) {
			invalid_input();
			return;
		}
		cout << "int b = ";
		if (cin.peek() == '|') {
			graceful_exit();
			return;
		}
		if (!(cin >> a)) {
			invalid_input();
			return;
		}
		process1(a, b);
	}
}

int main() {
	Drill1();
}