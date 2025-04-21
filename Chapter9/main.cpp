import std;
using namespace std;

//reading
void end_of_loop(istream& is, const char& terminator, const string& not_found) {
	if (is.fail()) {
		is.clear();
		char c;
		if (is >> c && c == terminator)
			return;
		throw runtime_error(not_found);
	}
}
template<typename T>
vector<T> generic_input_loop(istream& is, const char& term, const string& noterm_msg) {
	vector<T> res;
	for (T type; is >> type;) {
		res.push_back(type);
	}
	end_of_loop(is, term, noterm_msg);
}

///TryThis
void TryThis10_1() {
	//output your birth year in decimal, hexadecimal, and octal form. Label each value
	//line up output in columns using the tab character, output age now too.
	int year = 2024,
		month = 1,
		day = 1;
	cout << "Decimal: " << dec << year << '/' << month << '/' << day << endl
		<< "Hex: " << hex << year << '/' << month << '/' << day << endl
		<< "Octal: " << oct << year << '/' << month << '/' << day << endl;

	int age = 25;
	cout << "Decimal: " << dec << age << endl
		<< "Hex: " << hex << age << endl
		<< "Octal: " << oct << age << endl;
}
void TryThis10_6() {
	//see what that last statement prints and explain it. try some other formats.

	double d = 1234.56789;
	cout << format("- {:12} - {:12.8f} - {:30.20e} -\n", d, d, d);
}

