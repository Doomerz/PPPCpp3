import std;
using namespace std;

///TryThis
namespace TT {
	//Date class
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
	c7e14();
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