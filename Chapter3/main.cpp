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
	constexpr double d = 1, y = 151.95, k = 10.96, p = 0.77; //add swiss francs
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
}//TODO convert to switch statements, FINISH + ADD SWISS FRANCS

int main() {
	TryThis4_1_3();
}