///Drill
namespace Drill {
	struct Contact {
		string first,
			last,
			phone,
			email;
	};
	void output_contacts(ostream& os, vector<Contact> contacts) {
		const string& tblf = "First Name",
			tbll = "Last Name",
			tblp = "Phone",
			tble = "Email";
		size_t f{tblf.size()},
			l{tbll.size()},
			p{tblp.size()},
			e{tble.size()};
		
		for (const Contact& c : contacts) {
			if (c.first.size() > f) f = c.first.size();
			if (c.last.size() > l) l = c.last.size();
			if (c.phone.size() > p) p = c.phone.size();
			if (c.email.size() > e) e = c.email.size();
		}

		//tbl header
		os << setw(f) << tblf << '|' << setw(l) << tbll << '|' << setw(p) << tblp << '|' << setw(e) << tble << '\n'
			<< setfill('-') << setw(f) << '-' << '+' << setw(l) << '-' << '+' << setw(p) << '-' << '+' << setw(e) << '-' << '\n' << setfill(' ');
		//tbl
		for (const Contact& c : contacts) {
			os << setw(f) << c.first << '|' << setw(l) << c.last << '|' << setw(p) << c.phone << '|' << setw(e) << c.email << '\n';
		}
	}
	struct Point {
		int x, y;
	};
	ostream& operator<<(ostream& os, const Point& p) {
		os << '(' << p.x << ',' << p.y << ')';
		return os;
	}
	istream& operator>>(istream& is, Point& p) {
		char c;
		int a,b;
		is >> c;
		if (!is) return is;
		if (c != '(') {
			is.clear(ios::failbit);
			return is;
		}
		is >> a;
		if (!is) return is;
		is >> c;
		if (!is) return is;
		if (c != ',') {
			is.clear(ios::failbit);
			return is;
		}
		is >> b;
		if (!is) return is;
		is >> c;
		if (!is) return is;
		if (c != ')') {
			is.clear(ios::failbit);
			return is;
		}
		//finish
		p = Point{ a,b };
		return is;
	}
	Point get_point() {
		Point res;
		const string prompt = ">>";
		char c;
		
		while (true) {
			cout << prompt;
			if (cin >> res) {
				return res;
			}
			else {
				if (cin.eof() || cin.bad())
					throw runtime_error("get_point: unexpected stream state");
				else {
					cin.clear();
					cout << "Bad input, try again...\n";
					while (cin.get(c) && c != '\n');
					if (!cin)
						throw runtime_error("get_point: unable to reset");
				}
			}
		}
	}
	void test_output() {
		int birthyear = 2001,
			currentyear = 2025;
		cout << showbase; //enables base to be shown for numbers
		cout << "Dec:\t" << dec << birthyear << endl
			<< "Hex:\t" << hex << birthyear << endl
			<< "Oct:\t" << oct << birthyear << endl;
		
		cout << dec << "age:\t" << currentyear - birthyear << endl;
		
		string part8{ "1234 1234 1234 1234" };
		istringstream iss{ part8 };
		int a, b, c, d;
		iss >> a >> oct >> b >> hex >> c >> dec >> d;
		cout << endl << a << '\t' << b << '\t' << c << '\t' << d << endl
			<< "This is because first and last are decimals read as decimals, the others have differing values because they are read as different bases.\n\n";

		int part9 = 1234567.89;
		cout << "Default:\t" << defaultfloat << part9 << endl
			<< "Fixed:\t" << fixed << part9 << endl
			<< "Scientific:\t" << scientific << part9 << "\n\n";

		//make example table part10
		//first, last, phone, email
		vector<Contact> contacts{ 
			{"Bjarne", "Stroustrup", "3456789", "bstroustrup@cpp.prog"},
			{"Brian", "Kernighan", "1234567", "Bkernighan@cpp.prog"},
			{"Dennis", "Ritchie", "9876543", "dritchie@cpp.prog"},
			{"Greatest","Ever","1001337","FirstName.Greatest@LastName.Ever"},
			{"Tommy","Tutone","8675309","Jenny@Coumbia.anr"}
		};
		cout << "contacts table:\n";
		output_contacts(cout, contacts);
		cout << endl;

		//part 11
		cout << "Enter filename to pull Points: ";
		string file;
		cin >> file;
		ifstream ist{ file };
		vector<Point> points;
		for (Point p; ist >> p;)
			points.push_back(p);
		if (!ist) {
			if (ist.fail()) {
				if (ist.bad())
					throw runtime_error("drill points file bad");
				if (!ist.eof())
					cout << "bad file\n";
				else
					for (const Point& p : points)
						cout << p << '\n';
			}
		}
		ist.close();
		cout << '\n';
		
		//part12
		cout << "Enter 7 points (x,y)\n";
		vector<Point> original_points;
		for (int i{}; i < 7; i++)
			original_points.push_back(get_point());
		cout << "Our Points:\n";
		for (const Point& p : original_points)
			cout << p << '\n';
		cout << '\n';

		ofstream ofs{ "mydata.txt" };
		for (const Point& p : original_points)
			cout << p << '\n';
		ofs.close();

		ifstream ifs{ "mydata.txt" };
		vector<Point> processed_points;
		while (ifs) {
			Point p;
			ifs >> p;
			processed_points.push_back(p);
		}

		bool matched = true;
		size_t size = processed_points.size() > original_points.size() ? processed_points.size() : original_points.size();
		if (processed_points.size() != original_points.size())
			matched = false;
		for (int i{}; i < size; i++) {
			if (i < original_points.size())
				cout << original_points[i];
			else
				cout << "(Null,Null)";
			cout << '\t';
			if (i < processed_points.size())
				cout << processed_points[i];
			else
				cout << "(Null,Null)";
			cout << '\n';
			if (matched)
				if (original_points[i].x != processed_points[i].x || original_points[i].y != processed_points[i].y)
					matched = false;
		}

		if (!matched)
			cout << "Something went wrong!\n";
		if (processed_points.size() != original_points.size()) {
			cout << "size mismatch:\nOriginal = " << original_points.size() << "\nProcessed = " << processed_points.size();
		}
		cout << "\n\n";
	}
} //namespace Drill
void drill() {
	Drill::test_output();
}

