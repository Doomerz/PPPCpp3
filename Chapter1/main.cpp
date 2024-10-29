///reading notes

//writing text out to the console is done via this syntax: std::cout << "my string here";
//delimited = enclosed by?
//'\n' represents a new line.
//std::cout is character output stream
// use '//' for a comment (won't be read by the compiler)
//every c++ program needs a main function to tell the program where to start.
//functions are named sequences of instructions with 4 parts: return type, name, parameter list, and function body
//the return keyword ends the function
//something that specifies an action is called a statement.
//a compiler take our program that we can read (our source code) and turns it into object code/machine code.
//source code is placed in files with the .cpp extension
//object files have .obj extension (.o in linux)
//omitting "import std;" we get: error C2039: 'cout': is not a member of 'std' && error C2065: 'cout': undeclared identifier
//omitting the "std::" from "std::cout" we get: error C2065: 'cout': undeclared identifier
//omitting the last double quote of the string literal we get: error C2001: newline in constant && error C2143: syntax error: missing ';' before 'return'
//using integer instead of int we get: error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
// && error C2146: syntax error: missing ';' before identifier 'main'
// && error C2143: syntax error: missing ';' before '{'
// && error C2447: '{': missing function header (old-style formal list?)
//using < instead of << we get: error C2678: binary '<': no operator found which takes a left-hand operand of type 'std::basic_ostream<char,std::char_traits<char>>' && a slew of additional information
//using single quotes instead of double quotes we get: error C2015: too many characters in constant
//if we don't end the statement with a ; we get: error C2143: syntax error: missing ';' before 'return'
//no error if we omit the return from main. otherwise non-void functions must have a proper return statement.
//linkers link the object code from compilers into executable code
//debugging is the activity of finding errors in a program and removing them.

///Drill

//be sure to compile and run the example program.
//think of 5 mistakes you could make typing a program and see what their errors are.

///Review

///What is the purpose of the “Hello, World!” program?
// to demonstrate the most basic useful program in a language. Doing so to get acquainted with the basic tools of programming.
///Name the four parts of a function.
// return type, name, parameter list, body
///Name a function that must appear in every C++ program.
// main
///In the “Hello, World!” program, what is the purpose of the line return 0; ?
// to return a value to the caller, in this case the OS.
///What is the purpose of the compiler ?
// to convert the code we write in to object code
///What is the purpose of the import statement ?
// to import a module for adding additional functionality to a program.
///What is the purpose of the #include directive ?
// to include code from another file.
///What does a.cpp suffix at the end of a file name signify in C++ ?
// a source file.
///What does the linker do for your program ?
// convert the object files into an executable file.
///What is the difference between a source file and an object file ?
// source file is readable by programmers/humans, an object file is readable by machines.
///What is an executable ?
// a file that can be run by the operating system.
///What is an IDE and what does it do for you ?
// provides tools and features for programming that improve efficiency and quality of life.
///How do you get a compiled program to run ?
// you must first link it into an executable file and then run it like any other application.
///What is a comment ?
// a section of a source file that is ignored by the compiler and meant to be read by humans to help code readability.
///What is the purpose of a drill ?
// to establish or reinforce your practical programming skills and get experience with programming environment tools.
///If you understand everything in the textbook, why is it necessary to practice ?
// like any high level practical skill it takes regular practice to improve or maintain.

///Exercises

//Exercise 1
import std;

int main() {
	std::cout << "Hello, World\nHere we go!";
	return 0;
}

//ex2 is a personal exercise
//ex3 likewise
//ex4 much the same

//exercise 5; define terms

// '//'
	//a line comment
// executable
	//something that the OS can run
// main()
	//the start point of a C++ program
// <<
	//the insertion operator (see std::cout use)
// function
	//a sequence of ordered statements for completing a task
// object code
	//compiled source code that a computer can read.
// C++
	//an awesome programming language.
// header file
	//a file that can be included in another file to utilize the functionality programmed within the header file.
// output
	//something you get out of something.
// comment
	//notes ignored by the compiler
// IDE
	//Integrated Development environment used for tools and features to improve the programming experience.
// program
	//a compilation of source code that does something.
// compiler
	//a program that converts source code into object code
// import
	//imports a module's functionality into a source file so we can use their features. Kind of an improved include.
// source code
	//human readable code
// compile-time
	//a point in time during the conversion between source code and object code.
// error
	//when something is wrong
// library
	//a resource of functions and classes that is shared for others to use.
// statement
	//code ended by ';' denoting a single action.
// cout
	//c-out for std output stream.
// linker
	//program that combines object files into an executable file.
// module
	//a collection of classes and tools within a single logical space.
// #include
	//a directive to include source from another file.
// std
	//the standard library namespace
// command line
	//cmd.exe or a terminal in other OSs
// bug
	//an error with a program
// debugging
	//searching for and eliminating errors.