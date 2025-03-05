import std;
using namespace std;

///TryThis
namespace TT4 {
	//Date class
	class Date {
	public:
		Date(int yy, int mm, int dd)
			:y{yy}, m{mm}, d{dd} { }

		int year() { return y; }
		int month() { return m; }
		int day() { return d; }

		void add_day(int n);
	private:
		int y, m, d;
	};
	ostream& operator<<(ostream& os, Date d) {
		return os << d.year() << '/' << d.month() << '/' << d.day();
	}
}
void TryThis4_4() {
	TT4::Date christmas{ 2025,12,25 };
	cout << christmas;
}
namespace TT6 {
	//Date class
	class Date {
	public:
		class Invalid {};
		enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		enum class WeekDay { monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday };
		Date(int yy, int mm, int dd)
			:y{ yy }, m{ mm }, d{ dd }
		{
			if (!is_valid())
				throw Invalid{};
		}

		int year() { return y; }
		Month month() { return m; }
		int day() { return d; }

		bool is_valid();
		void add_day(unsigned int n);
	private:
		int y;
		Month m;
		int d;
	};

	int to_int(Date::Month m) { return static_cast<int>(m); }
	int to_int(Date::WeekDay d) { return static_cast<int>(d); }
	vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	ostream& operator<<(ostream& os, Date::Month m) { return os << month_tbl[to_int(m)]; }
	vector<string> day_tbl = { "Not a day", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	ostream& operator<<(ostream& os, Date::WeekDay d) { return os << day_tbl[to_int(d)]; }
	ostream& operator<<(ostream& os, Date d) {
		return os << d.year() << '/' << d.month() << '/' << d.day();
	}
	bool Date::is_valid() { return 0 < to_int(m) && to_int(m) < 13; }
	Date::Month operator++(Date::Month& m) {
		m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month{ to_int(m) + 1 };
		return m;
	}
	Date::Month int_to_month(int x) {
		if (x < to_int(Date::Month::jan) || to_int(Date::Month::dec) < x)
			throw runtime_error("bad month");
		return Date::Month{ x };
	}
	Date::WeekDay int_to_day(int x) {
		if (x < to_int(Date::WeekDay::monday) || to_int(Date::WeekDay::sunday) < x)
			throw runtime_error("bad weekday");
		return Date::WeekDay{ x };
	}
	void Date::add_day(unsigned int n) {
		while (n > 0) {
			if (n < 31 - d) {
				d += n;
				n = 0;
			}
			else {
				n -= 31 - d + 1; //assumes 31 day months
				d = 1;
				++m;
				if (m == Month::jan)
					y++;
			}
		}
	}
}
void TryThis6() {
	//write and compile and run a small example using ++ and << for month
	TT6::Date::Month amonth{ TT6::Date::Month::dec };
	cout << "last month was: " << amonth << ", this month is: " << ++amonth;
}

///Drill

//write Day, Month, and their associated functions per chapter. complete a final version of Date.
//Date must have:
// default constructor
// is_valid()
// Month
// Year
//define a date called today at feb 2, 2020; then define one called tomorrow and give it a value by
// copying today into it and increasing day by one using add_day()
//output today and tomorrow using a << (per 9.6 and 9.7
//check for a valid date can ignore leap years; make sure month is range checked as well as day
namespace Drill {
	class Date {
	public:
		class Invalid {};
		enum class Month {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
		enum class WeekDay {monday=1, tuesday, wednesday, thursday, friday, saturday, sunday};
		Date(const int& year, const Month& month, const unsigned int& day);

