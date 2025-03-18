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
//exercise for reader
//ex2:
//design and implement a name_pairs class holding name,age pairs. <string,double>
//represent with a vector for each
//provide and input operation (read_names()) that reads names, then use read_ages() to get ages for each name
//provide a print() operation that prints out the values pair in each in the order determined by the name vector
//provide a sort operation taht sorts the name vector in alphabetical order and reorganizes the age vector to matach.
//implement all as member functions
//ex3:
//replace name_pairs::print() with a global operator << and define == and !=
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
		return os << np.print();
	}
	bool operator==(const Name_pairs& a, const Name_pairs& b) {
		if (a.print() == b.print())
			return true;
	}
	bool operator!=(const Name_pairs& a, const Name_pairs& b) {
		return !(a == b);
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
		const string quit = "done"; //probably should have just done an empty string = done
		cout << "Enter names one line at a time, enter \"" << quit << "\" to conclude\n";
		while (true) {
			bool contains = false;
			string res = read_line();
			if (res == quit)
				break;
			for (const string& s : names) {
				if (res == s) {
					contains = true;
					break;
				}
			}
			if (!contains)
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
		//assumes there are no duplicate names
		vector<string> temp = names;
		std::sort(names.begin(), names.end());
		for (int i = 0; i < names.size(); i++) {
			if (names[i] == temp[i]) continue;
			for (int k = i + 1; k < names.size(); k++) {
				if (names[i] == temp[k]) {
					swap(temp[i], temp[k]);
					swap(ages[i], ages[k]);
					break;
				}
			}
		}
	}
}
void ex3() {
	ex2::Name_pairs nps;
	nps.read_names();
	nps.read_ages();
	cout << nps << "\n\n";
	nps.sort();
	cout << "sorted:\n\n" << nps;
}
//ex4:
//implement Name_pairs using a Name_pair class
namespace e4 {
	class Name_pair {
	public:
		Name_pair(const string& n, const double& a) : name{ n }, age{ a } {}

		string print() const;
		string get_name() const;
		double get_age() const;

		void set(const string& n, const double& a);
		//can't check for duplicates unless we pass in a vector or just handle on the caller side.
	private:
		string name;
		double age = -1;
	};
	class Name_pairs {
	public:
		string print() const;
		Name_pair get(const size_t& index) const;