///Review
//Why is I/O tricky for a programmer?
// 
//What does the notation << hex do ?
// 
//What are hexadecimal numbers used for in computer science ? Why ?
// 
//Name some of the options you may want to implement for formatting integer output.
// 
//What is a manipulator ?
// 
//What is the default output format for floating - point values ?
// 
//Explain what setprecision() and setw() do.
// 
//Which of the following manipulators do not “stick” : hex, scientific, setprecision(), setw() ?
// 
//In format(), how do you specify where an argument is placed on output ?
// 
//Give two examples where a stringstream can be useful.
// 
//When would you prefer line - oriented input to type - specific input ?
// 
//What does isalnum(c) do ?
// 
//When dealing with input and output, how is the variety of devices dealt with in most modern computers ?
// 
//What, fundamentally, does an istream do ?
// 
//What, fundamentally, does an ostream do ?
// 
//What, fundamentally, is a file ?
// 
//What is a file format ?
// 
//Name four different types of devices that can require I / O for a program.
// 
//What are the four steps for reading a file ?
// 
//What are the four steps for writing a file ?
// 
//Name and define the four stream states.
// 
//Discuss how the following input problems can be resolved :
//	a.The user typing an out - of - range value
//	b.Getting no value(end - of - file)
//	c.The user typing something of the wrong type
// 
//In what way is input usually harder than output ?
// 
//In what way is output usually harder than input ?
// 
//Why do we(often) want to separate input and output from computation ?
// 
//What are the two most common uses of the istream member function clear() ?
// 
//What are the usual function declarations for << and >> for a user - defined type X ?
// 
//How do you specify where an argument is inserted into a format string in format() ?
// 
//What is the notation for bases of decimal values in format() ?
// 
//How do you specify the precision of floating - point values in format() ?

///Exercises
//ex1:
//read a text file and convert to all lowercase and output to a new file
void c9e1(const string& inf = "c9e1i.txt", const string& opf = "c9e1o.txt") {
	ifstream ifs{ inf };
	if (!ifs) throw runtime_error("unable to open input file: " + inf);
	ofstream ofs{ opf };
	if (!ofs) throw runtime_error("unable to open output file: " + opf);
	char c;
	ifs >> noskipws;
	while (ifs >> c) {
		c = tolower(c);
		ofs << c;
		if (!ofs) throw runtime_error("Output file error during operation");
	}
	if (!ifs.eof())
		throw runtime_error("Not end of file for input file when complete");
	return;
}

//ex2:
//given a filename and a word; output each line that contains that word together with the line number
//hint: getline
void c9e2(const string& fname = "c9e2.txt", const string& find_str = "test") {
	ifstream ifs{ fname };
	if (!ifs) throw runtime_error("unable to open file");
	string s;
	int index{};
	while (getline(ifs, s)) {
		size_t pos = s.find(find_str,0);
		if (pos != string::npos) {
			cout << index << ": " << s << '\n';
		}
		index++;
	}
	if (!ifs.eof()) throw runtime_error("not end of file");
	cout << '\n';
	return;
}

//ex3:
//remove all vowels from a file (disemvowels)
const vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };
bool is_vowel(char c) {
	c = tolower(c);
	for (const char& v : vowels)
		if (c == v)
			return true;
	return false;
}
void c9e3(const string& fname = "c9e3.txt", const string& ofname = "c9e3res.txt") {
	ifstream ifs{ fname };
	if (!ifs) throw runtime_error("unable to open file");
	ofstream ofs{ ofname };
	if (!ofs) throw runtime_error("unable to open resfile");
	for (char c{}; ifs.get(c);) {
		if (is_vowel(c))
			continue;
		ofs << c;
	}
	return;
}