		unsigned int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_day(unsigned int n);
	private:
		int y;
		Month m;
		unsigned int d;
	};
	unsigned int to_int(const Date::Month& m) { return static_cast<unsigned int>(m); }
	unsigned int to_int(const Date::WeekDay& d) { return static_cast<unsigned int>(d); }
	vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	ostream& operator<<(ostream& os, const Date::Month& m) { return os << month_tbl[to_int(m)]; }
	vector<string> day_tbl = { "Not a day", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	ostream& operator<<(ostream& os, const Date::WeekDay& d) { return os << day_tbl[to_int(d)]; }
	ostream& operator<<(ostream& os, const Date& d) { return os << d.year() << '/' << d.month() << '/' << d.day(); }
	Date::Month operator++(Date::Month& m) {
		m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month( to_int(m) + 1 );
		return m;
	}
	Date::Month int_to_month(const unsigned int& x) {
		if (x < to_int(Date::Month::jan) || to_int(Date::Month::dec) < x)
			throw runtime_error("bad month");
		return Date::Month(x);
	}
	Date::WeekDay int_to_weekday(const unsigned int& x) {
		if (x < to_int(Date::WeekDay::monday) || to_int(Date::WeekDay::sunday) < x)
			throw runtime_error("bad weekday");
		return Date::WeekDay(x);
	}
	bool is_leapyear(int year) {
		//if year divisible 4
		//but not if year is divisble by 100
		//unless also divisible by 400
		if (!(year % 400))
			return true;
		if (!(year % 100))
			return false;
		if (!(year % 4))
			return true;
		return false;
	}
	unsigned int days_in_month(const Date& date) {
		switch (date.month()) {
		case Date::Month::jan:
			return 31;
		case Date::Month::feb:
			if (is_leapyear(date.year()))
				return 29;
			return 28;
		case Date::Month::mar:
			return 31;
		case Date::Month::apr:
			return 30;
		case Date::Month::may:
			return 31;
		case Date::Month::jun:
			return 30;
		case Date::Month::jul:
			return 31;
		case Date::Month::aug:
			return 31;
		case Date::Month::sep:
			return 30;
		case Date::Month::oct:
			return 31;
		case Date::Month::nov:
			return 30;
		case Date::Month::dec:
			return 31;
		default:
			throw runtime_error("bad month in days_in_month");
		}
	}
	bool is_valid(const Date& date) {
		return !(to_int(date.month()) < 1 || to_int(date.month()) > 12 || date.day() < 1 || date.day() > days_in_month(date));
	}
	Date::Date(const int& year, const Month& month, const unsigned int& day)
		:y{ year }, m{ month }, d{ day }
	{
		if (!is_valid(*this))
			throw Invalid{};
	}
	void Date::add_day(unsigned int n) {
		while (n) {
			unsigned int dim = days_in_month(*this);
			if (n + d <= dim) {
				d += n;
				return;
			}
			else {
				n -= dim - d + 1; //go to day 1 of next month
				d = 1;
				++m;
				if (m == Month::jan) y++;
			}
		}
	}
} //namespace Drill
void drill() {
	//write day, month and their associated funcs
	// is_valid(), Month, Year, etc. define a date called today init to feb 2, 2020
	// then def tomorrow by copy today and .add_day(); output today and tomorrow using a <<
	Drill::Date today{ 2020,Drill::Date::Month::feb,2 };
	Drill::Date tomorrow = today;
	tomorrow.add_day(1);
	cout << "Today: " << today << '\n' << "Tomorrow: " << tomorrow << endl;
}

///Review
//What are the two parts of a class, as described in the chapter ?
// 
//What is the difference between the interface and the implementation in a class ?
// 
//What are the limitations and problems of the struct Date from �8.4.1 ?
// 
//Why is a constructor used for the Date type instead of an init_day() function ?
// 
//What is an invariant ? Give examples.
// 
//When should functions be put in the class definition, and when should they be defined outside the class ? Why ?
// 
//What is a default constructor and when do we need one ?
// 
//What is a default member initializer ?
// 
//When should operator overloading be used in a program ? Give a list of operators that you might want to overload(each with a reason).Which ones can you define in C++ ?
// 
//Why should the public interface to a class be as small as possible ?
// 
//What does adding const to a member function do ?
// 
//Why are �helper functions� best placed outside the class definition ?
// 
//How does an enum class differ from a �plain� enum ?
//

///Exercises
//ex1:
//exercise for reader
//ex2:
//design and implement a name_pairs class holding name,age pairs. <string,double>
//represent with a vector for each
//provide and input operation (read_names()) that reads names, then use read_ages() to get ages for each name
//provide a print() operation that prints out the values pair in each in the order determined by the name vector
//provide a sort operation taht sorts the name vector in alphabetical order and reorganizes the age vector to matach.
//implement all as member functions
namespace ex2 {
	class Name_pairs {
	public:
		string print() const;

		void read_names();
		void read_ages();
		void sort();
	private:
		vector<string> names;
		vector<double> ages;
	};
	ostream& operator<<(ostream& os, const Name_pairs& np) {
		os << np.print();
	}
	string read_line() {
		string res;
		getline(cin, res);
		return res;
	}
	double read_age(const string& name) {
		size_t i;
		while (true) {
			cout << name << "'s age is: ";
			string inp = read_line();
			try {
				double res = stod(inp,&i);
				if (i != inp.size())
					throw runtime_error("Entry contained additional characters after number");
				else if (res < 0)
					throw runtime_error("Age cannot be < 0");
				else
					return res;
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
	}
	string Name_pairs::print() const {
		if (ages.size()!=names.size()) return "ages not initialized";
		string res;
		for (int i = 0; i < names.size(); i++)
			res += names[i] + ":" + to_string(ages[i]);
		return res;
	}
	void Name_pairs::read_names() {
		const string quit = "done";
		cout << "Enter names one line at a time, enter \"" << quit << "\" to conclude\n";
		while (true) {
			string res = read_line();
			if (res == quit)
				break;
			names.push_back(res);
		}
	}
	void Name_pairs::read_ages() {
		cout << "Enter ages for respective name\n";
		for (int i = 0; i < names.size(); i++) {
			double res = read_age(names[i]);
			ages.push_back(res);
		}
	}
	void Name_pairs::sort() {
		vector<string> temp = names;
		std::sort(names.begin(), names.end());
		for (int i = 0; i < names.size(); i++) {
			if (names[i] == temp[i]) continue;
			for (int k = i + 1; k < names.size(); k++) {
				//can we verify in get_names that there are no duplicates?
			}
		}
		//TODO
		return 0;
	}
}

///Main
int main() try {
	drill();
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

//reading 8.7