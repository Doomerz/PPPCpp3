import std;
using namespace std;

///TryThis

///Drill

///Review

///Exercises

///Main
int main() try {
	placeholder();
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