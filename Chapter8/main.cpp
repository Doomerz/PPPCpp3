import std;
using namespace std;

///TryThis
namespace TT {
	//Date class
	class Date {
	public:
		int year() { return y; }
		int month() { return m; }
		int day() { return d; }
	private:
		int y;
		int m;
		int d;
	};
	ostream& operator<<(ostream& os, Date d) {
		return os << d.year() << '/' << d.month() << '/' << d.day();
	}
}
void TryThis4_4() {
	//get date so far to run
}
void TryThis6() {
	//write and compile and run a small example using ++ and << for month
}

///Drill

///Review

///Exercises

///Main
int main() try {
	TryThis4_4();
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