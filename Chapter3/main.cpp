import std;
using namespace std;

/// Notes

//last on 113
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
	//TODO
	//WRITE A WHILE LOOP OUT PUTTING THE ASSOCIATED VALUE OF CHARS AND THEIR int equivalent separated by a \t
}

int main() {
	TryThis4_2_1();
}