		void read_pairs();
		void sort();
	private:
		vector<Name_pair> pairs;
	};
	ostream& operator<<(ostream& os, const Name_pair& np) { return os << np.print(); }
	ostream& operator<<(ostream& os, const Name_pairs& nps) { return os << nps.print(); }
	bool operator==(const Name_pair& a, const Name_pair& b) {
		if (a.get_name() == b.get_name() && a.get_age() == b.get_age())
			return true;
		return false;
	}
	bool operator==(const Name_pairs& a, const Name_pairs& b) {
		if (a.print() == b.print())
			return true;
		return false;
	}
	bool operator!=(const Name_pair& a, const Name_pair& b) { return !(a == b); }
	bool operator!=(const Name_pairs& a, const Name_pairs& b) { return !(a == b); }
	bool operator<(const Name_pair& a, const Name_pair& b) {
		return a.get_name() < b.get_name();
	}
	void Name_pair::set(const string& n, const double& a) { name = n; age = a; }
	double Name_pair::get_age() const { return age; }
	string Name_pair::get_name() const { return name; }
	string Name_pair::print() const { return name + ":" + to_string(age); }
	void Name_pairs::sort() { std::sort(pairs.begin(), pairs.end()); }
	void Name_pairs::read_pairs() {
		while (true) {
			string name, age;
			double x;
			cout << "Enter name or leave empty to exit\n";
			getline(cin, name);
			if (name.size() == 0) break;
			while (true) {
				size_t i;
				cout << "Enter " << name << "'s age: ";
				getline(cin, age);
				try {
					double res = stod(age, &i);
					if (i != age.size())
						throw runtime_error("Entry contained additional characters after number");
					else if (res < 0)
						throw runtime_error("Age cannot be < 0");
					else {
						x = res;
						break;
					}
				}
				catch (exception& e) {
					string err;
					if (e.what() == "invalid stod argument")
						err = "Entry not a number.";
					else if (e.what() == "stodargument out of range")
						err = "Entry does not fit in double.";
					else
						err = e.what();
					cerr << "Invalid input: " << err << "\nTry again:\n";
				}
			}
			pairs.push_back(Name_pair{ name,x });
		}
	}
	Name_pair Name_pairs::get(const size_t& index) const {
		if (index < 0) throw runtime_error("index out of range (index<0)");
		if (index >= pairs.size()) throw runtime_error("index out of range (index >= size)");
		return pairs[index];
	}
	string Name_pairs::print() const {
		string res;
		for (const auto& np : pairs) {
			res += np.print();
		}
		return res;
	}
}
void ex4() {
	e4::Name_pairs nps;
	nps.read_pairs();
	cout << nps << "\n\n";
	nps.sort();
	cout << "sorted:\n\n" << nps;
}
//ex5:
//design and implement a Book class such as for a library.
//Book should have members for the ISBN, Title, Author, and Copyright Date
//store data on whether or not the book is checked out.
//create functions for returning these values
//create funcs for checking a book in and out
//do simple validation of data entered
//ISBNs only of the form n-n-n-x where n is an int and x is a digit or letter. (store as string)
//ex6:
//add operators for the Book class, have the == operator check whether the ISBN numbers are the same for two books
//have != also compare
//have << print out the title, author and ISBN on separate lines
//ex7:
//create an enumerated type for the Book class called Genre
//have fiction,nonfiction, periodical, biography, and children
//ex8:
//create a Patron class for the library
//the class will have the user's name, library card number, library fees (if owed)
//have funcs that access this data as well as a function to set the fee of the user.
//have a helper that returns a boolean depending on whether the user owes fees
//ex9:
//create a library class
//include vectors of books and patrons
//include a struct called transaction to record when a book is checked out
//have it include a book, patron, and date
//make a vector of transactions
//create funcs to add books to the lirary, add patrons, and chckout books
//when checking out, library checks if user and book are in the library, if not report error.
//then check if the user oews fees. if so report an error
//otherwise create a transaction and add to respective vector.
//write a function that will return a vector that contains the names of all patrons who owe fees.
namespace Library_ {
	struct Book {
		enum class Genre { unknown, fiction, nonfiction, periodical, biography, children };

		Book(const string& isbn, const string& title, const string& author, const string& cpyr_date, const Genre& genre, const bool& avail = true)
			: ISBN{ isbn }, Title{ title }, Author{ author }, Copyright_date{ cpyr_date }, genre_{ genre }, available{ avail }
		{
			if (!valid_isbn(isbn)) throw runtime_error("Book::Book: isbn not valid");
			if (!valid_cpyr_date(cpyr_date)) throw runtime_error("Book::Book: cpyr_date not valid");
		}
		Book() = delete;

		//getters
		bool avail() const { return available; }
		string isbn() const { return ISBN; }
		string title() const { return Title; }
		string author() const { return Author; }
		string copyright_date() const { return Copyright_date; }
		Genre genre() const { return genre_; }

		//setters
		void checkout() { if (!available) throw runtime_error("book already checked out"); available = false; }
		void return_book() { if (available) throw runtime_error("book already in library"); available = true; }
		void isbn(const string& isbn) { if (!valid_isbn(isbn)) throw runtime_error("isbn not valid"); ISBN = isbn; }
		//void title(const string& title) { Title = title; }
		//void author(const string& author) { Author = author; }
		//void cpyr_date(const string& cpyr) { if (!valid_cpyr_date) throw runtime_error("cpyr not valid"); Copyright_date = cpyr; }
		void genre(const Genre& g) { genre_ = g; }
	private:
		bool available;
		Genre genre_ = Genre::unknown;
		string ISBN,
			Title,
			Author,
			Copyright_date;
	};
	//validation
	bool valid_isbn(const string& isbn) {
		if (isbn.size() != 13)
			return false;
		if (!isdigit(isbn[0]) || isbn[11] != '-' || !isalnum(isbn[12]))
			return false;
		for (int i{ 1 }; i < isbn.size() - 1; i++) {
			if (!isdigit(isbn[i]) && isbn[i] != '-')
				return false;
			if (isbn[i] == isbn[i - 1] && isbn[i] == '-')
				return false;
		}
		short sum{};
		for (const char& c : isbn)
			if (c == '-')
				sum++;
		if (sum != 3)
			return false;
		return true;
	}
	bool valid_cpyr_date(const string& cpyr_date) {
		//choose a date format.
		return true;
	}
	bool operator==(const Book& a, const Book& b) {
		if (a.isbn() == b.isbn())
			return true;
		return false;
	}
	bool operator!=(const Book& a, const Book& b) {
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Book& a) {
		return os << a.title() << '\n' << a.author() << '\n' << a.isbn() << '\n' << a.copyright_date() << '\n';
	}

