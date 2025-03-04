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
	void Date::add_day(unsigned int n) {
		while (n > 0) {
			if (n < 31 - d) {
				d += n;
				n = 0;
			}
			else {
				n -= 31 - d+1; //assumes 31 day months
				d = 1;
				++m;
				if (m == Month::jan)
					y++;
			}
		}
	}

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
		enum class Month {jan=1,feb,mar,apr,jun,jul,aug,sep,oct,nov,dec};
		Date(const int& year, const Month& month, const unsigned int& day)
			:y{ year }, m{ month }, d{ day }
		{ }

	private:
		int y;
		Month m;
		unsigned int d;
	};
} //namespace Drill
void Drill() {
	//TODO
	return;
}

///Review
//What are the two parts of a class, as described in the chapter ?
// 
//What is the difference between the interface and the implementation in a class ?
// 
//What are the limitations and problems of the struct Date from §8.4.1 ?
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
//Why are “helper functions” best placed outside the class definition ?
// 
//How does an enum class differ from a “plain” enum ?
//

///Exercises
//ex1:

///Main
int main() try {
	Drill();
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