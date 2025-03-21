import std;
using namespace std;

///TryThis
void TryThis10_1() {
	//output your birth year in decimal, hexadecimal, and octal form. Label each value
	//line up output in columns using the tab character, output age now too.
}
void TryThis10_6() {
	//see what that last statement prints and explain it. try some other formats.
}

///Drill

///Review

///Exercises

///Main
int main() try {
	TryThis10_1();
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