	struct Patron {
		Patron(const string& n, const int& cardnumber, const int& fees = 0) : name{ n }, card_num{ cardnumber }, libfees{ fees } {}
		Patron() = delete;

		string username() const { return name; }
		int fees() const { return libfees; }
		int card_number() const { return card_num; }

		void add_fee(const int& fee) { libfees += fee; }
		void change_name(const string& new_name) { name = new_name; }
	private:
		int libfees, card_num;
		string name;
	};
	bool has_fees(const Patron& patron) { return patron.fees() > 0; }
	bool operator==(const Patron& a, const Patron& b) { return a.card_number() == b.card_number() ? true : false; }
	bool operator!=(const Patron& a, const Patron& b) { return !(a == b); }

	struct Transaction {
		Transaction(const Book& book, const Patron& patron, const string& date)
			: book_{ book }, user_{ patron }, date_{ date }
		{
		}
		Transaction() = delete;

		const Book& book() const { return book_; }
		const Patron& user() const { return user_; }
		const string& date() const { return date_; }
	private:
		Book book_;
		Patron user_;
		string date_;
	};

	struct Library {
		const vector<Book>& selection() const { return books; }
		const vector<Patron>& patrons() const { return users; }
		const vector<Transaction>& history() const { return transactions; }
		const Book& selection(const string& isbn) const { for (const Book& b : books) if (isbn == b.isbn()) return b; throw runtime_error("isbn not in library"); }

		void add_book(const Book& book);
		void add_user(const string& name);
		void checkout(const Book& book, const Patron& user, const string& date);
	private:
		int next_card_number = 0;
		vector<Book> books;
		vector<Patron> users;
		vector<Transaction> transactions;
	};
	void Library::add_book(const Book& book) {
		for (const Book& b : books)
			if (book == b)
				throw runtime_error("duplicate book"); //just to simplify, if we want multiple copies we'll want an int instead of a bool for available.
		books.push_back(book);
	}
	void Library::add_user(const string& name) {
		Patron user(name, next_card_number);
		next_card_number++;
		users.push_back(user);
	}
	void Library::checkout(const Book& book, const Patron& user, const string& date) {
		for (Book& b : books) {
			if (b == book) {
				if (book.avail()) {
					for (Patron& p : users) {
						if (p == user) {
							if (!has_fees(p)) {
								b.checkout();
								transactions.emplace_back(Transaction(b, p, date));
							}
							throw runtime_error("user has outstanding balance");
						}
					}
					throw runtime_error("no such user");
				}
				throw runtime_error("book not available");
			}
		}
		throw runtime_error("book not in library");
	}
	vector<Patron> outstanding(const Library& lib) {
		vector<Patron> res;
		for (const Patron& user : lib.patrons())
			if (has_fees(user))
				res.push_back(user);
		return res;
	}
}
//ex10:
//completed
//ex11:
//design and implement a set of useful helper functions for the date class
//next_workday() (!saturday && !sunday), week_of_year()
namespace c8_e11Date {
	class Date {
	public:
		class Invalid {};
		enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		enum class WeekDay { monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday };
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
		m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month(to_int(m) + 1);
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
	Date::WeekDay day_of_week(const Date& d) {
		constexpr static short t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
		int y = d.year();
		if (to_int(d.month()) < 3)
			y -= 1;
		short res = (y + y / 4 - y / 100 + y / 400 + t[to_int(d.month()) - 1] + d.day()) % 7;
		if (res == 0) res = 7;
		return int_to_weekday(res);
	}
	Date next_workday(const Date& d) {
		Date res = d;
		int wkd = to_int(day_of_week(d));
		if (wkd == 7 || wkd >= 1 && wkd <= 4) {
			res.add_day(1);
			return res;
		}
		res.add_day(8 - wkd);
		return res;
	}
	short week_of_year(const Date& d) {
		Date ref(d.year(), Date::Month::jan, 1);
		Date::WeekDay yr_dow_start = day_of_week(ref);
		short woy = 0;
		if (to_int(yr_dow_start) < to_int(Date::WeekDay::friday)) {
			//first week of the year must contain thursday or it is the last week of the previous year.
			woy++;
		}
		for (; yr_dow_start != Date::WeekDay::monday; ref.add_day(1)) {
			if (ref.day() == d.day()) {
				if (ref.month() == d.month()) {
					return woy;
				}
			}
			if (yr_dow_start == Date::WeekDay::sunday) {
				ref.add_day(1);
				woy++;
				break;
			}
			else
				yr_dow_start = int_to_weekday(to_int(yr_dow_start) + 1);
		}
		for (int w{}; ref.day() != d.day() && ref.month() != d.month(); ref.add_day(1)) {
			w = (w + 1) % 7;
			if (w == 0) woy++;
		}
		return woy;
	}
}
//ex12:
//change the representation of a date to be the number of days since jan 1,1970.
//represent as a long int
// reimplement the date member funcs in 8.4.2
//be sure to reject dates outside the range
namespace c8_Date {
	class Date {
	public:
		class Invalid {};
		enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
		enum class WeekDay { monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday };
		Date(const long int& days_since_jan1_1970);

