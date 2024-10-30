///reading notes

//cin (see-in) is the character input stream
//uses >> (extraction operator) to get values out of cin.
//conventionally, reading of strings is terminated by whitespace
//whitespace is space (' '), newline ('\n'), and tab ('\t')
//whitespace is ignored by >>
//

//on page 2.6

import std;
using namespace std;

int TryThis3() {
	//modify name and age example to write out the age in number of months using a double.
	cout << "Please enter your first name and age\n";
	string name;
	double age;
	cin >> name >> age;
	cout << "Hello, " << name << " (age " << age * 12 << " months)\n";
	return 0;
}
int TryThis4() {
	cout << "Please enter a floating-point value: ";
	double n = 0;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< '\n';
	cout << "\nPlease enter an integer value: ";
	int x = 0;
	cin >> x;
	cout << "x == " << x
		<< "\nx+1 == " << x + 1
		<< "\nthree times x == " << 3 * x
		<< "\ntwice x == " << x + x
		<< "\nx squared == " << x * x
		<< "\nhalf of x == " << x / 2
		<< "\nsquare root of x == " << sqrt(x)
		<< "\nmodulo 2 of x == " << x%2
		<< '\n';
	return 0;
}
int TryThis5_1() {
	cout << "";
	string current, previous;
	while (cin >> current) {
		if (current == previous) cout << "repeated word: " << current << endl;
		previous = current;
	}
	return 0;
} //result from test string has "did", "very", and "good" as repeats.
//int TryThis6() {
//	STRING s = "Goodbye, cruel world! ";
//	cOut << S << '\n';
//}
//this gives errors:
//error C2065: 'STRING': undeclared identifier
//error C2146: syntax error: missing ';' before identifier 's'
//error C2065: 's': undeclared identifier
//error C2065: 'cOut': undeclared identifier
//error C2065: 'S': undeclared identifier

int main() {
	return TryThis6();
}