//ex4:
//prompt user to enter several integers in any combo of octal decimal or hex using 0 and 0x base prefixes
//interpret the numbers correctly and convert them to decimal
//out put in properly spaced columns:
//original_val \t base_type \t "converts to" \t decimal_val \t "decimal"
enum class base_type {Error=0,dec=10,oct=8,hex=16,bin=2};
base_type get_base_type(const string& s) {
	if (s.size() < 1) return base_type::Error;
	if (s[0] == '0' && s.size() > 1) {
		//can be octa 0~, hex 0x~, or binary 0b~
		switch (s[1]) {
		case 'x':
		case 'b':
		default:
		}
	}
	//TODO
}
string base_type2str(const base_type& bt) {
	switch (bt) {
	case base_type::Error:
		throw runtime_error("cannot convert base_type::Error to string");
	case base_type::dec:
		return "Decimal";
	case base_type::oct:
		return "Octal";
	case base_type::hex:
		return "Hexadecimal";
	case base_type::bin:
		return "Binary";
	default:
		throw runtime_error("not a base_type");
	}
}
ostream& operator<<(ostream& os, const base_type& bt) {
	os << base_type2str(bt);
	return os;
}
string to_decimal(const string& s, const base_type& type);
void c9e4() {
	string s;
	//
	base_type type = get_base_type(s);
	if (type == base_type::Error)
		cout << s << " is not a valid number" << '\n';
	else
		cout << s << '\t' << type << '\t' << "converts to" << '\t' << to_decimal(s, type) << "\tin decimal\n";
	//TODO
}

//ex5:
//read strings; for each string, output the character classiication of each char
//note that a character can have several classifications. (see 9.10.3 table)

//ex6:
//replace punctuation with whitespace (.;,?-')
//don't modiy chars in a pair of double quotes though.

//ex7:
//modify ex6; make don't become do not and can't becomes cannot, etc.
//leave hyphens within words intact and convert all chars to lower

//ex8:
//modify ex7: make a sorted list of words. run the result on a multi-page text file, look at result, and see if you can improve the program to make a better list.

//ex9:
//write: vector<string> split(const string& s) that returns a vec of whitespace separated substrings from the arg s

//ex10:
//write: vector<string split(const string& s, const string& w)
//returns vec of ws-separated substrings from the argument s, where ws is defined as ordinary ws + the chars in w.

//ex11:
//reverse the order of characters in a text file.

//ex12:
//reverse the order of words (defined as ws-separated strings) in a file
//assume that al the strings from the file will fit inot memory at once

//ex13:
//read a text file and write out how many character of each char classification are in the file

//ex14:
//read a file of ws-separated numbers and outputs a file of numbers using scientific format and precision 8 in four fields of 20 char per line.

//ex15:
//read a file of ws-separated numbers and output them in order (lowest value first), one value per line.
//write a value only once, and if it occurs more than once write the count of its occurrences on its line. (example given in book)

//ex16:
//out the sum of all the numbers in a file of ws-separated integers

//ex17:
//create a file of data in the form of the temperature reading type defined in 9.3.2
//for testing, fill the file with at least 50 readings.

//ex18:
//read data from ex17 file into a vector and then calc the mean and median temps in the data set.

//ex19:
//modify ex17: to include a temp suffic (c or f) for units of temperature.
//modify ex18: to test each temp converting the celsius readings to fahrenheit before putting them into the vector.

//ex20:
//write function: print_year() mentioned in 9.9.2

//ex21:
//define a Roman_int class for holding Roman numerals (as ints)
//have a << and >> defined
//provide Roman_int with an as_int() member that returns the int value
//use: cout << "Roman " << r << " equals " << r.as_int() << '\n';

//ex22:
//make a calculator from previous chapters taht accepts Roman numerals rather than the usual arabic ones.

//ex23:
//accept two filenames and produces a new file that is the contents of the first followed by the contents of the second

//ex24:
//take two files containing sorted ws-separated words and merge them preserving order.

//ex25:
//add a command "from x" to the calculator from previous chapters that takes input from a file "x"
//add a command "to y" to this calculator that makes it write its output (both std and err) to file "y"
//write a collection of test cases based on ideas from 6.3 and use that to test the calculator

//ex26:
//print the sum of all whitespace-separated integers in a text file, ignoring non integer strings.

///Main
int main() try {
	c9e3();
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