		long int days_since_epoch() const { return d_; }
		//unsigned int day() const { return d; }
		//Month month() const { return m; }
		//int year() const { return y; }

		void add_day(const long int& n);
	private:
		long int d_;
		//int y;
		//Month m;
		//unsigned int d;
	};
	struct YMD {
		int year;
		Date::Month month;
		int day;
	};
	unsigned int to_int(const Date::Month& m) { return static_cast<unsigned int>(m); }
	unsigned int to_int(const Date::WeekDay& d) { return static_cast<unsigned int>(d); }
	vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	ostream& operator<<(ostream& os, const Date::Month& m) { return os << month_tbl[to_int(m)]; }
	vector<string> day_tbl = { "Not a day", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	ostream& operator<<(ostream& os, const Date::WeekDay& d) { return os << day_tbl[to_int(d)]; }
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
	unsigned int days_in_month(const Date::Month& month, const int& year) {
		switch (month) {
		case Date::Month::jan:
			return 31;
		case Date::Month::feb:
			if (is_leapyear(year))
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
	Date::Month operator++(Date::Month& m) {
		m = (m == Date::Month::dec) ? Date::Month::jan : Date::Month(to_int(m) + 1);
		return m;
	}
	YMD ymd(const Date& date) {
		YMD res;
		long int x = date.days_since_epoch();
		//year
		res.year = 1970;
		res.month = Date::Month::jan;
		res.day = 1;
		while (x > 0) {
			short diy = is_leapyear(res.year) ? 366 : 365;
			if (x < diy)
				break;
			x -= diy;
			res.year++;
		}
		while (x < 0) {
			short dily = is_leapyear(res.year - 1) ? 366 : 365;
			x += dily;
			res.year--;
		}
		//month

		while (true) {
			int dim = days_in_month(res.month, res.year);
			if (x < dim)
				break;
			x -= dim;
			++res.month;
		}
		//day
		res.day += x;
		//res
		return res;
	}
	ostream& operator<<(ostream& os, const Date& d) { YMD y = ymd(d); return os << y.year << '/' << y.month << '/' << y.day; }
	Date::Date(const long int& days_since_jan1_1970) :d_{ days_since_jan1_1970 } { }
	void Date::add_day(const long int& n) { d_ += n; }
	Date::WeekDay day_of_week(const Date& d) {
		long int wdoe = to_int(Date::WeekDay::thursday); //jan 1, 1970 is a thursday
		wdoe = (d.days_since_epoch() + wdoe) % 7;
		if (wdoe == 0)
			return Date::WeekDay::sunday;
		return int_to_weekday(wdoe);
	}
	Date next_workday(const Date& d) {
		short dow = to_int(day_of_week(d));
		if (dow < 5) {
			return Date(d.days_since_epoch() + 1);
		}
		return Date(d.days_since_epoch() + 8 - dow);
	}
	short week_of_year(const Date& d) {
		YMD dat = ymd(d);
		int doy{};
		for (int m{ 1 }; m < to_int(dat.month); m++)
			doy += days_in_month(int_to_month(m), dat.year);
		doy += dat.day;
		long int ref = d.days_since_epoch() - doy + 1;
		int fwdoy = to_int(day_of_week(Date(ref)));
		short woy{};
		if (fwdoy < 5)
			woy++;
		ref += 8 - fwdoy;
		if (d.days_since_epoch() < ref)
			return woy;
		woy++;
		while (true) {
			ref += 7;
			if (d.days_since_epoch() < ref)
				return woy;
			woy++;
		}
	}
}
//ex13:
//design and implement a rational number class, Rational.
//numerator and a denominator
//provide assignment, addition, subtraction, multiplication, division, and equality operators
//provide a conversion to double.
namespace c8_math {
	struct Rational {
		int num() const { return numerator; }
		int den() const { return denominator; }

		int& num() { return numerator; }
		int& den() { return denominator; }
		Rational& operator=(int b) {
			numerator = b;
			denominator = 1;
			return *this;
		}
	private:
		int numerator{ 0 }, denominator{ 1 };
	};
	Rational operator+(const Rational& a, const int& b) {
		Rational res{ a };
		res.num() += b * res.den();
		return res;
	}
	Rational operator+(const Rational& a, const Rational& b) {
		Rational res;
		res.num() = a.num() * b.den() + b.num() * a.den();
		res.den() = a.den() * b.den();
		return res;
	}
	//addition
	Rational operator-(const Rational& a, const int& b) {
		Rational res{ a };
		res.num() -= b * res.den();
		return res;
	}
	Rational operator-(const Rational& a, const Rational& b) {
		Rational res;
		res.num() = a.num() * b.den() - b.num() * a.den();
		res.den() = a.den() * b.den();
		return res;
	}
	//subtraction
	Rational operator*(const Rational& a, const int& b) {
		Rational res{ a };
		res.num() = a.num() * b;
		return res;
	}
	Rational operator*(const Rational& a, const Rational& b) {
		Rational res{ a };
		res.num() *= b.num();
		res.den() *= b.den();
		return res;
	}
	//multiplication
	Rational operator/(const Rational& a, const int& b) {
		Rational res{ a };
		res.den() *= b;
		return res;
	}
	Rational operator/(const Rational& a, const Rational& b) {
		Rational res{ a };
		res.num() *= b.den();
		res.den() *= b.num();
		return res;
	}
	//division
	Rational operator==(const Rational& a, const int& b);
	Rational operator==(const Rational& a, const Rational& b);
	//equality
	double to_double(const Rational& a);
	//TODO
}
//ex14:
//design and implement a Money class
//4/5 rounding rule, accurate to the last cent
//rep as a long int of cents
//don't worry about numeric limits
//ex15:
//refine Money class by adding a currency (given as a constructor arg)
//accept a floating point initializer as long as it can be exactly represented as a long int
//don't accept illegal operations
//money*money doesn't make sense
//the USD1.23+DKK5.00 makes sense if you provide a conversion table definint the conversion factor.
//ex16:
//Define an input operator>> that reads monetary amounts with currency denominations into Money
//define << too
namespace c8_finance {
	//TODO
}
//ex17:
//example where a rational gives a mathematically better result than Money
//ex18:
//example where Rational gives a better result than double

///Main
int main() try {
	//should come up with some tests.
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

//
// an enum class of error types
class someobj {
	struct throwable {
		enum class failtype{one_loc_of_failure,another};
		//but what if we could specify all distinct error locations (perhaps dynamically??)
		//but then we use masks and other conditions like ios_base::fail bits etc. to make error groups.
		//perhaps write a way to express that and then try to implement it
		//we can either dynamically insert from the code or send the code to a middleman engine that then compiles post code.
		//or we can keep it abstract.
	};
};
//