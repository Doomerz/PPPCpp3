import std;
using namespace std;

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

//ex2:
//given a filename and a word; output each line that contains that word together with the line number
//hint: getline

//ex3:
//remove all vowels from a file (disemvowels)

//ex4:
//prompt user to enter several integers in any combo of octal decimal or hex using 0 and 0x base prefixes
//interpret the numbers correctly and convert them to decimal
//out put in properly spaced columns:
//original_val \t base_type \t "converts to" \t decimal_val \t "decimal"

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
//

///Main
int main() try {
	TryThis10_6();
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